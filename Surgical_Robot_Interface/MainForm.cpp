#include "MainForm.h"
#include "drdc.h"
#include <iostream>
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace SurgicalRobotInterface;

void MainForm::robot_main() {
	while (deviceConnected && startApp) {
		serialPort->Write(positionData);
		System::Threading::Thread::Sleep(10);
	}
}

void MainForm::haptic_main() {
	// Initialize the haptic device
	dhdEnableExpertMode();
	if (dhdOpen() < 0) {
		// Handle error
		MessageBox::Show("Error. Could not connect to the device.");
		return;
	}

	dhdEnableForce(DHD_ON);

	while (deviceConnected) {
		// Get the position of the end effector
		double px, py, pz, pg;
		double vx, vy, vz;

		dhdGetPosition(&px, &py, &pz);
		dhdGetGripperAngleDeg(&pg);
		dhdGetLinearVelocity(&vx, &vy, &vz);

		// Format the position data as a string
		positionData = String::Format("X: {0}, Y: {1}, Z: {2}, G: {3}", (px*1000), (py*1000), (pz*1000), (pg));

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

		String^ forceData = "Fx: " + fx + "Fy: " + fy + "Fz: " + fz;

		dhdSetForceAndGripperForce(fx, fy, fz, fg);

		//WRITE POSITION ON SERIAL
		//this->Invoke(gcnew Action<String^>(this, &MainForm::serial_write), positionData);
		//serialPort->WriteLine(positionData);

		//PRINT POSITION AND FORCE
		this->Invoke(gcnew Action<String^>(this, &MainForm::set_label2), positionData);
		this->Invoke(gcnew Action<String^>(this, &MainForm::set_label5), forceData);

		System::Threading::Thread::Sleep(10);
	}

	// Close the serial port
	//serialPort->Close();

	// Close the haptic device
	dhdClose();
}

void MainForm::serial_write(String^ data) {
	serialPort->WriteLine(data);
}

void MainForm::set_label2(String^ data) {
	label2->Text = data;
}

void MainForm::set_label5(String^ data) {
	label5->Text = data;
}

void MainForm::buttonStart_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!startApp) {
		this->startApp = true;
		serialPort->WriteLine("START");
		buttonStart->Text = "STOP";
		robotThread = gcnew System::Threading::Thread(gcnew ThreadStart(this, &MainForm::robot_main));
		robotThread->Start();
	}
	else {
		this->startApp = false;
		serialPort->WriteLine("STOP");
		buttonStart->Text = "START";
		robotThread->Join();
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

			serialPort->WriteLine("conn");
		}
		else if (connected) {
			serialPort->WriteLine("disc");
		}
	}
	catch (...) {
		MessageBox::Show("Error encountered while trying to connect to the device!");
	}
}

void MainForm::buttonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show(
		"Are you sure that you would like to exit?",
		"Form Closing", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) Application::Exit();
}

void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	deviceConnected = false;
	if (serialPort->IsOpen) {
		serialPort->Close();
	}
	this->startApp = false;
}

void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	connected = false;
	deviceConnected = false;
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

void MainForm::buttonConnectHaptic_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!deviceConnected) {
		hapticThread = gcnew System::Threading::Thread(gcnew ThreadStart(this, &MainForm::haptic_main));
		this->Invoke(gcnew Action(this, &MainForm::_connect_device));
		hapticThread->Start();
	}
	else if (deviceConnected && hapticThread != nullptr && hapticThread->IsAlive) {
		this->Invoke(gcnew Action(this, &MainForm::_disconnect_device));
		hapticThread->Join();
	}
}

void MainForm::serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
	String^ incomingData = serialPort->ReadLine();
	if (incomingData->Trim() == "ackc") {
		this->Invoke(gcnew Action(this, &MainForm::_connect_serial));
	}
	else if (incomingData->Trim() == "ackd") {
		this->Invoke(gcnew Action(this, &MainForm::_disconnect_serial));
		serialPort->Close();
	}
}

void MainForm::buttonHoming_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ incomingData = serialPort->ReadLine();
}

void MainForm::_connect_serial() {
	buttonConnect->Text = "DISCONNECT";
	buttonStart->Enabled = true;
	connected = true;
}

void MainForm::_disconnect_serial() {
	buttonConnect->Text = "CONNECT";
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

void main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SurgicalRobotInterface::MainForm mainForm;

    Application::Run(% mainForm);
}