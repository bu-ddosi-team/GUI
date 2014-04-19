#pragma once

#include <stdlib.h>
//#include "Client.h"
#include <fstream>
#include <string>
#include <iostream>
#include "msclr\marshal_cppstd.h"
#include <string>
#include <queue>
#include "tinyxml2.h"
#include "ProfileNameWindow.h"
#include "Warning_DateandPatientName.h"
#include "OouraFft.h"
#include "Fft.h"
#include "FlattopWindow.h"
#include "AquilaFft.h"
#include "Dct.h"
#include "Dft.h"
#include "FftFactory.h"
#include <stdint.h>



namespace SeniorDesign_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace ZedGraph;
	using namespace std;
	using namespace tinyxml2;
	//using namespace ClientDll;
//	using namespace Form1;

	/// <summary>
	/// Summary for ProfileNameWindow
	/// </summary>
	public ref class ProfileNameWindow : public System::Windows::Forms::Form
	{
	public:
		//declare a flag variable to indicate whether the settings should be saved to the file
		//int flagSave;
//		private
		//Form1 parentForm;
		const char* stepSize_pnw;
		const char* minFrequency_pnw;
		const char* numOfSweeps_pnw;
		const char* delayBetweenSweeps_pnw;
		const char* stepsPerSweep_pnw;
		const char* samplesPerStep_pnw;
		const char* gain_pnw;
		const char* laserDiodePattern_pnw;
		String^ ProfileName;
		ComboBox^ ProfNameCB_pnw;

		ProfileNameWindow(const char* stepSizeIn, const char* minFrequencyIn, const char* numOfSweepsIn, const char* delayBetweenSweepsIn, const char* stepsPerSweepIn, const char* samplesPerStepIn, const char* laserDiodePatternIn, ComboBox^ profileNameCBIn)
		{
			InitializeComponent();
			//flagSave = 0;
			stepSize_pnw = stepSizeIn;
			minFrequency_pnw = minFrequencyIn;
			numOfSweeps_pnw = numOfSweepsIn;
			delayBetweenSweeps_pnw = delayBetweenSweepsIn;
			stepsPerSweep_pnw = stepsPerSweepIn;
			samplesPerStep_pnw = samplesPerStepIn;
			//gain_pnw = gainIn;
			laserDiodePattern_pnw = laserDiodePatternIn;
			ProfNameCB_pnw = profileNameCBIn;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProfileNameWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Profile Name:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(116, 23);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(218, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ProfileNameWindow::button1_Click);
			// 
			// ProfileNameWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(366, 94);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ProfileNameWindow";
			this->Text = L"ProfileNameWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Hide();
			     this->SaveProfile();
			 }
	//Not currently using this function
	public: System::String^ getProfileName(){
				//String^ 
				ProfileName =  this->textBox1->Text;
				//clear text from textbox in PopUp window
				this->textBox1->Clear();
				return ProfileName;
			}
	public: System::Void SaveProfile(){
		marshal_context ^ context = gcnew marshal_context();
		FILE *outFile;
		outFile = fopen("C:\\Users\\CME\\Desktop\\ProfileName.xml", "a");
	    XMLPrinter printer(outFile);
		ProfileName = this->textBox1->Text;
		this->textBox1->Clear();
		const char* ProfileName_pnw;
		this->ProfNameCB_pnw->Items->Add(ProfileName);
		ProfileName_pnw = context->marshal_as<const char*>(ProfileName);
		printer.OpenElement(ProfileName_pnw, false);
		printer.PushAttribute("stepSize", stepSize_pnw);
	    printer.PushAttribute("MinFrequency", minFrequency_pnw);
		printer.PushAttribute("NumOfSweeps", numOfSweeps_pnw);
		printer.PushAttribute("DelayBetweenSweeps", delayBetweenSweeps_pnw);
		printer.PushAttribute("StepsPerSweep", stepsPerSweep_pnw);
		printer.PushAttribute("SamplesPerStep", samplesPerStep_pnw);
		printer.PushAttribute("LaserDiodePattern", laserDiodePattern_pnw);
	    printer.CloseElement(false);	  

		//close file
		fclose(outFile);

	}

	};
}
