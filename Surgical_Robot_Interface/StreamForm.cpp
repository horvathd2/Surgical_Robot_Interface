#include "StreamForm.h"
#include "MainForm.h"

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

void StreamForm::stream_main() {
	int camera_device = 0;
	cv::VideoCapture capture;
	Mat frame;
	MainForm^ mainForm = gcnew MainForm();

	capture.open(camera_device);
	if (!capture.isOpened()) {
		mainForm->update_error_label("*Error, cannot open video feed.", true);
		return;
	}
	mainForm->update_error_label("*No errors.", false);

	while (capture.read(frame)) {
		if (frame.empty()) break;

		Bitmap^ b;
		if (videoFeedOutput->InvokeRequired) {
			UPDATE_FRAME^ cb = gcnew UPDATE_FRAME(this, &StreamForm::UpdateFrame);
			Bitmap^ b = gcnew Bitmap(frame.cols, frame.rows, frame.step, Imaging::PixelFormat::Format24bppRgb, System::IntPtr(frame.data));
			Control::Invoke(cb, b);
		}
		else UpdateFrame(b);
	}
}

void StreamForm::StreamForm_Load(System::Object^ sender, System::EventArgs^ e) {
	if (MainForm::streaming) {
		streamThread = gcnew Thread(gcnew ThreadStart(this, &StreamForm::stream_main));
		streamThread->Start();
	}
	else {
		if (streamThread != nullptr)
		{
			if (true == streamThread->IsAlive)
			{
				streamThread->Abort();
			}
		}
	}
}

void StreamForm::StreamForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (streamThread != nullptr)
	{
		if (true == streamThread->IsAlive)
		{
			streamThread->Abort();
		}
	}
}

void StreamForm::buttonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show(
		"Are you sure that you would like to exit?",
		"Form Closing", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) this->Close();
}

void StreamForm::buttonMaximize_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == System::Windows::Forms::FormWindowState::Normal) {
		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
	}
	else {
		this->WindowState = System::Windows::Forms::FormWindowState::Normal;
	}
}

void StreamForm::buttonMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
}

void StreamForm::UpdateFrame(Bitmap^ b) {
	videoFeedOutput->Image = b;
}