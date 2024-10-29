#include <Windows.h>
#pragma once

namespace SurgicalRobotInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

			// Attach the mouse event handlers
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseUp);

			/*this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);*/
		}
	public: System::Windows::Forms::Button^ buttonConnect;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBoxPorts;
	private: System::Windows::Forms::ComboBox^ comboBoxBaudrate;


	public: System::Windows::Forms::Button^ buttonRefresh;
	private: System::IO::Ports::SerialPort^ serialPort;


	public:
	private:

	public:

	public:
		bool startApp;
		bool connected;
		String^ positionData;

	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Panel^ panel2;
	public: System::Windows::Forms::Button^ buttonHoming;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;


	private: System::Windows::Forms::Button^ buttonClose;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::RadioButton^ radioButtonJoystick;
	private: System::Windows::Forms::RadioButton^ radioButtonHaptic;
	private: System::Windows::Forms::Button^ buttonMenuControl;
	private: System::Windows::Forms::Button^ buttonMenuConnect;


	public:

	public:
	private:

	private:
	public:
		bool deviceConnected = false;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ buttonStart;
	public: System::Windows::Forms::Button^ buttonConnectDevice;



	protected:




	public: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;
	public:
	private:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonConnectDevice = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxPorts = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxBaudrate = (gcnew System::Windows::Forms::ComboBox());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->buttonHoming = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonHaptic = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonJoystick = (gcnew System::Windows::Forms::RadioButton());
			this->buttonMenuConnect = (gcnew System::Windows::Forms::Button());
			this->buttonMenuControl = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Gainsboro;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(81, 312);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// buttonStart
			// 
			this->buttonStart->BackColor = System::Drawing::Color::Transparent;
			this->buttonStart->Enabled = false;
			this->buttonStart->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonStart->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStart->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonStart->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonStart->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonStart->Location = System::Drawing::Point(48, 358);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(144, 40);
			this->buttonStart->TabIndex = 1;
			this->buttonStart->Text = L"START";
			this->buttonStart->UseVisualStyleBackColor = false;
			this->buttonStart->Click += gcnew System::EventHandler(this, &MainForm::buttonStart_Click);
			// 
			// buttonConnectDevice
			// 
			this->buttonConnectDevice->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonConnectDevice->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonConnectDevice->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonConnectDevice->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonConnectDevice->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonConnectDevice->ForeColor = System::Drawing::Color::Transparent;
			this->buttonConnectDevice->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonConnectDevice->Location = System::Drawing::Point(596, 148);
			this->buttonConnectDevice->Name = L"buttonConnectDevice";
			this->buttonConnectDevice->Size = System::Drawing::Size(173, 40);
			this->buttonConnectDevice->TabIndex = 2;
			this->buttonConnectDevice->Text = L"CONNECT DEVICE";
			this->buttonConnectDevice->UseVisualStyleBackColor = true;
			this->buttonConnectDevice->Click += gcnew System::EventHandler(this, &MainForm::buttonConnectHaptic_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Gainsboro;
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(174, 312);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// buttonConnect
			// 
			this->buttonConnect->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonConnect->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonConnect->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonConnect->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonConnect->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonConnect->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonConnect->Location = System::Drawing::Point(48, 148);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(173, 40);
			this->buttonConnect->TabIndex = 4;
			this->buttonConnect->Text = L"CONNECT ROBOT";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &MainForm::buttonConnect_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold));
			this->label3->ForeColor = System::Drawing::Color::Gainsboro;
			this->label3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label3->Location = System::Drawing::Point(45, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Serial Port";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::Color::Gainsboro;
			this->label4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label4->Location = System::Drawing::Point(45, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(59, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Baud Rate";
			// 
			// comboBoxPorts
			// 
			this->comboBoxPorts->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold));
			this->comboBoxPorts->ForeColor = System::Drawing::Color::Black;
			this->comboBoxPorts->FormattingEnabled = true;
			this->comboBoxPorts->Location = System::Drawing::Point(127, 55);
			this->comboBoxPorts->Name = L"comboBoxPorts";
			this->comboBoxPorts->Size = System::Drawing::Size(121, 21);
			this->comboBoxPorts->TabIndex = 8;
			// 
			// comboBoxBaudrate
			// 
			this->comboBoxBaudrate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold));
			this->comboBoxBaudrate->ForeColor = System::Drawing::Color::Black;
			this->comboBoxBaudrate->FormattingEnabled = true;
			this->comboBoxBaudrate->Location = System::Drawing::Point(127, 85);
			this->comboBoxBaudrate->Name = L"comboBoxBaudrate";
			this->comboBoxBaudrate->Size = System::Drawing::Size(121, 21);
			this->comboBoxBaudrate->TabIndex = 9;
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonRefresh->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonRefresh->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold));
			this->buttonRefresh->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonRefresh->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonRefresh->Location = System::Drawing::Point(265, 55);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(75, 23);
			this->buttonRefresh->TabIndex = 10;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = true;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &MainForm::buttonRefresh_Click);
			// 
			// serialPort
			// 
			this->serialPort->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MainForm::serialPort_DataReceived);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Gainsboro;
			this->label5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label5->Location = System::Drawing::Point(267, 312);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"label5";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->buttonMenuControl);
			this->panel2->Controls->Add(this->buttonMenuConnect);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(1, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(0, 120, 0, 0);
			this->panel2->Size = System::Drawing::Size(165, 635);
			this->panel2->TabIndex = 13;
			// 
			// buttonClose
			// 
			this->buttonClose->BackColor = System::Drawing::Color::Transparent;
			this->buttonClose->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonClose->Dock = System::Windows::Forms::DockStyle::Right;
			this->buttonClose->FlatAppearance->BorderSize = 0;
			this->buttonClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonClose->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->buttonClose->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonClose->Location = System::Drawing::Point(963, 0);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(47, 31);
			this->buttonClose->TabIndex = 5;
			this->buttonClose->Text = L"X";
			this->buttonClose->UseVisualStyleBackColor = false;
			this->buttonClose->Click += gcnew System::EventHandler(this, &MainForm::buttonClose_Click);
			// 
			// buttonHoming
			// 
			this->buttonHoming->BackColor = System::Drawing::Color::Transparent;
			this->buttonHoming->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonHoming->Enabled = false;
			this->buttonHoming->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonHoming->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonHoming->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonHoming->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonHoming->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonHoming->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonHoming->Location = System::Drawing::Point(230, 358);
			this->buttonHoming->Name = L"buttonHoming";
			this->buttonHoming->Size = System::Drawing::Size(144, 40);
			this->buttonHoming->TabIndex = 14;
			this->buttonHoming->Text = L"HOME MOTORS";
			this->buttonHoming->UseVisualStyleBackColor = false;
			this->buttonHoming->Click += gcnew System::EventHandler(this, &MainForm::buttonHoming_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->buttonClose);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(166, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1012, 33);
			this->panel1->TabIndex = 15;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->radioButtonJoystick);
			this->panel3->Controls->Add(this->radioButtonHaptic);
			this->panel3->Controls->Add(this->buttonConnectDevice);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->buttonStart);
			this->panel3->Controls->Add(this->buttonHoming);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->buttonConnect);
			this->panel3->Controls->Add(this->buttonRefresh);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->comboBoxBaudrate);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->comboBoxPorts);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(166, 34);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1012, 602);
			this->panel3->TabIndex = 16;
			this->panel3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseDown);
			this->panel3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseMove);
			this->panel3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseUp);
			// 
			// radioButtonHaptic
			// 
			this->radioButtonHaptic->AutoSize = true;
			this->radioButtonHaptic->Checked = true;
			this->radioButtonHaptic->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButtonHaptic->ForeColor = System::Drawing::Color::Gainsboro;
			this->radioButtonHaptic->Location = System::Drawing::Point(596, 75);
			this->radioButtonHaptic->Name = L"radioButtonHaptic";
			this->radioButtonHaptic->Size = System::Drawing::Size(99, 19);
			this->radioButtonHaptic->TabIndex = 15;
			this->radioButtonHaptic->TabStop = true;
			this->radioButtonHaptic->Text = L"Haptic Device";
			this->radioButtonHaptic->UseVisualStyleBackColor = true;
			// 
			// radioButtonJoystick
			// 
			this->radioButtonJoystick->AutoSize = true;
			this->radioButtonJoystick->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButtonJoystick->ForeColor = System::Drawing::Color::Gainsboro;
			this->radioButtonJoystick->Location = System::Drawing::Point(596, 100);
			this->radioButtonJoystick->Name = L"radioButtonJoystick";
			this->radioButtonJoystick->Size = System::Drawing::Size(67, 19);
			this->radioButtonJoystick->TabIndex = 16;
			this->radioButtonJoystick->Text = L"Joystick";
			this->radioButtonJoystick->UseVisualStyleBackColor = true;
			// 
			// buttonMenuConnect
			// 
			this->buttonMenuConnect->BackColor = System::Drawing::Color::Transparent;
			this->buttonMenuConnect->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonMenuConnect->FlatAppearance->BorderSize = 0;
			this->buttonMenuConnect->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(106)));
			this->buttonMenuConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMenuConnect->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold));
			this->buttonMenuConnect->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonMenuConnect->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonMenuConnect->Location = System::Drawing::Point(0, 120);
			this->buttonMenuConnect->Name = L"buttonMenuConnect";
			this->buttonMenuConnect->Size = System::Drawing::Size(163, 65);
			this->buttonMenuConnect->TabIndex = 0;
			this->buttonMenuConnect->Text = L"CONNECT";
			this->buttonMenuConnect->UseVisualStyleBackColor = false;
			// 
			// buttonMenuControl
			// 
			this->buttonMenuControl->BackColor = System::Drawing::Color::Transparent;
			this->buttonMenuControl->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonMenuControl->FlatAppearance->BorderSize = 0;
			this->buttonMenuControl->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(106)));
			this->buttonMenuControl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMenuControl->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold));
			this->buttonMenuControl->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonMenuControl->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonMenuControl->Location = System::Drawing::Point(0, 185);
			this->buttonMenuControl->Name = L"buttonMenuControl";
			this->buttonMenuControl->Size = System::Drawing::Size(163, 65);
			this->buttonMenuControl->TabIndex = 15;
			this->buttonMenuControl->Text = L"CONTROL";
			this->buttonMenuControl->UseVisualStyleBackColor = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateBlue;
			this->ClientSize = System::Drawing::Size(1179, 637);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->Padding = System::Windows::Forms::Padding(1);
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
		System::Void buttonConnect_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonConnectHaptic_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e);
		System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonHoming_Click(System::Object^ sender, System::EventArgs^ e);

		void haptic_main();
		void robot_main();
		void _connect_serial();
		void _disconnect_serial();
		void _connect_device();
		void _disconnect_device();
		void set_label2(String^ data);
		void set_label5(String^ data);
		void serial_write(String^ data);

		System::Threading::Thread^ hapticThread;
		System::Threading::Thread^ robotThread;

		//FORM DRAGGING
		private:
			bool dragging;
			System::Drawing::Point dragCursorPoint;
			System::Drawing::Point dragFormPoint;

		private: System::Void panel3_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = true;
			dragCursorPoint = Cursor->Position;
			dragFormPoint = this->Location;
		}
		private: System::Void panel3_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (dragging) {
				System::Drawing::Point diff = System::Drawing::Point(Cursor->Position.X - dragCursorPoint.X,
					Cursor->Position.Y - dragCursorPoint.Y);
				this->Location = System::Drawing::Point(dragFormPoint.X + diff.X, dragFormPoint.Y + diff.Y);
			}
		}
		private: System::Void panel3_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = false;
		}

		////FORM RESIZING
		//private:
		//	const int resizeMargin = 10; // Thickness of the resize area
		//	bool resizing;
		//	System::Drawing::Point resizeCursorPoint;
		//	System::Drawing::Size originalFormSize;
		//	enum class ResizeDirection { None, Right, Bottom, BottomRight };
		//	ResizeDirection resizeDir;

		//private: ResizeDirection GetResizeDirection(System::Windows::Forms::MouseEventArgs^ e) {
		//	if (e->X >= this->Width - resizeMargin && e->Y >= this->Height - resizeMargin) return ResizeDirection::BottomRight;
		//	if (e->X >= this->Width - resizeMargin) return ResizeDirection::Right;
		//	if (e->Y >= this->Height - resizeMargin) return ResizeDirection::Bottom;
		//	return ResizeDirection::None;
		//}

		//private: System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//	if (resizeDir != ResizeDirection::None) {
		//		resizing = true;
		//		resizeCursorPoint = Cursor->Position;
		//		originalFormSize = this->Size;
		//	}
		//}
		//private: System::Void MainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//	resizing = false;
		//}
		//private: System::Void MainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//	if (resizing) {
		//		int deltaX = Cursor->Position.X - resizeCursorPoint.X;
		//		int deltaY = Cursor->Position.Y - resizeCursorPoint.Y;

		//		// Resize form based on the direction
		//		if (resizeDir == ResizeDirection::Right || resizeDir == ResizeDirection::BottomRight)
		//			this->Width = originalFormSize.Width + deltaX;
		//		if (resizeDir == ResizeDirection::Bottom || resizeDir == ResizeDirection::BottomRight)
		//			this->Height = originalFormSize.Height + deltaY;
		//	}
		//	else {
		//		// Change cursor based on position if not resizing
		//		resizeDir = GetResizeDirection(e);
		//		switch (resizeDir) {
		//		case ResizeDirection::Right: this->Cursor = System::Windows::Forms::Cursors::SizeWE; break;
		//		case ResizeDirection::Bottom: this->Cursor = System::Windows::Forms::Cursors::SizeNS; break;
		//		case ResizeDirection::BottomRight: this->Cursor = System::Windows::Forms::Cursors::SizeNWSE; break;
		//		default: this->Cursor = System::Windows::Forms::Cursors::Default; break;
		//		}
		//	}
		//}
};
}
