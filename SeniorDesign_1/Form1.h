#pragma once

#include <stdlib.h>
#include "Client.h"
#include <fstream>
#include <string>
#include <iostream>
#include "msclr\marshal_cppstd.h"
//using namespace std;
#include <string>
#include "ClientFunctions.h"
#include <queue>

//CircularBuffer fifoD;
queue<string> fifoQ;

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

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here



		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 

	protected: 

	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;








	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  profileNameCB;










	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  stopButton;

	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Button^  saveButton;



	private: System::Windows::Forms::NumericUpDown^  samplesPerStepUpDown;

	private: System::Windows::Forms::NumericUpDown^  stepsPerSweepUpDown;

	private: System::Windows::Forms::NumericUpDown^  sweepDelayUpDown;

	private: System::Windows::Forms::NumericUpDown^  numberOfSweepsUpDown;

	private: System::Windows::Forms::NumericUpDown^  minFrequencyUpDown;

	private: System::Windows::Forms::NumericUpDown^  maxFrequencyUpDown;
	private: System::Windows::Forms::Button^  okButton;






	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Button^  button6;
	private: System::ComponentModel::IContainer^  components;










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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->stopButton = (gcnew System::Windows::Forms::Button());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->samplesPerStepUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->stepsPerSweepUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->sweepDelayUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->numberOfSweepsUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->minFrequencyUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->maxFrequencyUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->profileNameCB = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->samplesPerStepUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepsPerSweepUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sweepDelayUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numberOfSweepsUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minFrequencyUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->maxFrequencyUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(612, 360);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->splitContainer1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(604, 334);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Settings/Controls";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->button6);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label9);
			this->splitContainer1->Panel1->Controls->Add(this->label8);
			this->splitContainer1->Panel1->Controls->Add(this->stopButton);
			this->splitContainer1->Panel1->Controls->Add(this->startButton);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(598, 328);
			this->splitContainer1->SplitterDistance = 56;
			this->splitContainer1->TabIndex = 1;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(568, 5);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(28, 20);
			this->button6->TabIndex = 8;
			this->button6->Text = L"...";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click_1);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(302, 31);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(269, 20);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(302, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(269, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(275, 34);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(21, 13);
			this->label9->TabIndex = 3;
			this->label9->Text = L"as:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(179, 9);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(117, 13);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Output will be saved in:";
			// 
			// stopButton
			// 
			this->stopButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->stopButton->Location = System::Drawing::Point(75, 0);
			this->stopButton->Name = L"stopButton";
			this->stopButton->Size = System::Drawing::Size(75, 56);
			this->stopButton->TabIndex = 1;
			this->stopButton->Text = L"Stop";
			this->stopButton->UseVisualStyleBackColor = true;
			// 
			// startButton
			// 
			this->startButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->startButton->Location = System::Drawing::Point(0, 0);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 56);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// splitContainer2
			// 
			this->splitContainer2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->BackColor = System::Drawing::Color::White;
			this->splitContainer2->Panel1->Controls->Add(this->okButton);
			this->splitContainer2->Panel1->Controls->Add(this->samplesPerStepUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->stepsPerSweepUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->sweepDelayUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->numberOfSweepsUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->minFrequencyUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->maxFrequencyUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->saveButton);
			this->splitContainer2->Panel1->Controls->Add(this->profileNameCB);
			this->splitContainer2->Panel1->Controls->Add(this->label7);
			this->splitContainer2->Panel1->Controls->Add(this->label6);
			this->splitContainer2->Panel1->Controls->Add(this->label5);
			this->splitContainer2->Panel1->Controls->Add(this->label4);
			this->splitContainer2->Panel1->Controls->Add(this->label3);
			this->splitContainer2->Panel1->Controls->Add(this->label2);
			this->splitContainer2->Panel1->Controls->Add(this->label1);
			this->splitContainer2->Panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->splitContainer2->Panel1->ForeColor = System::Drawing::SystemColors::ControlText;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->zedGraphControl1);
			this->splitContainer2->Panel2->Controls->Add(this->button4);
			this->splitContainer2->Size = System::Drawing::Size(598, 268);
			this->splitContainer2->SplitterDistance = 222;
			this->splitContainer2->TabIndex = 0;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(123, 195);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(90, 23);
			this->okButton->TabIndex = 23;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			// 
			// samplesPerStepUpDown
			// 
			this->samplesPerStepUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->samplesPerStepUpDown->Location = System::Drawing::Point(101, 169);
			this->samplesPerStepUpDown->Name = L"samplesPerStepUpDown";
			this->samplesPerStepUpDown->Size = System::Drawing::Size(82, 20);
			this->samplesPerStepUpDown->TabIndex = 22;
			// 
			// stepsPerSweepUpDown
			// 
			this->stepsPerSweepUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->stepsPerSweepUpDown->Location = System::Drawing::Point(101, 144);
			this->stepsPerSweepUpDown->Name = L"stepsPerSweepUpDown";
			this->stepsPerSweepUpDown->Size = System::Drawing::Size(82, 20);
			this->stepsPerSweepUpDown->TabIndex = 21;
			// 
			// sweepDelayUpDown
			// 
			this->sweepDelayUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->sweepDelayUpDown->Location = System::Drawing::Point(131, 116);
			this->sweepDelayUpDown->Name = L"sweepDelayUpDown";
			this->sweepDelayUpDown->Size = System::Drawing::Size(82, 20);
			this->sweepDelayUpDown->TabIndex = 20;
			// 
			// numberOfSweepsUpDown
			// 
			this->numberOfSweepsUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numberOfSweepsUpDown->Location = System::Drawing::Point(101, 90);
			this->numberOfSweepsUpDown->Name = L"numberOfSweepsUpDown";
			this->numberOfSweepsUpDown->Size = System::Drawing::Size(82, 20);
			this->numberOfSweepsUpDown->TabIndex = 19;
			// 
			// minFrequencyUpDown
			// 
			this->minFrequencyUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->minFrequencyUpDown->Location = System::Drawing::Point(101, 64);
			this->minFrequencyUpDown->Name = L"minFrequencyUpDown";
			this->minFrequencyUpDown->Size = System::Drawing::Size(82, 20);
			this->minFrequencyUpDown->TabIndex = 18;
			// 
			// maxFrequencyUpDown
			// 
			this->maxFrequencyUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maxFrequencyUpDown->Location = System::Drawing::Point(101, 38);
			this->maxFrequencyUpDown->Name = L"maxFrequencyUpDown";
			this->maxFrequencyUpDown->Size = System::Drawing::Size(82, 20);
			this->maxFrequencyUpDown->TabIndex = 15;
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(11, 197);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(91, 23);
			this->saveButton->TabIndex = 14;
			this->saveButton->Text = L"Save Settings";
			this->saveButton->UseVisualStyleBackColor = true;
			// 
			// profileNameCB
			// 
			this->profileNameCB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->profileNameCB->FormattingEnabled = true;
			this->profileNameCB->Location = System::Drawing::Point(76, 10);
			this->profileNameCB->Name = L"profileNameCB";
			this->profileNameCB->Size = System::Drawing::Size(107, 21);
			this->profileNameCB->TabIndex = 7;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 171);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Samples/Step:";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 146);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Steps/Sweep:";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 120);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(123, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Delay Between Sweeps:";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 92);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"# of Sweeps:";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Min. Frequency:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Max. Frequency:";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Profile Name:";
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphControl1->Location = System::Drawing::Point(29, 0);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(339, 264);
			this->zedGraphControl1->TabIndex = 2;
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Left;
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(29, 264);
			this->button4->TabIndex = 1;
			this->button4->Text = L"<<";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(604, 334);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Data";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(604, 334);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Graphs/Post Processing";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(612, 360);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->samplesPerStepUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepsPerSweepUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sweepDelayUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numberOfSweepsUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minFrequencyUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->maxFrequencyUpDown))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//button3 named saveButton
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {			 }
private: System::Void splitContainer2_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
		 
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (button4->Text == ">>")
			 {
				button4->Text = "<<";
				splitContainer2->Panel1Collapsed = false;
			 }
			 else
			 {
				button4->Text = ">>";
				splitContainer2->Panel1Collapsed = true;
			 }
		 }

private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
//Initialize form stuff	
		 }
private: void CreateGraph( ZedGraphControl ^zgc )
	{
		GraphPane ^myPane = zgc->GraphPane;

		// Set the titles and axis labels
		myPane->Title->Text = "Data vs Time";
		myPane->XAxis->Title->Text = "Time (s)";
		myPane->YAxis->Title->Text = "Data";
		//myPane->XAxis->Type= AxisType::Date;
		//myPane->XAxis->Scale->MajorUnit = DateUnit::Second;
        //myPane->XAxis->Scale->MinorUnit = DateUnit::Second;
		
		//myPane->XAxis->Scale->Min = DateTime::Now::Subtract(new TimeSpan(0, 0, 10, 0, 0)::ToOADate();
        //myPane->XAxis->Scale->Max = DateTime::Now::ToOADate();

		//needs to be called any time data is added or changed
		//zgc->AxisChanged();
		//zgc->Refresh();
		// ifstream inFile;


		 double tickStart = Environment::TickCount;


			 PointPairList ^dataList = gcnew PointPairList();
			 ifstream inFile;
			 ofstream outFile;
			 inFile.open("C:\\Users\\CME\\Desktop\\PracticeFile1.txt");
			 std::string outFileName = marshal_as<std::string>(textBox2->Text);
			 std::string outFilePath = marshal_as<std::string>(textBox1->Text);
			 std::string outFileComplete = outFilePath + "\\" + outFileName;
			  int data;//, dataY;
			  LineItem ^myCurve = myPane->AddCurve("DataList", dataList, Color::Red, SymbolType::Diamond);
			  outFile.open(outFileComplete);
			//do
			  while(inFile>>data)
			  {
				 double time = (Environment::TickCount - tickStart) / 1000.0;
				 //inFile >> data;
				 dataList->Add(time,data);
				 outFile << data << endl;

				 //LineItem ^myCurve = myPane->AddCurve(dataList, Color::Red, SymbolType::Diamond);
				 zgc->AxisChange();
				 zgc->Refresh();

				// this->chart1->Series["Data"]->Points->AddY(data);
				// outFile << data << endl;
			  }//while(!inFile.eof());
		 }
		 //button1 name change to startButton
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 CreateGraph(zedGraphControl1);
			 string str1;
 			 string msgtype="s";
			 string addrloc="1";
			 string dat="ith30tha309ut0";
			 str1.assign(msgtype);
			 str1.append(addrloc);
			 str1.append(dat);
			 char *a=new char[str1.size()+1];
			 a[str1.size()]=0;
			 memcpy(a,str1.c_str(),str1.size());
			 fifoQ.push(str1);
			 mkConnection();
			 sendThis(str1);
			 recvThis();
			 rmConnection();
//			 ClientRun(str1);//correct utilization of client send should use the fifo.


		 }
/*
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 //file i/o
			 ifstream inFile;
			 ofstream outFile;
			 inFile.open("C:\\Users\\CME\\Desktop\\PracticeFile1.txt");
			 std::string outFileName = marshal_as<std::string>(textBox2->Text);
			 std::string outFilePath = marshal_as<std::string>(textBox1->Text);
			 std::string outFileComplete = outFilePath + "\\" + outFileName;
			 //textBox3->Text = marshal_as<System::String>(outFileComplete);
			 outFile.open(outFileComplete);
			 int data;
			 while(!inFile.eof())
			 {
				 inFile >> data;
//				 this->chart1->Series["Data"]->Points->AddY(data);
				 outFile << data << endl;
			 }
		 }
		 */
private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 folderBrowserDialog1->ShowDialog();
			 textBox1->Text= folderBrowserDialog1->SelectedPath;

		 }
};

}

