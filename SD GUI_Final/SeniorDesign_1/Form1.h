#pragma once

#include <stdlib.h>
#include "Client.h" 
#include <fstream>
#include <string>
#include <iostream>
#include "msclr\marshal_cppstd.h"
#include <string>
#include <queue>
#include "tinyxml2.h"
#include "ProfileNameWindow.h"
#include "Warning_DateandPatientName.h"
#include "SimultaneousPattern.h"
#include <stdint.h>
#include <sstream>
#include <cstdio>
#include <ctime>

#define XMLPATH "C:\\Users\\CME\\Desktop\\ProfileName.xml"
#define IPADDRESS "192.168.1.10"


namespace SeniorDesign_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop; //For marshalling
	using namespace ZedGraph; //Graphing
	using namespace std;
	using namespace tinyxml2;
	using namespace ClientDll;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		ProfileNameWindow^ pnw; //Pop Up Window for entering profile naming
		SimultaneousPattern^ SPwin; //Pop Up Window for enter offsets for simultaneous pattern
		Warning_DateandPatientName^ ConnectError; //Error window for being unable to connect to the server
		int SimFlag; //Indicates whether the user chose the simultaneous laser diode pattern or the simultaneous laser pattern
		GraphPane ^myPane; //Graph for plotting incoming data
		//Declare all of the controls that the user enters as public variables
		const char* ProfileName;
		const char* stepSize; 
		const char* minFrequency;
		const char* numOfSweeps;
		const char* delayBetweenSweeps;
		const char* stepsPerSweep;
		const char* samplesPerStep;
		const char* laserDiodePattern;
		//Sim_Diode1 through Sim_Diode6 will only be used if the user selects a simultaneous diode pattern
		const char* Sim_Diode1;
		const char* Sim_Diode2;
		const char* Sim_Diode3;
		const char* Sim_Diode4;
		const char* Sim_Diode5;
		const char* Sim_Diode6;
		int checkFlag; //This flag will indicate whether or not the checkbox for the graphng functionality has been checked or not
		int fileInc; //Will keep track of the file naming increment functionality


	public: 



	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  profileManagerButton;
	private: System::Windows::Forms::Label^  labelSaveName;

	public: 
		int numElements; //Keeps track of the number of profile names in the ProfileName XML File
		Form1(void)
		{
			InitializeComponent();

			//Set up the graph with the correct axes and title
			myPane = zedGraphControl1->GraphPane;
			myPane->Title->Text = "Voltage vs Time";
			myPane->XAxis->Title->Text = "Time (s)";
			myPane->YAxis->Title->Text = "Voltage (V)";

			//Open the XML file that holds the profile names
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile(XMLPATH);
			//Get the first profile name
			tinyxml2::XMLNode *currentNode_0 = xmlDoc.FirstChild();
			tinyxml2::XMLElement *currentElement_0;

			SimFlag = 0; //Initialize flag to 0 (means the simultaneous laser diode pattern was not selected)
			string elementName_0;
			String^ elementNameSysString_0;
			numElements = 0;
			fileInc = 0; //Initialize the File Incrementing value to 0

			//This while loop searches through the XML file that holds the profile names and populate the drop down menu
			while(currentNode_0 != NULL)
			{
				numElements++;
				currentElement_0 = currentNode_0 ->ToElement();
				elementName_0 = currentElement_0 -> Name();
				elementNameSysString_0 = marshal_as<System::String^> (elementName_0);
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

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  button6;

	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;

	private: System::Windows::Forms::NumericUpDown^  samplesPerStepUpDown;
	private: System::Windows::Forms::NumericUpDown^  stepsPerSweepUpDown;
	private: System::Windows::Forms::NumericUpDown^  sweepDelayUpDown;
	private: System::Windows::Forms::NumericUpDown^  numberOfSweepsUpDown;
	private: System::Windows::Forms::NumericUpDown^  minFrequencyUpDown;
private: System::Windows::Forms::NumericUpDown^  stepSizeUpDown;


	private: System::Windows::Forms::Button^  saveButton;
	public: System::Windows::Forms::ComboBox^  profileNameCB;
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































private: System::Windows::Forms::Label^  label22;


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
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->labelSaveName = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->profileManagerButton = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->samplesPerStepUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->stepsPerSweepUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->sweepDelayUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->numberOfSweepsUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->minFrequencyUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->stepSizeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepSizeUpDown))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// saveFileDialog1
			// 
//			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->splitContainer1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(800, 526);
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
			this->splitContainer1->Panel1->Controls->Add(this->labelSaveName);
			this->splitContainer1->Panel1->Controls->Add(this->textBox4);
			this->splitContainer1->Panel1->Controls->Add(this->label23);
			this->splitContainer1->Panel1->Controls->Add(this->textBox2);
			this->splitContainer1->Panel1->Controls->Add(this->label9);
			this->splitContainer1->Panel1->Controls->Add(this->button6);
			this->splitContainer1->Panel1->Controls->Add(this->textBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label8);
			this->splitContainer1->Panel1->Controls->Add(this->startButton);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(794, 520);
			this->splitContainer1->SplitterDistance = 86;
			this->splitContainer1->TabIndex = 0;
			// 
			// labelSaveName
			// 
			this->labelSaveName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->labelSaveName->AutoSize = true;
			this->labelSaveName->Location = System::Drawing::Point(535, 63);
			this->labelSaveName->Name = L"labelSaveName";
			this->labelSaveName->Size = System::Drawing::Size(107, 13);
			this->labelSaveName->TabIndex = 12;
			this->labelSaveName->Text = L"File will be saved as: ";
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->Location = System::Drawing::Point(613, 10);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(176, 20);
			this->textBox4->TabIndex = 1;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// label23
			// 
			this->label23->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(574, 10);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(33, 13);
			this->label23->TabIndex = 11;
			this->label23->Text = L"Date:";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(360, 7);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(198, 20);
			this->textBox2->TabIndex = 0;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(280, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(74, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Patient Name:";
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button6->Location = System::Drawing::Point(761, 40);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(28, 20);
			this->button6->TabIndex = 8;
			this->button6->Text = L"...";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(495, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(269, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(368, 42);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(117, 13);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Output will be saved in:";
			// 
			// startButton
			// 
			this->startButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->startButton->Location = System::Drawing::Point(0, 0);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(133, 86);
			this->startButton->TabIndex = 3;
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
			this->splitContainer2->Panel1->Controls->Add(this->profileManagerButton);
			this->splitContainer2->Panel1->Controls->Add(this->checkBox2);
			this->splitContainer2->Panel1->Controls->Add(this->textBox5);
			this->splitContainer2->Panel1->Controls->Add(this->label21);
			this->splitContainer2->Panel1->Controls->Add(this->comboBox2);
			this->splitContainer2->Panel1->Controls->Add(this->label22);
			this->splitContainer2->Panel1->Controls->Add(this->samplesPerStepUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->stepsPerSweepUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->sweepDelayUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->numberOfSweepsUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->minFrequencyUpDown);
			this->splitContainer2->Panel1->Controls->Add(this->stepSizeUpDown);
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
//			this->splitContainer2->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer2_Panel1_Paint);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->zedGraphControl1);
			this->splitContainer2->Panel2->Controls->Add(this->button4);
			this->splitContainer2->Size = System::Drawing::Size(794, 430);
			this->splitContainer2->SplitterDistance = 351;
			this->splitContainer2->TabIndex = 0;
			// 
			// profileManagerButton
			// 
			this->profileManagerButton->Location = System::Drawing::Point(200, 334);
			this->profileManagerButton->Name = L"profileManagerButton";
			this->profileManagerButton->Size = System::Drawing::Size(91, 27);
			this->profileManagerButton->TabIndex = 29;
			this->profileManagerButton->Text = L"Delete Profile";
			this->profileManagerButton->UseVisualStyleBackColor = true;
			this->profileManagerButton->Click += gcnew System::EventHandler(this, &Form1::profileManagerButton_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(109, 398);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(103, 17);
			this->checkBox2->TabIndex = 28;
			this->checkBox2->Text = L"Turn Off Plotting";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(121, 367);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(91, 20);
			this->textBox5->TabIndex = 27;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(8, 370);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(93, 13);
			this->label21->TabIndex = 3;
			this->label21->Text = L"Time for 1 Sweep:";
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Simultaneous", L"Sequential"});
			this->comboBox2->Location = System::Drawing::Point(161, 301);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(160, 21);
			this->comboBox2->TabIndex = 7;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label22
			// 
			this->label22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(5, 301);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(104, 13);
			this->label22->TabIndex = 25;
			this->label22->Text = L"Laser Diode Pattern:";
			// 
			// samplesPerStepUpDown
			// 
			this->samplesPerStepUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->samplesPerStepUpDown->Location = System::Drawing::Point(161, 175);
			this->samplesPerStepUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->samplesPerStepUpDown->Name = L"samplesPerStepUpDown";
			this->samplesPerStepUpDown->Size = System::Drawing::Size(160, 20);
			this->samplesPerStepUpDown->TabIndex = 4;
			this->samplesPerStepUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// stepsPerSweepUpDown
			// 
			this->stepsPerSweepUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->stepsPerSweepUpDown->Location = System::Drawing::Point(161, 131);
			this->stepsPerSweepUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->stepsPerSweepUpDown->Name = L"stepsPerSweepUpDown";
			this->stepsPerSweepUpDown->Size = System::Drawing::Size(160, 20);
			this->stepsPerSweepUpDown->TabIndex = 3;
			this->stepsPerSweepUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// sweepDelayUpDown
			// 
			this->sweepDelayUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->sweepDelayUpDown->Location = System::Drawing::Point(161, 262);
			this->sweepDelayUpDown->Name = L"sweepDelayUpDown";
			this->sweepDelayUpDown->Size = System::Drawing::Size(160, 20);
			this->sweepDelayUpDown->TabIndex = 6;
			// 
			// numberOfSweepsUpDown
			// 
			this->numberOfSweepsUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numberOfSweepsUpDown->Location = System::Drawing::Point(161, 218);
			this->numberOfSweepsUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numberOfSweepsUpDown->Name = L"numberOfSweepsUpDown";
			this->numberOfSweepsUpDown->Size = System::Drawing::Size(160, 20);
			this->numberOfSweepsUpDown->TabIndex = 5;
			this->numberOfSweepsUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// minFrequencyUpDown
			// 
			this->minFrequencyUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->minFrequencyUpDown->Location = System::Drawing::Point(161, 50);
			this->minFrequencyUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {500, 0, 0, 0});
			this->minFrequencyUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->minFrequencyUpDown->Name = L"minFrequencyUpDown";
			this->minFrequencyUpDown->Size = System::Drawing::Size(160, 20);
			this->minFrequencyUpDown->TabIndex = 1;
			this->minFrequencyUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// stepSizeUpDown
			// 
			this->stepSizeUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->stepSizeUpDown->Location = System::Drawing::Point(161, 88);
			this->stepSizeUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->stepSizeUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->stepSizeUpDown->Name = L"stepSizeUpDown";
			this->stepSizeUpDown->Size = System::Drawing::Size(160, 20);
			this->stepSizeUpDown->TabIndex = 2;
			this->stepSizeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(40, 334);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(91, 27);
			this->saveButton->TabIndex = 8;
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
			this->profileNameCB->Location = System::Drawing::Point(159, 16);
			this->profileNameCB->Name = L"profileNameCB";
			this->profileNameCB->Size = System::Drawing::Size(160, 21);
			this->profileNameCB->TabIndex = 0;
			this->profileNameCB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::profileNameCB_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(5, 177);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(90, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Sample Size (kS):";
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 133);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Steps:";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 264);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(145, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Delay Between Sweeps (ms):";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 218);
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
			this->label3->Location = System::Drawing::Point(5, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(116, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Start Frequency (MHz):";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Step Size (MHz):";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 17);
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
			this->zedGraphControl1->Size = System::Drawing::Size(406, 426);
			this->zedGraphControl1->TabIndex = 2;
			// 
			// button4
			// 
			this->button4->Dock = System::Windows::Forms::DockStyle::Left;
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(29, 426);
			this->button4->TabIndex = 0;
			this->button4->Text = L"<<";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(808, 552);
			this->tabControl1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(808, 552);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"dDOSI";
//			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepSizeUpDown))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		
//button4_Click() is called every time button 4 is clicked, it creates the collapsable control menu
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Panel1 either collpases or expands based on whether the button is displaying "<<" or ">>"
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

//CreateGraph() creates graph that will be displayed in on the GUI, saves the data that is being collected to a .csv file, and creates the metadata file
private: void CreateGraph( ZedGraphControl ^zgc, int recvBytes ){

		//Create a marshal_context to convert managed types of strings to standard strings
		marshal_context ^ context = gcnew marshal_context();

		//start clock for timing data transfer
		std::clock_t start;
		double duration;
		start = std::clock();
	
	   //Intialize the strings for the file paths
	   std::string outFileComplete;
	   std::string outFileMetadata;

	   //Create PointPairLists for Channels A and B
	   PointPairList ^ChannelA = gcnew PointPairList();
	   PointPairList ^ChannelB = gcnew PointPairList();
	   
	   //inFile is for reading the binary file that contains that collected data
	   ifstream inFile;
	   //outFile will be the .csv file that the data is written to
	   ofstream outFile;
	   //outFile_Meta will be the metadata file where the information about the settings is written
	   ofstream outFile_Meta;
	   
	   //Open the binary file
	   inFile.open("fwrite_test", ios::in | ios::binary);
	   
	   //obtain strings of the file path, patient name and data information by marshalling
	   std::string outFilePath = marshal_as<std::string>(textBox1->Text);
	   std::string PatientName = marshal_as<std::string>(textBox2->Text);
	   std::string Date = marshal_as<std::string>(textBox4->Text);

	   //Increment the file name
	   fileInc++;
	   //Convert fileInc to a string so it can be added to the file name
	   string fileIncStr;
	   ostringstream convert;
	   convert << fileInc;
	   fileIncStr = convert.str();

	   if (fileInc == 0)
	   {
			 outFileComplete = outFilePath + "\\" + PatientName + Date + ".csv";
			 outFileMetadata = outFilePath + "\\" + PatientName + Date + "_SettingInfo.csv";
	   }
	   else
	   {
			 outFileComplete = outFilePath + "\\" + PatientName + Date + fileIncStr + ".csv";
			 outFileMetadata = outFilePath + "\\" + PatientName + Date + fileIncStr + "_SettingInfo.csv";
	   }

	   //Declare data variable, this variable will store the data that was collected and read in from the binary file
	   int16_t data;

	   //Create two curves, one for Channel A(blue curve) and one for Channel B(red curve)
	   LineItem ^myCurve1 = myPane->AddCurve("Channel A", ChannelA, Color::Blue, SymbolType::Diamond);
	   LineItem ^myCurve2 = myPane->AddCurve("Channel B", ChannelB, Color::Red, SymbolType::Diamond);

	   //Create two counters
	   int count = 0; 
	   int count2 = 0;

	   //SE_data1 and SE_data2 keep track of the sign extended data points
	   int16_t SE_data1;
	   int16_t SE_data2;
	
	   //Open the output file so it can be written to
	   outFile.open(outFileComplete);


	   //WRITE TO .CSV FILE
	   char bufferIn[2048];
	   char bufferOut[16384];

	   //Get the file length
	   inFile.seekg (0, inFile.end);
	   int length = inFile.tellg();
	   inFile.seekg (0, inFile.beg);
	   int topVal = (length / 2048);
	   int readSize = sizeof(bufferIn[0]);
	   int counter1=0;
	   char intString[6];
	   int16_t SE_data[1024];

	    for (int i=0; i<topVal; i++) {
				inFile.read((char*)&SE_data, 2048);
				for (int j=0; j<1024; j++) {
					SE_data[j] <<= 2;
					SE_data[j] >>= 2;
				}
				counter1=0;
				for (int j=0; j<1024; j++) {
				  count++;
				  itoa (SE_data[j], intString, 10);
				  int intLen = strlen(intString);
				  if (count%2 == 0) {
					 if (count < 8192){
						 ChannelB->Add((count2/250000000.0), (float)SE_data[j]/4096);
						 count2++;
					 }
					memcpy(&bufferOut[counter1], &intString, intLen);
					counter1+=intLen+1;
					bufferOut[counter1-1] = '\n';
				 }
				 else
				 {
					if (count < 8192)
					{
					ChannelA->Add((count2/250000000.0), (float)SE_data[j]/4096);  
					}
					memcpy(&bufferOut[counter1], &intString, intLen);
					counter1+=intLen+1;
					bufferOut[counter1-1] = ',';
				 }
				}
				bufferOut[counter1] = '\0';
				outFile << bufferOut;
			}

			zgc->AxisChange();
		    zgc->Refresh();
			outFile.close();
			inFile.close();
			count = 0;


			//WRITE TO METADATA FILE
			//Convert stepsPerSweep to int
			stringstream stepNumValue;
			stepNumValue << stepsPerSweep;
			int intStepNumValue;
			stepNumValue >> intStepNumValue;

			//Convert minFrequency to int
			stringstream minFrequencyValue;
			minFrequencyValue << minFrequency;
			int intMinFreqValue;
			minFrequencyValue >> intMinFreqValue;

			//Convert samplesPerStep to int
			stringstream samplesPerStepValue;
			samplesPerStepValue << samplesPerStep;
			int intSamplesPerStepValue;
			samplesPerStepValue >> intSamplesPerStepValue;

			//Convert stepSize to int
			stringstream stepSizeValue;
			stepSizeValue << stepSize;
			int intStepSizeValue;
			stepSizeValue >> intStepSizeValue;

			//Open Metadata file
			outFile_Meta.open(outFileMetadata);
			int prevFreq = 0 ;
			int currentFreq = intMinFreqValue;
			int currentStartRow = 1;
			int currentEndRow = intSamplesPerStepValue*1024;
			
			//Write to Metadata file
			for (int i = 0; i < intStepNumValue; i++)
			{
				//currentFreq = prevFreq + intStepSizeValue;
				outFile_Meta << "FREQUENCY: " << currentFreq << " Start: " << currentStartRow << " End: " << currentEndRow << endl;
			    currentStartRow += intSamplesPerStepValue * 1024;
				currentEndRow += intSamplesPerStepValue * 1024;
				prevFreq = currentFreq;
				currentFreq = prevFreq + intStepSizeValue;
			}

			//Close Metadata file
			outFile_Meta.close();

		//Print the time it took for the data transfer to the GUI
		std::ostringstream durationVal;
		durationVal << duration;
		std::string strDurationVal = durationVal.str();
		String^ dur = context->marshal_as<String ^>(strDurationVal);
	}

//button1_Click() sends all of the controls to the serve and sends a sweep request to the server for it to start sending data to the client
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Check to make sure the user entered a save location for the output file
			 if (this->textBox1->Text->Length == 0)//If they did not, print an error message
			 {
				 Warning_DateandPatientName^ ErrorW = gcnew Warning_DateandPatientName();
				 ErrorW->setErrorMessage("Please enter a location for the file to be saved.");
				 ErrorW->Show();
			 }
			 //Check to make sure the user entered the patient name and date
			 else if(this->textBox2->Text->Length == 0 || this->textBox4->Text->Length == 0)//If they did not, print an error message
			 {
				 Warning_DateandPatientName^ ErrorW = gcnew Warning_DateandPatientName();
				 ErrorW->setErrorMessage("Please Enter the Patient Name and Date.");
				 ErrorW->Show();
			 }
			 else //Otherwise send the request to the server to start the sweep and send the appropriate control values to the server
			 {
				 //Need marshalling to send all controls to the server
				 marshal_context ^ context = gcnew marshal_context();

				//Tray to make connection to server, Failure to connect returns value of 1
				 int connectFail = DsauClient::mkConnection(IPADDRESS);

				 //start clock
				 std::clock_t start;
				 double duration;

				 //Check to see if the plotting functionality was turned off
				 if (this-> checkBox2-> Checked)
				 {
					 checkFlag = 1; //If it was turned off set flag to 1
				 }
				 else
				 {
					 checkFlag = 0; //Otherwise set flag to 0
				 }

				 //If there was problem connecting to the server print an error message
				 if (connectFail == 1)
				 {
					 ConnectError = gcnew Warning_DateandPatientName();
					 ConnectError->setErrorMessage("Unable to Connect to Server");
					 ConnectError->Show();
				 }

				 start = std::clock();

				 //SEND THE CONTROLS TO THE SERVER
				 string SS = "wf"; 
				 //get Max. Frequency
				 stepSize = context->marshal_as<const char*>(stepSizeUpDown->Text);
				 DsauClient::sendThis(SS.append(stepSize).append("fffff "));
				 //get Min. Frequency 
				 minFrequency = context->marshal_as<const char*>(minFrequencyUpDown->Text);
				 string minF = "we";
				 DsauClient::sendThis(minF.append(minFrequency).append("fffff "));
				 //get # of sweeps
				 numOfSweeps = context->marshal_as<const char*>(numberOfSweepsUpDown->Text);
				 //string NOS(numOfSweeps);
				 string NOS = "wa";		
				 DsauClient::sendThis(NOS.append(numOfSweeps).append("fffff "));
				 //get delay between sweeps
				 delayBetweenSweeps = context->marshal_as<const char*>(sweepDelayUpDown->Text);
				 string DBS = "wd";
				 DsauClient::sendThis(DBS.append(delayBetweenSweeps).append("fffff "));
				 //get Steps/Sweep
				 stepsPerSweep = context->marshal_as<const char*>(stepsPerSweepUpDown->Text);
				 //string StepsPS(stepsPerSweep);
				 string StepsPS = "wb";
				 DsauClient::sendThis(StepsPS.append(stepsPerSweep).append("fffff "));
				 //get Samples/Ste
				 samplesPerStep = context->marshal_as<const char*>(samplesPerStepUpDown->Text);
				// string SamPS(samplesPerStep);
				 string SamPS = "wc";		
				 DsauClient::sendThis(SamPS.append(samplesPerStep).append("fffff "));
				 //get Laser Diode Pattern
				 string LDP = "wh"; 
				 laserDiodePattern= context->marshal_as<const char*>(comboBox2->Text);
				 //Determine which laser diode pattern was chosen -- Write now it does not make a difference to the server which diode pattern is chosen
				 if (strcmp(laserDiodePattern, "Simultaneous") == 0)
				 {
					DsauClient::sendThis(LDP.append("1").append("fffff ")); //Simultaneous = 1
				 }
				 else
				 {
					 DsauClient::sendThis(LDP.append("2").append("fffff ")); //Sequential = 2
				 }
			     //If Simultaneous was chosen, send the appropriate values for each laser offset to the server
				 if (SimFlag == 1)
				 {
					 string SD1 = "wi";
					 Sim_Diode1 = context->marshal_as<const char*>(SPwin->getDiode1Val());
					 DsauClient::sendThis(SD1.append(Sim_Diode1));
					 Sim_Diode2 = context->marshal_as<const char*>(SPwin->getDiode2Val());
					 string SD2 = "wj";
					 DsauClient::sendThis(SD2.append(Sim_Diode2));
					 string SD3 = "wk";
					 Sim_Diode3 = context->marshal_as<const char*>(SPwin->getDiode3Val());
					 DsauClient::sendThis(SD3.append(Sim_Diode3));
					 string SD4 = "wl";
					 Sim_Diode4 = context->marshal_as<const char*>(SPwin->getDiode4Val());
					 DsauClient::sendThis(SD4.append(Sim_Diode4));
					 string SD5 = "wm";
					 Sim_Diode5 = context->marshal_as<const char*>(SPwin->getDiode5Val());
					 DsauClient::sendThis(SD5.append(Sim_Diode5));
					 string SD6 = "wn";
					 Sim_Diode6 = context->marshal_as<const char*>(SPwin->getDiode6Val());
					 DsauClient::sendThis(SD6.append(Sim_Diode6));
				 }
			
				//Send start sweep request to server
				 myPane->CurveList->Clear();
 				 string msgtype="s";
				 DsauClient::sendThis(msgtype);

				 int recvBytes = DsauClient::recvThis();
				 duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
				 //Call CreateGraph()
				 CreateGraph(zedGraphControl1, recvBytes);
				 if (fileInc != 0)
				 {
					labelSaveName->Text = "File will be saved as: " + textBox2->Text + textBox4->Text + fileInc.ToString() + ".csv";
				 }
				 DsauClient::rmConnection();
			 
				 //convert from double to string
				 std::ostringstream durationVal;
				 durationVal << duration;
				 std::string strDurationVal = durationVal.str();
				 //CHECK THIS**********************************************************
				 //convert from std::string to String^ 
				 String^ dur = context->marshal_as<String ^>(strDurationVal);
				 this->textBox5->Text = dur;
				 ofstream TimeFile;

				 //Create file for that will contain the time it took for the various data transfers
				 std::string outFilePath = marshal_as<std::string>(textBox1->Text);
				 std::string outFileComplete = outFilePath + "\\" + "Times.csv";
				 TimeFile.open(outFileComplete, ios::out | ios::app);
				 TimeFile << duration << ","<< (int)stepSizeUpDown->Value << "," << (int)(samplesPerStepUpDown->Value) << endl;
				 TimeFile.close();
				}


		 }

//button6_Click_1() opens a directory for the users computer so that they can select a place to save the output .csv file and the metadata file
private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 //Check to make sure that user entered values in name and date field
			 //Did the user enter the Patient Name and/or Date? If not, produce an error message
			 if (this->textBox2->Text->Length == 0 || this->textBox4->Text->Length == 0)
			 {
				 Warning_DateandPatientName^ ErrorW = gcnew Warning_DateandPatientName();
				 ErrorW->setErrorMessage("Please Enter the Patient Name and Date.");
				 ErrorW->Show();
			 }
			 else
			 {
				//Check to make sure Date and Patient name contain appropriate characters
				std::string PatientName_Check = marshal_as<std::string>(textBox2->Text);
				std::string Date_Check = marshal_as<std::string>(textBox4->Text);
				 //If there are no backslashes or forward slashes proceed
				 if (Date_Check.find("\\") == std::string::npos && Date_Check.find("/") == std::string::npos && PatientName_Check.find("\\") == string::npos && PatientName_Check.find("/") == string::npos)
				 {
					folderBrowserDialog1->ShowDialog();
					textBox1->Text= folderBrowserDialog1->SelectedPath;
				 }
				 else //otherwise generate error window
				 {
					 Warning_DateandPatientName^ ErrorW = gcnew Warning_DateandPatientName();
					 ErrorW->setErrorMessage("The Date and Patient Name fields cannot contain forward slashes or back slashes");
					 ErrorW->Show();
				 }
			 }
		 }

//saveButton_Click() will make a Pop Up window show up which will allow the user to enter the profile name they would like to save the parameter values under
private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			  marshal_context ^ context = gcnew marshal_context();
			  //increase the number of elements
			  numElements++;
			 //get Max. Frequency
			  stepSize = context->marshal_as<const char*>(stepSizeUpDown->Text);
			 //get Min. Frequency
			  minFrequency = context->marshal_as<const char*>(minFrequencyUpDown->Text);
			 //get # of sweeps
			  numOfSweeps = context->marshal_as<const char*>(numberOfSweepsUpDown->Text);
			 //get delay between sweeps
			  delayBetweenSweeps = context->marshal_as<const char*>(sweepDelayUpDown->Text);
			 //get Steps/Sweep 
			  stepsPerSweep = context->marshal_as<const char*>(stepsPerSweepUpDown->Text);
			 //get Samples/Step
			  samplesPerStep = context->marshal_as<const char*>(samplesPerStepUpDown->Text);
			 //get Laser Diode Pattern
			  laserDiodePattern = context->marshal_as<const char*>(comboBox2->Text);

			 //create Pop-Up Window and send it the appropriate controls so that the information can be saved to the ProfileName.XML file
			 pnw = gcnew ProfileNameWindow(stepSize, minFrequency, numOfSweeps, delayBetweenSweeps, stepsPerSweep, samplesPerStep, laserDiodePattern, profileNameCB, numElements);
			 //have PopUp window show up
			 pnw->Show();

		 }


//profileNameCB_SelectedIndexChanged() will update the appropriate fields whenever the profile name in the combobox is changed
private: System::Void profileNameCB_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			marshal_context ^ context = gcnew marshal_context();

			//Get the name from the ComboBox after it is changed
			const char* choice = context->marshal_as<const char*>(profileNameCB->Text); 
			tinyxml2::XMLDocument xmlDoc;

			//Open the XML file
			xmlDoc.LoadFile(XMLPATH);
			tinyxml2::XMLNode *currentNode = xmlDoc.FirstChild();
			tinyxml2::XMLElement *rootElement= currentNode ->ToElement();
			//get the first Profile Name
			string rootName = rootElement ->Name();
			string attributeName;
			string elementName;
			tinyxml2::XMLElement *currentElement;

			//Search through file
			for (int i = 0; i<numElements; i++)
			{
				if (currentNode == NULL) //indicates that you are at the end of the file
				{
					//do nothing
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
			stepSizeUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("stepSize"));
			minFrequencyUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("MinFrequency"));
			numberOfSweepsUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("NumOfSweeps"));
			sweepDelayUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("DelayBetweenSweeps"));
			stepsPerSweepUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("StepsPerSweep"));
			samplesPerStepUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("SamplesPerStep"));
			comboBox2->Text = marshal_as<System::String^>(currentElement ->Attribute("LaserDiodePattern"));

			//delete context
			delete context;
		 }

//comboBox2_SelectedIndexChanged() checks to see what the user entered for the laserDiodePattern and consequently changes simFlag
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 String^ PatternChoice = comboBox2->Text;
			 marshal_context ^ context = gcnew marshal_context();
			 SPwin = gcnew SimultaneousPattern();
			 const char* LDPChoice = context->marshal_as<const char*>(PatternChoice); 
			 if (strcmp(LDPChoice, "Simultaneous") == 0)
			 {
				 SPwin->Show();
				 SimFlag = 1; //Simultaneous chosen, set flag to 1
			 }
			 else
			 {
				 SimFlag = 0;//Simultaneous NOT chosen, set flag to 0
			 }

		 }

//profileManagerButton_Click() deletes the profile name that is selected in the profileNameCB comboBox
private: System::Void profileManagerButton_Click(System::Object^  sender, System::EventArgs^  e) {

			marshal_context ^ context = gcnew marshal_context();
			 
			//Save the profile name that the user selected to delete
	     	const char* choice = context->marshal_as<const char*>(profileNameCB->Text); 

			//Open the XML file
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile(XMLPATH);
			tinyxml2::XMLNode *currentNode = xmlDoc.FirstChild();
			tinyxml2::XMLElement *rootElement= currentNode ->ToElement();
			string rootName = rootElement ->Name();
			string attributeName;
			string elementName;
			tinyxml2::XMLElement *currentElement;

			//Search through file to find the appropriate file name
			for (int i = 0; i<numElements; i++)
			{
				if (currentNode == NULL) //indicates that we are at the end of the file
				{
					 //do nothing
				}
				else
				{
					//Convert to element
					currentElement = currentNode ->ToElement();
	
					 elementName = currentElement ->Name();
					//get attribute
					 if (elementName == choice)//if the element is found delete it
					 {
						xmlDoc.DeleteNode(currentNode);
						profileNameCB->Items->Remove((profileNameCB->Text));
						numElements--;
						break;
					 }
					 else //otherwise keep searching
					 {
						currentNode = currentNode ->NextSibling();
					 }
				}
				
			}

			//delete context
			delete context;	
			//Save the XML file after deleting the profile
			xmlDoc.SaveFile(XMLPATH);
			
			
		 }

//textBox2_TextChanged() will update the File will be saved as: field whenever the user changes the patient name field
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {	
				//reset the fileInc to 0
				fileInc = 0;
				labelSaveName->Text = "File will be saved as: " + textBox2->Text + textBox4->Text + ".csv";

		 }

//textBox4_TextChanged() will update the File will be saved as: field whenever the user changes the date field
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 //reset the fileInc to 0
			 fileInc = 0;
			labelSaveName->Text = "File will be saved as: " + textBox2->Text + textBox4->Text + ".csv";

		 }
};

}

