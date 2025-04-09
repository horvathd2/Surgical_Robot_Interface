#include <Windows.h>
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <dinput.h>
#include "drdc.h"
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
	private: System::Windows::Forms::Panel^ panelConnect;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ labelError;
	private: System::Windows::Forms::Button^ buttonMinimize;
	private: System::Windows::Forms::Button^ buttonMaximize;



	private: System::Windows::Forms::Panel^ panelControl;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	public: System::Windows::Forms::Button^ buttonCameraFeed;
	private:
	private: System::Windows::Forms::Panel^ panel8;
	public: System::Windows::Forms::Button^ buttonVoiceCommand;
	private:

	private:
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public: System::Windows::Forms::Button^ buttonLeft;
	private:

	public: System::Windows::Forms::Button^ buttonDown;
	public: System::Windows::Forms::Button^ buttonRight;
	private:


	public: System::Windows::Forms::Button^ buttonUp;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ motionScaleBox;
	private: System::Windows::Forms::Timer^ timerIncrementer;

	public:



	public:
	public:
	public:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonMenuControl = (gcnew System::Windows::Forms::Button());
			this->buttonMenuConnect = (gcnew System::Windows::Forms::Button());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->buttonHoming = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonMinimize = (gcnew System::Windows::Forms::Button());
			this->buttonMaximize = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panelConnect = (gcnew System::Windows::Forms::Panel());
			this->radioButtonJoystick = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonHaptic = (gcnew System::Windows::Forms::RadioButton());
			this->panelControl = (gcnew System::Windows::Forms::Panel());
			this->motionScaleBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->buttonLeft = (gcnew System::Windows::Forms::Button());
			this->buttonDown = (gcnew System::Windows::Forms::Button());
			this->buttonRight = (gcnew System::Windows::Forms::Button());
			this->buttonUp = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->buttonVoiceCommand = (gcnew System::Windows::Forms::Button());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->buttonCameraFeed = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->timerIncrementer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panelConnect->SuspendLayout();
			this->panelControl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->motionScaleBox))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Gainsboro;
			this->label1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label1->Location = System::Drawing::Point(1002, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// buttonStart
			// 
			this->buttonStart->BackColor = System::Drawing::Color::Transparent;
			this->buttonStart->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonStart->Enabled = false;
			this->buttonStart->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonStart->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonStart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStart->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonStart->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonStart->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonStart->Location = System::Drawing::Point(40, 0);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(144, 45);
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
			this->buttonConnectDevice->Location = System::Drawing::Point(385, 122);
			this->buttonConnectDevice->Name = L"buttonConnectDevice";
			this->buttonConnectDevice->Size = System::Drawing::Size(188, 40);
			this->buttonConnectDevice->TabIndex = 2;
			this->buttonConnectDevice->Text = L"CONNECT DEVICE";
			this->buttonConnectDevice->UseVisualStyleBackColor = true;
			this->buttonConnectDevice->Click += gcnew System::EventHandler(this, &MainForm::buttonConnectDevice_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Gainsboro;
			this->label2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label2->Location = System::Drawing::Point(626, 16);
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
			this->buttonConnect->Location = System::Drawing::Point(46, 122);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(183, 40);
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
			this->label3->Location = System::Drawing::Point(43, 51);
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
			this->label4->Location = System::Drawing::Point(43, 79);
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
			this->comboBoxPorts->Location = System::Drawing::Point(108, 45);
			this->comboBoxPorts->Name = L"comboBoxPorts";
			this->comboBoxPorts->Size = System::Drawing::Size(121, 21);
			this->comboBoxPorts->TabIndex = 8;
			// 
			// comboBoxBaudrate
			// 
			this->comboBoxBaudrate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8.25F, System::Drawing::FontStyle::Bold));
			this->comboBoxBaudrate->ForeColor = System::Drawing::Color::Black;
			this->comboBoxBaudrate->FormattingEnabled = true;
			this->comboBoxBaudrate->Location = System::Drawing::Point(108, 76);
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
			this->buttonRefresh->Location = System::Drawing::Point(246, 43);
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
			this->label5->Location = System::Drawing::Point(899, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"label5";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->buttonMenuControl);
			this->panel2->Controls->Add(this->buttonMenuConnect);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(1, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(0, 250, 0, 20);
			this->panel2->Size = System::Drawing::Size(165, 711);
			this->panel2->TabIndex = 13;
			this->panel2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel2_MouseDown);
			this->panel2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel2_MouseMove);
			this->panel2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel2_MouseUp);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 549);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(163, 140);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 16;
			this->pictureBox1->TabStop = false;
			// 
			// buttonMenuControl
			// 
			this->buttonMenuControl->BackColor = System::Drawing::Color::Transparent;
			this->buttonMenuControl->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonMenuControl->FlatAppearance->BorderSize = 0;
			this->buttonMenuControl->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(106)));
			this->buttonMenuControl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMenuControl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonMenuControl->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonMenuControl->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonMenuControl->Location = System::Drawing::Point(0, 315);
			this->buttonMenuControl->Name = L"buttonMenuControl";
			this->buttonMenuControl->Size = System::Drawing::Size(163, 65);
			this->buttonMenuControl->TabIndex = 15;
			this->buttonMenuControl->Text = L"CONTROL";
			this->buttonMenuControl->UseVisualStyleBackColor = false;
			this->buttonMenuControl->Click += gcnew System::EventHandler(this, &MainForm::buttonMenuControl_Click);
			// 
			// buttonMenuConnect
			// 
			this->buttonMenuConnect->BackColor = System::Drawing::Color::Transparent;
			this->buttonMenuConnect->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonMenuConnect->FlatAppearance->BorderSize = 0;
			this->buttonMenuConnect->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(106)));
			this->buttonMenuConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMenuConnect->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonMenuConnect->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonMenuConnect->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonMenuConnect->Location = System::Drawing::Point(0, 250);
			this->buttonMenuConnect->Name = L"buttonMenuConnect";
			this->buttonMenuConnect->Size = System::Drawing::Size(163, 65);
			this->buttonMenuConnect->TabIndex = 0;
			this->buttonMenuConnect->Text = L"CONNECT";
			this->buttonMenuConnect->UseVisualStyleBackColor = false;
			this->buttonMenuConnect->Click += gcnew System::EventHandler(this, &MainForm::buttonMenuConnect_Click);
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
			this->buttonClose->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonClose->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonClose->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonClose->Location = System::Drawing::Point(1079, 0);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(40, 30);
			this->buttonClose->TabIndex = 5;
			this->buttonClose->Text = L"X";
			this->buttonClose->UseVisualStyleBackColor = false;
			this->buttonClose->Click += gcnew System::EventHandler(this, &MainForm::buttonClose_Click);
			// 
			// buttonHoming
			// 
			this->buttonHoming->BackColor = System::Drawing::Color::Transparent;
			this->buttonHoming->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonHoming->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonHoming->Enabled = false;
			this->buttonHoming->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonHoming->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonHoming->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonHoming->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonHoming->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonHoming->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonHoming->Location = System::Drawing::Point(229, 0);
			this->buttonHoming->Name = L"buttonHoming";
			this->buttonHoming->Size = System::Drawing::Size(144, 45);
			this->buttonHoming->TabIndex = 14;
			this->buttonHoming->Text = L"AUTO HOME";
			this->buttonHoming->UseVisualStyleBackColor = false;
			this->buttonHoming->Click += gcnew System::EventHandler(this, &MainForm::buttonHoming_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->buttonMinimize);
			this->panel1->Controls->Add(this->buttonMaximize);
			this->panel1->Controls->Add(this->buttonClose);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(166, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1121, 32);
			this->panel1->TabIndex = 15;
			// 
			// buttonMinimize
			// 
			this->buttonMinimize->BackColor = System::Drawing::Color::Transparent;
			this->buttonMinimize->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonMinimize->Dock = System::Windows::Forms::DockStyle::Right;
			this->buttonMinimize->FlatAppearance->BorderSize = 0;
			this->buttonMinimize->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->buttonMinimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMinimize->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonMinimize->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonMinimize->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonMinimize->Location = System::Drawing::Point(999, 0);
			this->buttonMinimize->Name = L"buttonMinimize";
			this->buttonMinimize->Size = System::Drawing::Size(40, 30);
			this->buttonMinimize->TabIndex = 7;
			this->buttonMinimize->Text = L"—";
			this->buttonMinimize->UseVisualStyleBackColor = false;
			this->buttonMinimize->Click += gcnew System::EventHandler(this, &MainForm::buttonMinimize_Click);
			// 
			// buttonMaximize
			// 
			this->buttonMaximize->BackColor = System::Drawing::Color::Transparent;
			this->buttonMaximize->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonMaximize->Dock = System::Windows::Forms::DockStyle::Right;
			this->buttonMaximize->FlatAppearance->BorderSize = 0;
			this->buttonMaximize->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->buttonMaximize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMaximize->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonMaximize->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonMaximize->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonMaximize->Location = System::Drawing::Point(1039, 0);
			this->buttonMaximize->Name = L"buttonMaximize";
			this->buttonMaximize->Size = System::Drawing::Size(40, 30);
			this->buttonMaximize->TabIndex = 6;
			this->buttonMaximize->Text = L"☐";
			this->buttonMaximize->UseVisualStyleBackColor = false;
			this->buttonMaximize->Click += gcnew System::EventHandler(this, &MainForm::buttonMaximize_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->panelConnect);
			this->panel3->Controls->Add(this->panelControl);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(166, 33);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(20, 20, 20, 30);
			this->panel3->Size = System::Drawing::Size(1121, 679);
			this->panel3->TabIndex = 16;
			this->panel3->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseDown);
			this->panel3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseMove);
			this->panel3->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel3_MouseUp);
			// 
			// panelConnect
			// 
			this->panelConnect->Controls->Add(this->buttonConnect);
			this->panelConnect->Controls->Add(this->radioButtonJoystick);
			this->panelConnect->Controls->Add(this->comboBoxPorts);
			this->panelConnect->Controls->Add(this->radioButtonHaptic);
			this->panelConnect->Controls->Add(this->label4);
			this->panelConnect->Controls->Add(this->buttonConnectDevice);
			this->panelConnect->Controls->Add(this->comboBoxBaudrate);
			this->panelConnect->Controls->Add(this->label3);
			this->panelConnect->Controls->Add(this->buttonRefresh);
			this->panelConnect->Location = System::Drawing::Point(5, 238);
			this->panelConnect->Name = L"panelConnect";
			this->panelConnect->Size = System::Drawing::Size(605, 203);
			this->panelConnect->TabIndex = 17;
			// 
			// radioButtonJoystick
			// 
			this->radioButtonJoystick->AutoSize = true;
			this->radioButtonJoystick->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButtonJoystick->ForeColor = System::Drawing::Color::Gainsboro;
			this->radioButtonJoystick->Location = System::Drawing::Point(385, 76);
			this->radioButtonJoystick->Name = L"radioButtonJoystick";
			this->radioButtonJoystick->Size = System::Drawing::Size(67, 19);
			this->radioButtonJoystick->TabIndex = 16;
			this->radioButtonJoystick->Text = L"Joystick";
			this->radioButtonJoystick->UseVisualStyleBackColor = true;
			// 
			// radioButtonHaptic
			// 
			this->radioButtonHaptic->AutoSize = true;
			this->radioButtonHaptic->Checked = true;
			this->radioButtonHaptic->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButtonHaptic->ForeColor = System::Drawing::Color::Gainsboro;
			this->radioButtonHaptic->Location = System::Drawing::Point(385, 45);
			this->radioButtonHaptic->Name = L"radioButtonHaptic";
			this->radioButtonHaptic->Size = System::Drawing::Size(99, 19);
			this->radioButtonHaptic->TabIndex = 15;
			this->radioButtonHaptic->TabStop = true;
			this->radioButtonHaptic->Text = L"Haptic Device";
			this->radioButtonHaptic->UseVisualStyleBackColor = true;
			// 
			// panelControl
			// 
			this->panelControl->Controls->Add(this->motionScaleBox);
			this->panelControl->Controls->Add(this->label6);
			this->panelControl->Controls->Add(this->buttonLeft);
			this->panelControl->Controls->Add(this->buttonDown);
			this->panelControl->Controls->Add(this->buttonRight);
			this->panelControl->Controls->Add(this->buttonUp);
			this->panelControl->Controls->Add(this->panel7);
			this->panelControl->Controls->Add(this->panel5);
			this->panelControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelControl->Location = System::Drawing::Point(20, 20);
			this->panelControl->Name = L"panelControl";
			this->panelControl->Size = System::Drawing::Size(1079, 584);
			this->panelControl->TabIndex = 20;
			// 
			// motionScaleBox
			// 
			this->motionScaleBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->motionScaleBox->Location = System::Drawing::Point(801, 421);
			this->motionScaleBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->motionScaleBox->Name = L"motionScaleBox";
			this->motionScaleBox->Size = System::Drawing::Size(102, 26);
			this->motionScaleBox->TabIndex = 25;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::Gainsboro;
			this->label6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label6->Location = System::Drawing::Point(797, 397);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(106, 21);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Motion Scale";
			// 
			// buttonLeft
			// 
			this->buttonLeft->BackColor = System::Drawing::Color::Transparent;
			this->buttonLeft->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonLeft->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLeft->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLeft->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->buttonLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonLeft.Image")));
			this->buttonLeft->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonLeft->Location = System::Drawing::Point(743, 185);
			this->buttonLeft->Name = L"buttonLeft";
			this->buttonLeft->Size = System::Drawing::Size(65, 65);
			this->buttonLeft->TabIndex = 23;
			this->buttonLeft->UseVisualStyleBackColor = false;
			this->buttonLeft->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonLeft_MouseDown);
			this->buttonLeft->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonLeft_MouseUp);
			// 
			// buttonDown
			// 
			this->buttonDown->BackColor = System::Drawing::Color::Transparent;
			this->buttonDown->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonDown->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonDown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDown->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDown->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->buttonDown->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonDown.Image")));
			this->buttonDown->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonDown->Location = System::Drawing::Point(814, 217);
			this->buttonDown->Name = L"buttonDown";
			this->buttonDown->Size = System::Drawing::Size(65, 65);
			this->buttonDown->TabIndex = 22;
			this->buttonDown->UseVisualStyleBackColor = false;
			this->buttonDown->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonDown_MouseDown);
			this->buttonDown->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonDown_MouseUp);
			// 
			// buttonRight
			// 
			this->buttonRight->BackColor = System::Drawing::Color::Transparent;
			this->buttonRight->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonRight->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonRight->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonRight->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->buttonRight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonRight.Image")));
			this->buttonRight->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonRight->Location = System::Drawing::Point(885, 185);
			this->buttonRight->Name = L"buttonRight";
			this->buttonRight->Size = System::Drawing::Size(65, 65);
			this->buttonRight->TabIndex = 21;
			this->buttonRight->UseVisualStyleBackColor = false;
			this->buttonRight->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonRight_MouseDown);
			this->buttonRight->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonRight_MouseUp);
			// 
			// buttonUp
			// 
			this->buttonUp->BackColor = System::Drawing::Color::Transparent;
			this->buttonUp->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonUp->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonUp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonUp->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->buttonUp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonUp.Image")));
			this->buttonUp->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonUp->Location = System::Drawing::Point(814, 148);
			this->buttonUp->Name = L"buttonUp";
			this->buttonUp->Size = System::Drawing::Size(65, 65);
			this->buttonUp->TabIndex = 20;
			this->buttonUp->UseVisualStyleBackColor = false;
			this->buttonUp->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonUp_MouseDown);
			this->buttonUp->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::buttonUp_MouseUp);
			// 
			// panel7
			// 
			this->panel7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel7->Location = System::Drawing::Point(0, 516);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1079, 23);
			this->panel7->TabIndex = 12;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->buttonVoiceCommand);
			this->panel5->Controls->Add(this->panel9);
			this->panel5->Controls->Add(this->buttonCameraFeed);
			this->panel5->Controls->Add(this->panel8);
			this->panel5->Controls->Add(this->buttonHoming);
			this->panel5->Controls->Add(this->panel6);
			this->panel5->Controls->Add(this->buttonStart);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel5->Location = System::Drawing::Point(0, 539);
			this->panel5->Name = L"panel5";
			this->panel5->Padding = System::Windows::Forms::Padding(40, 0, 0, 0);
			this->panel5->Size = System::Drawing::Size(1079, 45);
			this->panel5->TabIndex = 16;
			// 
			// buttonVoiceCommand
			// 
			this->buttonVoiceCommand->BackColor = System::Drawing::Color::Transparent;
			this->buttonVoiceCommand->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonVoiceCommand->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonVoiceCommand->Enabled = false;
			this->buttonVoiceCommand->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonVoiceCommand->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonVoiceCommand->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonVoiceCommand->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonVoiceCommand->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonVoiceCommand->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonVoiceCommand->Location = System::Drawing::Point(651, 0);
			this->buttonVoiceCommand->Name = L"buttonVoiceCommand";
			this->buttonVoiceCommand->Size = System::Drawing::Size(205, 45);
			this->buttonVoiceCommand->TabIndex = 19;
			this->buttonVoiceCommand->Text = L"START VOICE CONTROL";
			this->buttonVoiceCommand->UseVisualStyleBackColor = false;
			this->buttonVoiceCommand->Click += gcnew System::EventHandler(this, &MainForm::buttonVoiceCommand_Click);
			// 
			// panel9
			// 
			this->panel9->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel9->Location = System::Drawing::Point(606, 0);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(45, 45);
			this->panel9->TabIndex = 18;
			// 
			// buttonCameraFeed
			// 
			this->buttonCameraFeed->BackColor = System::Drawing::Color::Transparent;
			this->buttonCameraFeed->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCameraFeed->Dock = System::Windows::Forms::DockStyle::Left;
			this->buttonCameraFeed->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->buttonCameraFeed->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Gray;
			this->buttonCameraFeed->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonCameraFeed->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->buttonCameraFeed->ForeColor = System::Drawing::Color::Gainsboro;
			this->buttonCameraFeed->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->buttonCameraFeed->Location = System::Drawing::Point(418, 0);
			this->buttonCameraFeed->Name = L"buttonCameraFeed";
			this->buttonCameraFeed->Size = System::Drawing::Size(188, 45);
			this->buttonCameraFeed->TabIndex = 17;
			this->buttonCameraFeed->Text = L"START VIDEO STREAM";
			this->buttonCameraFeed->UseVisualStyleBackColor = false;
			this->buttonCameraFeed->Click += gcnew System::EventHandler(this, &MainForm::buttonCameraFeed_Click);
			// 
			// panel8
			// 
			this->panel8->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel8->Location = System::Drawing::Point(373, 0);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(45, 45);
			this->panel8->TabIndex = 16;
			// 
			// panel6
			// 
			this->panel6->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel6->Location = System::Drawing::Point(184, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(45, 45);
			this->panel6->TabIndex = 15;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->labelError);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel4->Location = System::Drawing::Point(20, 604);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(30, 10, 10, 10);
			this->panel4->Size = System::Drawing::Size(1079, 43);
			this->panel4->TabIndex = 18;
			// 
			// labelError
			// 
			this->labelError->AutoSize = true;
			this->labelError->Dock = System::Windows::Forms::DockStyle::Fill;
			this->labelError->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelError->ForeColor = System::Drawing::Color::Red;
			this->labelError->Location = System::Drawing::Point(30, 10);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(87, 21);
			this->labelError->TabIndex = 0;
			this->labelError->Text = L"*No errors";
			this->labelError->Visible = false;
			// 
			// timerIncrementer
			// 
			this->timerIncrementer->Tick += gcnew System::EventHandler(this, &MainForm::timerIncrementer_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateBlue;
			this->ClientSize = System::Drawing::Size(1288, 713);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panelConnect->ResumeLayout(false);
			this->panelConnect->PerformLayout();
			this->panelControl->ResumeLayout(false);
			this->panelControl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->motionScaleBox))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
		System::Void buttonConnect_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonConnectDevice_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void serialPort_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e);
		System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonHoming_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonMenuConnect_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonMenuControl_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonMaximize_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonMinimize_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonCameraFeed_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonVoiceCommand_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void timerIncrementer_Tick(System::Object^ sender, System::EventArgs^ e);

		System::Void buttonUp_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void buttonUp_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void buttonDown_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void buttonDown_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void buttonLeft_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void buttonLeft_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void buttonRight_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void buttonRight_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

		void ctrl_device_main();
		void robot_main();
		void _connect_serial();
		void _disconnect_serial();
		void _connect_device();
		void _disconnect_device();
		void set_label2(System::String^ data);
		void set_label5(System::String^ data);
		void serial_write(System::String^ data);
		void set_device_selectbox(bool setstate);
		void set_buttons_state(bool setstate);
		//void ReadJoystickInput();
		//void InitializeJoystick();
		//void OnJoystickTick(Object^ sender, EventArgs^ e);
		//BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE* instance, VOID* context);

		System::Threading::Thread^ ctrlDeviceThread;
		System::Threading::Thread^ robotThread;

		System::Windows::Forms::Timer^ joystickTimer;

		public:
			bool startApp;
			bool connected;

			bool buttonUpPressed;
			bool buttonDownPressed;
			bool buttonLeftPressed;
			bool buttonRightPressed;

			static bool streaming;

			int test = 0;
			int joyX = 32767;
			int joyY = 32767;
			int joyZ = 32767;

			void update_error_label(System::String^ data, bool visible);
			delegate void UpdateErrorLabelDelegate(System::String^, bool);

			System::String^ positionData;
			System::String^ command;

		//FORM DRAGGING--------------------------------------------------------------------
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

		private: System::Void panel2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = true;
			dragCursorPoint = Cursor->Position;
			dragFormPoint = this->Location;
		}

		private: System::Void panel2_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (dragging) {
				System::Drawing::Point diff = System::Drawing::Point(Cursor->Position.X - dragCursorPoint.X,
					Cursor->Position.Y - dragCursorPoint.Y);
				this->Location = System::Drawing::Point(dragFormPoint.X + diff.X, dragFormPoint.Y + diff.Y);
			}
		}

		private: System::Void panel2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
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