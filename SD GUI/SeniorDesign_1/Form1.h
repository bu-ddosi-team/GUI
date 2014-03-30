#pragma once

#include <stdlib.h>
#include "Client.h"
#include <fstream>
#include <string>
#include <iostream>
#include "msclr\marshal_cppstd.h"
#include <string>
//#include "Client_Functions.h"
#include <queue>
#include "tinyxml2.h"
#include "ProfileNameWindow.h"

//CircularBuffer fifoD;
//queue<string> fifoQ;

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
	using namespace ClientDll;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		//make PopUp window public variable
		ProfileNameWindow^ pnw;
	//private: System::Windows::Forms::TextBox^  textBox4;
	public: 
	//private: System::Windows::Forms::Label^  label23;
	//private: System::Windows::Forms::TextBox^  textBox2;
	//private: System::Windows::Forms::Label^  label9;
			 int numElements; //number of elements in the file
		Form1(void)
		{
			InitializeComponent();
			pnw = gcnew ProfileNameWindow();
			//Count the number of elements in the file when it opens
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile("C:\\Users\\CME\\Desktop\\ProfileName.xml");
			tinyxml2::XMLNode *currentNode_0 = xmlDoc.FirstChild();
			tinyxml2::XMLElement *currentElement_0;
			string elementName_0;
			String^ elementNameSysString_0;
			numElements = 0;
			while(currentNode_0 != NULL)
			{
				numElements++;
				currentElement_0 = currentNode_0 ->ToElement();
				elementName_0 = currentElement_0 -> Name();
				elementNameSysString_0 = marshal_as<System::String^> (elementName_0);//->Name();
				this->profileNameCB->Items->Add(elementNameSysString_0);
				currentNode_0 = currentNode_0 -> NextSibling();
			}
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

	protected: 

	protected: 

	protected: 

























































 

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  button6;

	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  stopButton;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::NumericUpDown^  samplesPerStepUpDown;
	private: System::Windows::Forms::NumericUpDown^  stepsPerSweepUpDown;
	private: System::Windows::Forms::NumericUpDown^  sweepDelayUpDown;
	private: System::Windows::Forms::NumericUpDown^  numberOfSweepsUpDown;
	private: System::Windows::Forms::NumericUpDown^  minFrequencyUpDown;
	private: System::Windows::Forms::NumericUpDown^  maxFrequencyUpDown;
	private: System::Windows::Forms::Button^  saveButton;
	private: System::Windows::Forms::ComboBox^  profileNameCB;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TabControl^  tabControl1;
private: System::Windows::Forms::TabPage^  tabPage2;
private: System::Windows::Forms::SplitContainer^  splitContainer3;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::NumericUpDown^  numericUpDown7;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::ComboBox^  comboBox1;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::CheckBox^  checkBox1;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::NumericUpDown^  numericUpDown8;
private: System::Windows::Forms::ComboBox^  comboBox2;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::Label^  label9;



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
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->stopButton = (gcnew System::Windows::Forms::Button());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->numericUpDown8 = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->samplesPerStepUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepsPerSweepUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sweepDelayUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numberOfSweepsUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minFrequencyUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->maxFrequencyUpDown))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->BeginInit();
			this->SuspendLayout();
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(697, 386);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Graphs/Post Processing";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->splitContainer1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(697, 386);
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
			this->splitContainer1->Panel1->Controls->Add(this->textBox4);
			this->splitContainer1->Panel1->Controls->Add(this->label23);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->label9);
			this->splitContainer1->Panel1->Controls->Add(this->button6);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label8);
			this->splitContainer1->Panel1->Controls->Add(this->stopButton);
			this->splitContainer1->Panel1->Controls->Add(this->startButton);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(691, 380);
			this->splitContainer1->SplitterDistance = 64;
			this->splitContainer1->TabIndex = 1;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(572, 34);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(28, 20);
			this->button6->TabIndex = 8;
			this->button6->Text = L"...";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(302, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(269, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(179, 38);
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
			this->stopButton->Size = System::Drawing::Size(75, 64);
			this->stopButton->TabIndex = 1;
			this->stopButton->Text = L"Stop";
			this->stopButton->UseVisualStyleBackColor = true;
			// 
			// startButton
			// 
			this->startButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->startButton->Location = System::Drawing::Point(0, 0);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(75, 64);
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
			this->splitContainer2->Panel1->Controls->Add(this->numericUpDown8);
			this->splitContainer2->Panel1->Controls->Add(this->comboBox2);
			this->splitContainer2->Panel1->Controls->Add(this->label22);
			this->splitContainer2->Panel1->Controls->Add(this->label21);
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
			this->splitContainer2->Size = System::Drawing::Size(691, 312);
			this->splitContainer2->SplitterDistance = 256;
			this->splitContainer2->TabIndex = 0;
			// 
			// numericUpDown8
			// 
			this->numericUpDown8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown8->Location = System::Drawing::Point(49, 199);
			this->numericUpDown8->Name = L"numericUpDown8";
			this->numericUpDown8->Size = System::Drawing::Size(116, 20);
			this->numericUpDown8->TabIndex = 27;
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Simultaneous", L"Sequential"});
			this->comboBox2->Location = System::Drawing::Point(110, 228);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(139, 21);
			this->comboBox2->TabIndex = 26;
			// 
			// label22
			// 
			this->label22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(8, 231);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(104, 13);
			this->label22->TabIndex = 25;
			this->label22->Text = L"Laser Diode Pattern:";
			// 
			// label21
			// 
			this->label21->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(8, 201);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(32, 13);
			this->label21->TabIndex = 24;
			this->label21->Text = L"Gain:";
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(127, 268);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(90, 23);
			this->okButton->TabIndex = 23;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &Form1::okButton_Click);
			// 
			// samplesPerStepUpDown
			// 
			this->samplesPerStepUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->samplesPerStepUpDown->Location = System::Drawing::Point(101, 169);
			this->samplesPerStepUpDown->Name = L"samplesPerStepUpDown";
			this->samplesPerStepUpDown->Size = System::Drawing::Size(116, 20);
			this->samplesPerStepUpDown->TabIndex = 22;
			// 
			// stepsPerSweepUpDown
			// 
			this->stepsPerSweepUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->stepsPerSweepUpDown->Location = System::Drawing::Point(101, 144);
			this->stepsPerSweepUpDown->Name = L"stepsPerSweepUpDown";
			this->stepsPerSweepUpDown->Size = System::Drawing::Size(116, 20);
			this->stepsPerSweepUpDown->TabIndex = 21;
			// 
			// sweepDelayUpDown
			// 
			this->sweepDelayUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->sweepDelayUpDown->Location = System::Drawing::Point(131, 116);
			this->sweepDelayUpDown->Name = L"sweepDelayUpDown";
			this->sweepDelayUpDown->Size = System::Drawing::Size(116, 20);
			this->sweepDelayUpDown->TabIndex = 20;
			// 
			// numberOfSweepsUpDown
			// 
			this->numberOfSweepsUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numberOfSweepsUpDown->Location = System::Drawing::Point(101, 90);
			this->numberOfSweepsUpDown->Name = L"numberOfSweepsUpDown";
			this->numberOfSweepsUpDown->Size = System::Drawing::Size(116, 20);
			this->numberOfSweepsUpDown->TabIndex = 19;
			// 
			// minFrequencyUpDown
			// 
			this->minFrequencyUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->minFrequencyUpDown->Location = System::Drawing::Point(101, 64);
			this->minFrequencyUpDown->Name = L"minFrequencyUpDown";
			this->minFrequencyUpDown->Size = System::Drawing::Size(116, 20);
			this->minFrequencyUpDown->TabIndex = 18;
			// 
			// maxFrequencyUpDown
			// 
			this->maxFrequencyUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->maxFrequencyUpDown->Location = System::Drawing::Point(101, 38);
			this->maxFrequencyUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->maxFrequencyUpDown->Name = L"maxFrequencyUpDown";
			this->maxFrequencyUpDown->Size = System::Drawing::Size(116, 20);
			this->maxFrequencyUpDown->TabIndex = 15;
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(11, 268);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(91, 23);
			this->saveButton->TabIndex = 14;
			this->saveButton->Text = L"Save Settings";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &Form1::saveButton_Click);
			// 
			// profileNameCB
			// 
			this->profileNameCB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->profileNameCB->FormattingEnabled = true;
			this->profileNameCB->Location = System::Drawing::Point(76, 10);
			this->profileNameCB->Name = L"profileNameCB";
			this->profileNameCB->Size = System::Drawing::Size(141, 21);
			this->profileNameCB->TabIndex = 7;
			this->profileNameCB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::profileNameCB_SelectedIndexChanged);
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
			this->zedGraphControl1->Size = System::Drawing::Size(398, 308);
			this->zedGraphControl1->TabIndex = 2;
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Left;
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(29, 308);
			this->button4->TabIndex = 1;
			this->button4->Text = L"<<";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(705, 412);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainer3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(697, 386);
			this->tabPage2->TabIndex = 3;
			this->tabPage2->Text = L"Debug";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(3, 3);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->label16);
			this->splitContainer3->Panel1->Controls->Add(this->numericUpDown7);
			this->splitContainer3->Panel1->Controls->Add(this->button1);
			this->splitContainer3->Panel1->Controls->Add(this->numericUpDown1);
			this->splitContainer3->Panel1->Controls->Add(this->numericUpDown2);
			this->splitContainer3->Panel1->Controls->Add(this->numericUpDown3);
			this->splitContainer3->Panel1->Controls->Add(this->numericUpDown4);
			this->splitContainer3->Panel1->Controls->Add(this->numericUpDown5);
			this->splitContainer3->Panel1->Controls->Add(this->numericUpDown6);
			this->splitContainer3->Panel1->Controls->Add(this->label10);
			this->splitContainer3->Panel1->Controls->Add(this->label11);
			this->splitContainer3->Panel1->Controls->Add(this->label12);
			this->splitContainer3->Panel1->Controls->Add(this->label13);
			this->splitContainer3->Panel1->Controls->Add(this->label14);
			this->splitContainer3->Panel1->Controls->Add(this->label15);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->button10);
			this->splitContainer3->Panel2->Controls->Add(this->checkBox1);
			this->splitContainer3->Panel2->Controls->Add(this->label20);
			this->splitContainer3->Panel2->Controls->Add(this->textBox3);
			this->splitContainer3->Panel2->Controls->Add(this->label19);
			this->splitContainer3->Panel2->Controls->Add(this->label18);
			this->splitContainer3->Panel2->Controls->Add(this->comboBox1);
			this->splitContainer3->Panel2->Controls->Add(this->label17);
			this->splitContainer3->Panel2->Controls->Add(this->button9);
			this->splitContainer3->Panel2->Controls->Add(this->button8);
			this->splitContainer3->Panel2->Controls->Add(this->button7);
			this->splitContainer3->Panel2->Controls->Add(this->button5);
			this->splitContainer3->Panel2->Controls->Add(this->button3);
			this->splitContainer3->Panel2->Controls->Add(this->button2);
			this->splitContainer3->Size = System::Drawing::Size(691, 380);
			this->splitContainer3->SplitterDistance = 293;
			this->splitContainer3->TabIndex = 0;
			// 
			// label16
			// 
			this->label16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(25, 256);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 13);
			this->label16->TabIndex = 39;
			this->label16->Text = L"Gain:";
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown7->Location = System::Drawing::Point(118, 249);
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(121, 20);
			this->numericUpDown7->TabIndex = 38;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(140, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 23);
			this->button1->TabIndex = 37;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown1->Location = System::Drawing::Point(118, 223);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(121, 20);
			this->numericUpDown1->TabIndex = 36;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown2->Location = System::Drawing::Point(118, 197);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(121, 20);
			this->numericUpDown2->TabIndex = 35;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown3->Location = System::Drawing::Point(148, 164);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(121, 20);
			this->numericUpDown3->TabIndex = 34;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown4->Location = System::Drawing::Point(118, 120);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(121, 20);
			this->numericUpDown4->TabIndex = 33;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown5->Location = System::Drawing::Point(118, 81);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(121, 20);
			this->numericUpDown5->TabIndex = 32;
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown6->Location = System::Drawing::Point(118, 37);
			this->numericUpDown6->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(121, 20);
			this->numericUpDown6->TabIndex = 31;
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(19, 223);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(77, 13);
			this->label10->TabIndex = 30;
			this->label10->Text = L"Samples/Step:";
			// 
			// label11
			// 
			this->label11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(19, 196);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(75, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"Steps/Sweep:";
			// 
			// label12
			// 
			this->label12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(16, 166);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(123, 13);
			this->label12->TabIndex = 28;
			this->label12->Text = L"Delay Between Sweeps:";
			// 
			// label13
			// 
			this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(19, 122);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(70, 13);
			this->label13->TabIndex = 27;
			this->label13->Text = L"# of Sweeps:";
			// 
			// label14
			// 
			this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(19, 81);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(83, 13);
			this->label14->TabIndex = 26;
			this->label14->Text = L"Min. Frequency:";
			// 
			// label15
			// 
			this->label15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(16, 37);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(86, 13);
			this->label15->TabIndex = 25;
			this->label15->Text = L"Max. Frequency:";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(285, 227);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(50, 23);
			this->button10->TabIndex = 33;
			this->button10->Text = L"Send";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(91, 272);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 32;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label20
			// 
			this->label20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(11, 272);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(74, 13);
			this->label20->TabIndex = 31;
			this->label20->Text = L"Save as XML:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(83, 227);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(202, 20);
			this->textBox3->TabIndex = 30;
			// 
			// label19
			// 
			this->label19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(11, 230);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(74, 13);
			this->label19->TabIndex = 29;
			this->label19->Text = L"Send a String:";
			// 
			// label18
			// 
			this->label18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(144, 92);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(44, 13);
			this->label18->TabIndex = 26;
			this->label18->Text = L"Pattern:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Simultaneous", L"Sequential"});
			this->comboBox1->Location = System::Drawing::Point(100, 108);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 7;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(10, 15);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(211, 24);
			this->label17->TabIndex = 6;
			this->label17->Text = L"Laser Diode Controls:";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(269, 42);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(45, 47);
			this->button9->TabIndex = 5;
			this->button9->Text = L"6";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(218, 42);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(45, 47);
			this->button8->TabIndex = 4;
			this->button8->Text = L"5";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(167, 42);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(45, 47);
			this->button7->TabIndex = 3;
			this->button7->Text = L"4";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(116, 42);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(45, 47);
			this->button5->TabIndex = 2;
			this->button5->Text = L"3";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(65, 42);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(45, 47);
			this->button3->TabIndex = 1;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(14, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(45, 47);
			this->button2->TabIndex = 0;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(179, 13);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(74, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Patient Name:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(259, 10);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(198, 20);
			this->textBox2->TabIndex = 10;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(463, 13);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(33, 13);
			this->label23->TabIndex = 11;
			this->label23->Text = L"Date:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(502, 10);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(176, 20);
			this->textBox4->TabIndex = 12;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(705, 412);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->samplesPerStepUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepsPerSweepUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->sweepDelayUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numberOfSweepsUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minFrequencyUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->maxFrequencyUpDown))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel1->PerformLayout();
			this->splitContainer3->Panel2->ResumeLayout(false);
			this->splitContainer3->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown6))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		

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

private: void CreateGraph( ZedGraphControl ^zgc ){
		GraphPane ^myPane = zgc->GraphPane;

		// Set the titles and axis labels
		myPane->Title->Text = "Data vs Time";
		myPane->XAxis->Title->Text = "Time (s)";
		myPane->YAxis->Title->Text = "Data";

	   double tickStart = Environment::TickCount;


			 PointPairList ^ChannelA = gcnew PointPairList();
			 PointPairList ^ChannelB = gcnew PointPairList();
			 ifstream inFile;
			 ofstream outFile;
			 inFile.open("fwrite_test.txt");
			 //inFile* fopen("fwrite_test.txt", "r"); //Open file for reading operations
			 std::string outFilePath = marshal_as<std::string>(textBox1->Text);
			 std::string PatientName = marshal_as<std::string>(textBox2->Text);
			 std::string Date = marshal_as<std::string>(textBox4->Text);
			 std::string outFileComplete = outFilePath + "\\" + PatientName + Date + ".csv";
			  int data;
			  LineItem ^myCurve1 = myPane->AddCurve("Channel A", ChannelA, Color::Blue, SymbolType::Diamond);
			  LineItem ^myCurve2 = myPane->AddCurve("Channel B", ChannelB, Color::Red, SymbolType::Diamond);

			  int count = 0;
			  int count2 = 0;

			  outFile.open(outFileComplete);
			  
			  while(inFile.read((char *)&data, sizeof(int)))
			  {
				  count++;
				 if (count%2 == 0)
				 {
					 ChannelB->Add((count2/250000000.0),data);
					 outFile << data << endl;
					 count2++;
				 }
				 else
				 {
					ChannelA->Add((count2/250000000.0),data);
					outFile << data << ",";
				 }
				 
				 zgc->AxisChange();
				 zgc->Refresh();
			  } //WHILE LOOP ENDS HERE
			outFile.close();
			inFile.close();
			count = 0;
		 }
		 //button1 name change to startButton
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
 			 string msgtype="s";
			 string caddr= "192.168.1.10";
			 DsauClient::mkConnection(caddr);
			 DsauClient::sendThis(msgtype);
			 DsauClient::recvThis();
			 CreateGraph(zedGraphControl1);
			 DsauClient::rmConnection();

			 /*
			 string str1;
 			 string msgtype="s";
			 string addrloc="0"; 
			 string dat="ith30tha309ut0";
			 str1.assign(msgtype);
			 str1.append(addrloc);
			 str1.append(dat);
			 string caddr= "192.168.1.10";
			 mkConnection(caddr);
			 sendThis(str1);
			 recvThis();
			//receive_int();
			 rmConnection();
			 CreateGraph(zedGraphControl1);
			// ClientRun(str1);//correct utilization of client send should use the fifo.
			*/

		 }

private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 folderBrowserDialog1->ShowDialog();
			 textBox1->Text= folderBrowserDialog1->SelectedPath;

		 }

private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 marshal_context ^ context = gcnew marshal_context();
			 if (pnw->flagSave == 1)
			 {
			  FILE *outFile;
			  outFile = fopen("C:\\Users\\CME\\Desktop\\ProfileName.xml", "a");
			  XMLPrinter printer(outFile);
			  //Add ProfileName to drop down menu
			  String^ ProfName = pnw->getProfileName();
			  this->profileNameCB->Items->Add(ProfName);
			  //increase the number of elements
			  numElements++;
			 //get Profile Name
			 const char* ProfileName = context->marshal_as<const char*>(ProfName);
			 //get Max. Frequency
			 const char* maxFrequency = context->marshal_as<const char*>(maxFrequencyUpDown->Text);
			 //get Min. Frequency
			 const char* minFrequency = context->marshal_as<const char*>(minFrequencyUpDown->Text);
			 //get # of sweeps
			 const char* numOfSweeps = context->marshal_as<const char*>(numberOfSweepsUpDown->Text);
			 //get delay between sweeps
			 const char* delayBetweenSweeps = context->marshal_as<const char*>(sweepDelayUpDown->Text);
			 //get Steps/Sweep
			 const char* stepsPerSweep = context->marshal_as<const char*>(stepsPerSweepUpDown->Text);
			 //get Samples/Step
			 const char* samplesPerStep = context->marshal_as<const char*>(samplesPerStepUpDown->Text);
			 //get gain
			 const char* gain = context->marshal_as<const char*>(numericUpDown7->Text);
			 //get Laser Diode Pattern
			 const char* laserDiodePattern = context->marshal_as<const char*>(comboBox2->Text);
			 //Write to XML file
			 printer.OpenElement(ProfileName, false);
			 printer.PushAttribute("MaxFrequency", maxFrequency);
			 printer.PushAttribute("MinFrequency", minFrequency);
			 printer.PushAttribute("NumOfSweeps", numOfSweeps);
			 printer.PushAttribute("DelayBetweenSweeps", delayBetweenSweeps);
			 printer.PushAttribute("StepsPerSweep", stepsPerSweep);
			 printer.PushAttribute("SamplesPerStep", samplesPerStep);
			 printer.PushAttribute("Gain", gain);
			 printer.PushAttribute("LaserDiodePattern", laserDiodePattern);
			 printer.CloseElement(false);

			// const char* value = ProfileName->ToElement()->Attribute( "maxFrequency" );
			// delete context;

			 //close file
			 fclose(outFile);

			 pnw->flagSave = 0; //reset flag to 0
			 }

			//Make connection to server
			 DsauClient::mkConnection("192.168.1.10");
			//send data
			 string maxF = "wa"; //string a ="a";
			 //get Max. Frequency
			 const char* maxFrequency = context->marshal_as<const char*>(maxFrequencyUpDown->Text);
			 DsauClient::sendThis(maxF.append(maxFrequency));
			 //get Min. Frequency
			 const char* minFrequency = context->marshal_as<const char*>(minFrequencyUpDown->Text);
			 string minF = "wb";
			 DsauClient::sendThis(minF.append(minFrequency));
			 //get # of sweeps
			 const char* numOfSweeps = context->marshal_as<const char*>(numberOfSweepsUpDown->Text);
			 //string NOS(numOfSweeps);
			 string NOS = "wc";		
			 DsauClient::sendThis(NOS.append(numOfSweeps));
			 //get delay between sweeps
			 const char* delayBetweenSweeps = context->marshal_as<const char*>(sweepDelayUpDown->Text);
			 string DBS = "wd";
			 DsauClient::sendThis(DBS.append(delayBetweenSweeps));
			 //get Steps/Sweep
			 const char* stepsPerSweep = context->marshal_as<const char*>(stepsPerSweepUpDown->Text);
			 //string StepsPS(stepsPerSweep);
			 string StepsPS = "we";
			 DsauClient::sendThis(StepsPS.append(stepsPerSweep));
			 //get Samples/Step
			 const char* samplesPerStep = context->marshal_as<const char*>(samplesPerStepUpDown->Text);
			// string SamPS(samplesPerStep);
			 string SamPS = "wf";		
			 DsauClient::sendThis(SamPS.append(samplesPerStep));
			 //get gain
			 /*
			 const char* gain = context->marshal_as<const char*>(numericUpDown7->Text);
			 DsauClient::sendThis(gain);
			 //get Laser Diode Pattern
			 const char* laserDiodePattern= context->marshal_as<const char*>(comboBox2->Text);
			 DsauClient::sendThis(laserDiodePattern);
			 */
			 DsauClient::rmConnection();

		 }


private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 //have pop up window to save profile name show up
				pnw->Show();
		 }

private: System::Void profileNameCB_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			marshal_context ^ context = gcnew marshal_context();
			const char* choice = context->marshal_as<const char*>(profileNameCB->Text); 
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile("C:\\Users\\CME\\Desktop\\ProfileName.xml");

			tinyxml2::XMLNode *currentNode = xmlDoc.FirstChild();
			tinyxml2::XMLElement *rootElement= currentNode ->ToElement();
			string rootName = rootElement ->Name();
			string attributeName;
			string elementName;
			tinyxml2::XMLElement *currentElement;

			//Search through file
			for (int i = 0; i<numElements; i++)
			{
				if (currentNode == NULL)
				{
					string strAttr4 = "hi"; //do nothing
				}
				else
				{
					//Convert to element
					currentElement = currentNode ->ToElement();
	
					 elementName = currentElement ->Name();
					//get attribute
					 if (elementName == choice)
					 {
						 break;
					 }
					 else
					 {
						currentNode = currentNode ->NextSibling();
					 }
				}
				
			}

			//Change attribute strings back to compatible type for the numeric up down and combo boxes
			maxFrequencyUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("MaxFrequency"));
			minFrequencyUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("MinFrequency"));
			numberOfSweepsUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("NumOfSweeps"));
			sweepDelayUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("DelayBetweenSweeps"));
			stepsPerSweepUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("StepsPerSweep"));
			samplesPerStepUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("SamplesPerStep"));
			numericUpDown7->Text = marshal_as<System::String^>(currentElement ->Attribute("Gain"));
			comboBox2->Text = marshal_as<System::String^>(currentElement ->Attribute("LaserDiodePattern"));

			//delete context
			delete context;
		 }
};

}