
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
			//
			//TODO: Add the constructor code here
			//
		}
	public: System::Windows::Forms::Button^ buttonConnect;
	private: System::Windows::Forms::Button^ buttonClose;
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
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	public: System::Windows::Forms::Button^ buttonHoming;

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
	public: System::Windows::Forms::Button^ buttonHaptic;

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
			this->buttonHaptic = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxPorts = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxBaudrate = (gcnew System::Windows::Forms::ComboBox());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->buttonHoming = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(342, 293);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// buttonStart
			// 
			this->buttonStart->Enabled = false;
			this->buttonStart->Location = System::Drawing::Point(321, 348);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(120, 40);
			this->buttonStart->TabIndex = 1;
			this->buttonStart->Text = L"START";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &MainForm::buttonStart_Click);
			// 
			// buttonHaptic
			// 
			this->buttonHaptic->Location = System::Drawing::Point(545, 348);
			this->buttonHaptic->Name = L"buttonHaptic";
			this->buttonHaptic->Size = System::Drawing::Size(120, 40);
			this->buttonHaptic->TabIndex = 2;
			this->buttonHaptic->Text = L"CONNECT HAPTIC";
			this->buttonHaptic->UseVisualStyleBackColor = true;
			this->buttonHaptic->Click += gcnew System::EventHandler(this, &MainForm::buttonConnectHaptic_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(572, 293);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(762, 348);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(120, 40);
			this->buttonConnect->TabIndex = 4;
			this->buttonConnect->Text = L"CONNECT";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &MainForm::buttonConnect_Click);
			// 
			// buttonClose
			// 
			this->buttonClose->Location = System::Drawing::Point(1253, 3);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(41, 29);
			this->buttonClose->TabIndex = 5;
			this->buttonClose->Text = L"X";
			this->buttonClose->UseVisualStyleBackColor = true;
			this->buttonClose->Click += gcnew System::EventHandler(this, &MainForm::buttonClose_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(311, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Serial Port";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(311, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Baud Rate";
			// 
			// comboBoxPorts
			// 
			this->comboBoxPorts->FormattingEnabled = true;
			this->comboBoxPorts->Location = System::Drawing::Point(395, 135);
			this->comboBoxPorts->Name = L"comboBoxPorts";
			this->comboBoxPorts->Size = System::Drawing::Size(121, 21);
			this->comboBoxPorts->TabIndex = 8;
			// 
			// comboBoxBaudrate
			// 
			this->comboBoxBaudrate->FormattingEnabled = true;
			this->comboBoxBaudrate->Location = System::Drawing::Point(395, 165);
			this->comboBoxBaudrate->Name = L"comboBoxBaudrate";
			this->comboBoxBaudrate->Size = System::Drawing::Size(121, 21);
			this->comboBoxBaudrate->TabIndex = 9;
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->Location = System::Drawing::Point(533, 135);
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
			this->label5->Location = System::Drawing::Point(572, 244);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"label5";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->panel1->Controls->Add(this->buttonClose);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1297, 35);
			this->panel1->TabIndex = 12;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Gainsboro;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 35);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 627);
			this->panel2->TabIndex = 13;
			// 
			// buttonHoming
			// 
			this->buttonHoming->Location = System::Drawing::Point(321, 411);
			this->buttonHoming->Name = L"buttonHoming";
			this->buttonHoming->Size = System::Drawing::Size(120, 40);
			this->buttonHoming->TabIndex = 14;
			this->buttonHoming->Text = L"HOME MOTORS";
			this->buttonHoming->UseVisualStyleBackColor = true;
			this->buttonHoming->Click += gcnew System::EventHandler(this, &MainForm::buttonHoming_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1297, 662);
			this->Controls->Add(this->buttonHoming);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonRefresh);
			this->Controls->Add(this->comboBoxBaudrate);
			this->Controls->Add(this->comboBoxPorts);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonHaptic);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

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
	};
}
