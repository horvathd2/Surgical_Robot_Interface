#include "drdc.h"
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#pragma once

namespace SurgicalRobotInterface {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StreamForm
	/// </summary>
	public ref class StreamForm : public System::Windows::Forms::Form
	{
	public:
		StreamForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StreamForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel3;
	protected:
	private: System::Windows::Forms::Panel^ panelControl;
	private: System::Windows::Forms::PictureBox^ videoFeedOutput;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonMinimize;
	private: System::Windows::Forms::Button^ buttonMaximize;
	private: System::Windows::Forms::Button^ buttonClose;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panelControl = (gcnew System::Windows::Forms::Panel());
			this->videoFeedOutput = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonMinimize = (gcnew System::Windows::Forms::Button());
			this->buttonMaximize = (gcnew System::Windows::Forms::Button());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel3->SuspendLayout();
			this->panelControl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoFeedOutput))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->panelControl);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(1, 33);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(20, 20, 20, 30);
			this->panel3->Size = System::Drawing::Size(1198, 566);
			this->panel3->TabIndex = 17;
			// 
			// panelControl
			// 
			this->panelControl->Controls->Add(this->videoFeedOutput);
			this->panelControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelControl->Location = System::Drawing::Point(20, 20);
			this->panelControl->Name = L"panelControl";
			this->panelControl->Size = System::Drawing::Size(1156, 514);
			this->panelControl->TabIndex = 20;
			// 
			// videoFeedOutput
			// 
			this->videoFeedOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->videoFeedOutput->Location = System::Drawing::Point(0, 0);
			this->videoFeedOutput->Name = L"videoFeedOutput";
			this->videoFeedOutput->Size = System::Drawing::Size(1156, 514);
			this->videoFeedOutput->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->videoFeedOutput->TabIndex = 19;
			this->videoFeedOutput->TabStop = false;
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
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1198, 32);
			this->panel1->TabIndex = 18;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &StreamForm::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StreamForm::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &StreamForm::panel1_MouseUp);
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
			this->buttonMinimize->Location = System::Drawing::Point(1076, 0);
			this->buttonMinimize->Name = L"buttonMinimize";
			this->buttonMinimize->Size = System::Drawing::Size(40, 30);
			this->buttonMinimize->TabIndex = 7;
			this->buttonMinimize->Text = L"—";
			this->buttonMinimize->UseVisualStyleBackColor = false;
			this->buttonMinimize->Click += gcnew System::EventHandler(this, &StreamForm::buttonMinimize_Click);
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
			this->buttonMaximize->Location = System::Drawing::Point(1116, 0);
			this->buttonMaximize->Name = L"buttonMaximize";
			this->buttonMaximize->Size = System::Drawing::Size(40, 30);
			this->buttonMaximize->TabIndex = 6;
			this->buttonMaximize->Text = L"☐";
			this->buttonMaximize->UseVisualStyleBackColor = false;
			this->buttonMaximize->Click += gcnew System::EventHandler(this, &StreamForm::buttonMaximize_Click);
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
			this->buttonClose->Location = System::Drawing::Point(1156, 0);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(40, 30);
			this->buttonClose->TabIndex = 5;
			this->buttonClose->Text = L"X";
			this->buttonClose->UseVisualStyleBackColor = false;
			this->buttonClose->Click += gcnew System::EventHandler(this, &StreamForm::buttonClose_Click);
			// 
			// StreamForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateBlue;
			this->ClientSize = System::Drawing::Size(1200, 600);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"StreamForm";
			this->Padding = System::Windows::Forms::Padding(1);
			this->Text = L"StreamForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StreamForm::StreamForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StreamForm::StreamForm_Load);
			this->panel3->ResumeLayout(false);
			this->panelControl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoFeedOutput))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void StreamForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonMaximize_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonMinimize_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void StreamForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);

		void stream_main();
		void UpdateFrame(Bitmap^ b);
		delegate void UPDATE_FRAME(Bitmap^ b);

		System::Threading::Thread^ streamThread;

		//FORM DRAGGING
	private:
		bool dragging;
		System::Drawing::Point dragCursorPoint;
		System::Drawing::Point dragFormPoint;

	private: System::Void panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		dragCursorPoint = Cursor->Position;
		dragFormPoint = this->Location;
	}
	private: System::Void panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			System::Drawing::Point diff = System::Drawing::Point(Cursor->Position.X - dragCursorPoint.X,
				Cursor->Position.Y - dragCursorPoint.Y);
			this->Location = System::Drawing::Point(dragFormPoint.X + diff.X, dragFormPoint.Y + diff.Y);
		}
	}
	private: System::Void panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
	};
}
