#include "MainForm.h"
#include "StreamForm.h"

using namespace SurgicalRobotInterface;
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace cv;

LPDIRECTINPUT8          g_pDI		= nullptr;	// DirectInput interface
LPDIRECTINPUTDEVICE8    g_pJoystick = nullptr;	// Joystick device

// Joystick state structure
struct JoystickState {
	LONG lX, lY, lZ;
	std::vector<bool> buttons;
};

bool InitDirectInput(HWND hwnd) {
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pDI, NULL))) {
		
		return false;
	}
	g_pDI->EnumDevices(DI8DEVCLASS_GAMECTRL, [](LPCDIDEVICEINSTANCE dii, LPVOID) -> BOOL {
		g_pDI->CreateDevice(dii->guidInstance, &g_pJoystick, NULL);
		return DIENUM_STOP;
		}, NULL, DIEDFL_ATTACHEDONLY);
	if (g_pJoystick) {
		g_pJoystick->SetDataFormat(&c_dfDIJoystick);
		g_pJoystick->SetCooperativeLevel(hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
		g_pJoystick->Acquire();
	}
	else {
		MessageBox::Show("Error. Could not connect to the device.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return false;
	}
	return true;
}

JoystickState ReadJoystickState() {
	DIJOYSTATE js;
	g_pJoystick->Poll();
	if (FAILED(g_pJoystick->GetDeviceState(sizeof(DIJOYSTATE), &js))) {
		g_pJoystick->Acquire();
		g_pJoystick->Poll();
		g_pJoystick->GetDeviceState(sizeof(DIJOYSTATE), &js);
	}
	JoystickState state = { js.lX, js.lY, js.lZ, std::vector<bool>(js.rgbButtons, js.rgbButtons + 32) };
	return state;
}

void ReleaseJoystick() {
	if (g_pJoystick) {
		g_pJoystick->Unacquire();
		g_pJoystick->Release();
		g_pJoystick = NULL;
	}
}

void main(array<System::String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SurgicalRobotInterface::MainForm mainForm;

	Application::Run(% mainForm);
}

void MainForm::robot_main() {
	while (deviceConnected && startApp) {
		//INSERT IK COMPUTATION HERE
		command = System::String::Format("{0}/{1}/{2}/{3}/", "ST", joyX, joyY, joyZ);
		serial_write(command);
		System::Threading::Thread::Sleep(10);
	}
	serial_write("SO");
}

void MainForm::ctrl_device_main() {
	if (radioButtonHaptic->Checked) {
		// Initialize the haptic device
		dhdEnableExpertMode();
		if (dhdOpen() < 0) {
			MessageBox::Show("Could not connect to the device.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		dhdEnableForce(DHD_ON);

		this->Invoke(gcnew Action(this, &MainForm::_connect_device));

		while (deviceConnected) {
			// Get the position of the end effector
			double px, py, pz, pg;
			double vx, vy, vz;

			dhdGetPosition(&px, &py, &pz);
			dhdGetGripperAngleDeg(&pg);
			dhdGetLinearVelocity(&vx, &vy, &vz);

			// Format the position data as a string
			//positionData = System::String::Format("X: {0}, Y: {1}, Z: {2}, G: {3}", (px * 1000), (py * 1000), (pz * 1000), (pg));

			//SET FORCE FIELD AND DAMPING TO CENTER HAPTIC EEF
			double desiredX = 0.0, desiredY = 0.0, desiredZ = 0.0;
			const double Kp = 30, Kv = 3; //max 8 damping
			double xDamping = 0.0, yDamping = 0.0, zDamping = 0.0;
			double fx = 0.0, fy = 0.0, fz = 0.0, fg = 1.0;

			xDamping = -Kv * vx;
			yDamping = -Kv * vy;
			zDamping = -Kv * vz;

			fx = ((desiredX - px) * Kp) + xDamping;
			fy = ((desiredY - py) * Kp) + yDamping;
			fz = ((desiredZ - pz) * Kp) + zDamping;

			//System::String^ forceData = "Fx: " + fx + "Fy: " + fy + "Fz: " + fz;

			dhdSetForceAndGripperForce(fx, fy, fz, fg);

			//PRINT POSITION AND FORCE
			//this->Invoke(gcnew Action<System::String^>(this, &MainForm::set_label2), positionData);
			//this->Invoke(gcnew Action<System::String^>(this, &MainForm::set_label5), forceData);

			System::Threading::Thread::Sleep(10);
		}
	}
	else if (radioButtonJoystick->Checked) {
		this->Invoke(gcnew Action(this, &MainForm::_connect_device));
		while (deviceConnected) {
			if (!g_pJoystick) return;
			JoystickState state = ReadJoystickState();
			joyX = (state.lX - 32767) * 0.5;
			joyY = (state.lY - 32767) * 0.5;
			joyZ = (state.lZ - 32767) * 0.5;
			System::String^ positionData = "X: " + joyX + "Y: " + joyY + "Z: " + joyZ;
			this->Invoke(gcnew Action<System::String^>(this, &MainForm::set_label2), positionData);
		}
	}
}

void MainForm::serial_write(System::String^ data) {
	try {
		serialPort->WriteLine(data);
	}
	catch(...){
		this->Invoke(gcnew UpdateErrorLabelDelegate(this, &MainForm::update_error_label), 
		"Unable establish communication with robot. Please check connection.", true);
	}
}

void MainForm::update_error_label(System::String^ data, bool visible) {
	labelError->Text = data;
	labelError->Visible = visible;
}

void MainForm::set_buttons_state(bool setstate) {
	buttonConnect->Enabled = setstate;
	buttonConnectDevice->Enabled = setstate;
}

void MainForm::buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!startApp && deviceConnected && connected) {
		this->startApp = true;
		serial_write("ST");
		buttonStart->Text = "STOP";
		robotThread = gcnew System::Threading::Thread(gcnew ThreadStart(this, &MainForm::robot_main));
		robotThread->Start();
		set_buttons_state(false);
	}
	else {
		this->startApp = false;
		serial_write("SO");
		buttonStart->Text = "START";
		robotThread->Join();
		set_buttons_state(true);
	}
}

void MainForm::buttonConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		if (!connected) {
			if (serialPort->IsOpen) {
				serialPort->Close();
			}
			serialPort->PortName = comboBoxPorts->Text;
			serialPort->BaudRate = Int32::Parse(comboBoxBaudrate->Text);
			serialPort->Open();

			serial_write("conn");
		}
		else if (connected) {
			serial_write("disc");
		}
	}
	catch (...) {
		MessageBox::Show("Error encountered while trying to connect to the device!");//change with error label
	}
}

void MainForm::buttonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show(
		"Are you sure that you would like to exit?",
		"Exit", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) Application::Exit();
}

void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	deviceConnected = false;
	if (connected) {
		serial_write("SO");
		Sleep(50);
		serial_write("disc");
	}
	if (serialPort->IsOpen) serialPort->Close();
}

void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	connected = false;
	deviceConnected = false;
	streaming = false;
	positionData = "";

	array<Object^>^ com_ports = SerialPort::GetPortNames();
	comboBoxPorts->Items->AddRange(com_ports);
	comboBoxPorts->SelectedIndex = 0;

	array<Object^>^ baudrates = { 9600, 57000, 115200 };
	comboBoxBaudrate->Items->AddRange(baudrates);
	comboBoxBaudrate->SelectedIndex = 0;
}

void MainForm::buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
	array<Object^>^ com_ports = SerialPort::GetPortNames();
	comboBoxPorts->Items->Clear();
	comboBoxPorts->Items->AddRange(com_ports);
	comboBoxPorts->SelectedIndex = 0;
}

void MainForm::set_device_selectbox(bool setstate) {
	radioButtonHaptic->Enabled = setstate;
	radioButtonJoystick->Enabled = setstate;
}

void MainForm::buttonConnectDevice_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radioButtonHaptic->Checked) {
		if (!deviceConnected) {
			ctrlDeviceThread = gcnew System::Threading::Thread(gcnew ThreadStart(this, &MainForm::ctrl_device_main));
			ctrlDeviceThread->Start();
			set_device_selectbox(false);
			if (connected) buttonStart->Enabled = true;
		}
		else if (deviceConnected && ctrlDeviceThread != nullptr && ctrlDeviceThread->IsAlive) {
			ctrlDeviceThread->Join();
			this->Invoke(gcnew Action(this, &MainForm::_disconnect_device));
			dhdClose(); // Close the haptic device
			set_device_selectbox(true);
		}
	}
	else if (radioButtonJoystick->Checked) {
		if (!deviceConnected) {
			if (InitDirectInput((HWND)this->Handle.ToPointer())) {
				ctrlDeviceThread = gcnew System::Threading::Thread(gcnew ThreadStart(this, &MainForm::ctrl_device_main));
				ctrlDeviceThread->Start();
				set_device_selectbox(false);
				if (connected) buttonStart->Enabled = true;
			}
		}
		else if (deviceConnected && ctrlDeviceThread != nullptr && ctrlDeviceThread->IsAlive) {
			this->Invoke(gcnew Action(this, &MainForm::_disconnect_device));
			ctrlDeviceThread->Join();
			ReleaseJoystick();
			set_device_selectbox(true);
		}
	}
}

void MainForm::serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
	System::String^ incomingData = serialPort->ReadLine();
	if (incomingData->Trim() == "ackc") {
		this->Invoke(gcnew Action(this, &MainForm::_connect_serial));
	}
	else if (incomingData->Trim() == "ackd") {
		this->Invoke(gcnew Action(this, &MainForm::_disconnect_serial));
		serialPort->Close();
	}
}

void MainForm::buttonHoming_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ incomingData = serialPort->ReadLine();
}

void MainForm::_connect_serial() {
	buttonConnect->Text = "DISCONNECT ROBOT";
	buttonStart->Enabled = true;
	connected = true;
}

void MainForm::_disconnect_serial() {
	buttonConnect->Text = "CONNECT ROBOT";
	buttonStart->Enabled = false;
	connected = false;
}

void MainForm::_connect_device() {
	buttonConnectDevice->Text = "DISCONNECT DEVICE";
	deviceConnected = true;
}

void MainForm::_disconnect_device() {
	buttonConnectDevice->Text = "CONNECT DEVICE";
	deviceConnected = false;
}

void MainForm::buttonCameraFeed_Click(System::Object^ sender, System::EventArgs^ e) {
	StreamForm^ streamForm;
	if (!streaming) {
		streaming = true;
		streamForm = gcnew StreamForm();
		streamForm->Show();
		buttonCameraFeed->Text = "STOP VIDEO STREAM";
	}
	else {
		streaming = false;
		if (streamForm != nullptr) streamForm->Close();
		buttonCameraFeed->Text = "START VIDEO STREAM";
	}
}

void MainForm::buttonVoiceCommand_Click(System::Object^ sender, System::EventArgs^ e) {
	update_error_label("Voice control not yet implemented.", true);
}

void MainForm::buttonUp_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonUpPressed = true;
	timerIncrementer->Start();
}

void MainForm::buttonUp_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonUpPressed = false;
	timerIncrementer->Stop();
}

void MainForm::buttonDown_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonDownPressed = true;
	timerIncrementer->Start();
}

void MainForm::buttonDown_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonDownPressed = false;
	timerIncrementer->Stop();
}

void MainForm::buttonLeft_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonLeftPressed = true;
	timerIncrementer->Start();
}

void MainForm::buttonLeft_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonLeftPressed = false;
	timerIncrementer->Stop();
}

void MainForm::buttonRight_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonRightPressed = true;
	timerIncrementer->Start();
}

void MainForm::buttonRight_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	buttonRightPressed = false;
	timerIncrementer->Stop();
}

void MainForm::buttonMenuConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	panelConnect->Visible = true;
	timerIncrementer->Start();
}

void MainForm::buttonMenuControl_Click(System::Object^ sender, System::EventArgs^ e) {
	panelConnect->Visible = false;
	timerIncrementer->Stop();
}

void MainForm::timerIncrementer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (buttonUpPressed) {
		test += (int)motionScaleBox->Value;
		label2->Text = test.ToString();
	}
	if (buttonDownPressed) {
		test -= (int)motionScaleBox->Value;
		label2->Text = test.ToString();
	}
	if (buttonLeftPressed) {
		test += (int)motionScaleBox->Value;
		label2->Text = test.ToString();
	}
	if (buttonRightPressed) {
		test -= (int)motionScaleBox->Value;
		label2->Text = test.ToString();
	}
}

void MainForm::buttonMaximize_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == System::Windows::Forms::FormWindowState::Normal) {
		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
	}
	else {
		this->WindowState = System::Windows::Forms::FormWindowState::Normal;
	}
}

void MainForm::buttonMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
}





//-------DELETE---------
void MainForm::set_label2(System::String^ data) {
	label2->Text = data;
}

void MainForm::set_label5(System::String^ data) {
	label5->Text = data;
}
//-------DELETE---------
