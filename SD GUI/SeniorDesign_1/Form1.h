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
#include "ManageProfiles.h"
//for timer
#include <cstdio>
#include <ctime>




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
		SimultaneousPattern^ SPwin;
		Warning_DateandPatientName^ ConnectError;
		ManageProfiles^ MPwin;
		int SimFlag; //simultaneous flag
		//Make public variable so graph can be cleared later
		GraphPane ^myPane;
		//Make controls public variables
		
		const char* ProfileName;
		const char* stepSize; //maxFrequency
		const char* minFrequency;
		const char* numOfSweeps;
		const char* delayBetweenSweeps;
		const char* stepsPerSweep;
		const char* samplesPerStep;
		//const char* gain;
		const char* laserDiodePattern;
		const char* Sim_Diode1;
		const char* Sim_Diode2;
		const char* Sim_Diode3;
		const char* Sim_Diode4;
		const char* Sim_Diode5;
		const char* Sim_Diode6;
		int checkFlag;
		int incnum;
	private: System::Windows::Forms::SplitContainer^  splitContainer4;
	public: 
	private: System::Windows::Forms::Button^  button11;
	private: ZedGraph::ZedGraphControl^  zedGraphControl2;
	private: ZedGraph::ZedGraphControl^  zedGraphControl3;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  profileManagerButton;
	private: System::Windows::Forms::Label^  labelSaveName;

	public: 
		int numElements; //number of elements in the file
		Form1(void)
		{
			InitializeComponent();
			
			myPane = zedGraphControl1->GraphPane;
			//SPwin = gcnew SimultaneousPattern();
			//Count the number of elements in the file when it opens
			myPane->Title->Text = "Voltage vs Time";
			myPane->XAxis->Title->Text = "Time (s)";
			myPane->YAxis->Title->Text = "Voltage (V)";
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile("C:\\Users\\CME\\Desktop\\ProfileName.xml");
			tinyxml2::XMLNode *currentNode_0 = xmlDoc.FirstChild();
			tinyxml2::XMLElement *currentElement_0;
			SimFlag = 0; //initialize to 0
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
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->zedGraphControl2 = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphControl3 = (gcnew ZedGraph::ZedGraphControl());
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
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer4))->BeginInit();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
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
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->splitContainer4);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(800, 526);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Graphs/Post Processing";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// splitContainer4
			// 
			this->splitContainer4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer4->Location = System::Drawing::Point(3, 3);
			this->splitContainer4->Name = L"splitContainer4";
			this->splitContainer4->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer4.Panel1
			// 
			this->splitContainer4->Panel1->Controls->Add(this->button11);
			this->splitContainer4->Panel1->Controls->Add(this->zedGraphControl2);
			// 
			// splitContainer4.Panel2
			// 
			this->splitContainer4->Panel2->Controls->Add(this->zedGraphControl3);
			this->splitContainer4->Size = System::Drawing::Size(794, 520);
			this->splitContainer4->SplitterDistance = 251;
			this->splitContainer4->TabIndex = 0;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(5, 43);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 23);
			this->button11->TabIndex = 1;
			this->button11->Text = L"Test";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// zedGraphControl2
			// 
			this->zedGraphControl2->Dock = System::Windows::Forms::DockStyle::Right;
			this->zedGraphControl2->Location = System::Drawing::Point(200, 0);
			this->zedGraphControl2->Name = L"zedGraphControl2";
			this->zedGraphControl2->ScrollGrace = 0;
			this->zedGraphControl2->ScrollMaxX = 0;
			this->zedGraphControl2->ScrollMaxY = 0;
			this->zedGraphControl2->ScrollMaxY2 = 0;
			this->zedGraphControl2->ScrollMinX = 0;
			this->zedGraphControl2->ScrollMinY = 0;
			this->zedGraphControl2->ScrollMinY2 = 0;
			this->zedGraphControl2->Size = System::Drawing::Size(594, 251);
			this->zedGraphControl2->TabIndex = 0;
			// 
			// zedGraphControl3
			// 
			this->zedGraphControl3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphControl3->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl3->Name = L"zedGraphControl3";
			this->zedGraphControl3->ScrollGrace = 0;
			this->zedGraphControl3->ScrollMaxX = 0;
			this->zedGraphControl3->ScrollMaxY = 0;
			this->zedGraphControl3->ScrollMaxY2 = 0;
			this->zedGraphControl3->ScrollMinX = 0;
			this->zedGraphControl3->ScrollMinY = 0;
			this->zedGraphControl3->ScrollMinY2 = 0;
			this->zedGraphControl3->Size = System::Drawing::Size(794, 265);
			this->zedGraphControl3->TabIndex = 0;
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
			this->splitContainer1->SplitterMoved += gcnew System::Windows::Forms::SplitterEventHandler(this, &Form1::splitContainer1_SplitterMoved);
			// 
			// labelSaveName
			// 
			this->labelSaveName->AutoSize = true;
			this->labelSaveName->Location = System::Drawing::Point(381, 61);
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
			this->textBox2->Text = L"test";
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
			this->textBox1->Text = L"C:\\Users\\CME\\Desktop";
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
			this->splitContainer2->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer2_Panel1_Paint);
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
			this->profileManagerButton->Location = System::Drawing::Point(18, 328);
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
			this->saveButton->Location = System::Drawing::Point(121, 328);
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
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(808, 552);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainer3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(800, 526);
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
			this->splitContainer3->Size = System::Drawing::Size(794, 520);
			this->splitContainer3->SplitterDistance = 336;
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
			this->numericUpDown7->Size = System::Drawing::Size(164, 20);
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
			this->numericUpDown1->Size = System::Drawing::Size(164, 20);
			this->numericUpDown1->TabIndex = 36;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown2->Location = System::Drawing::Point(118, 197);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(164, 20);
			this->numericUpDown2->TabIndex = 35;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown3->Location = System::Drawing::Point(148, 164);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(164, 20);
			this->numericUpDown3->TabIndex = 34;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown4->Location = System::Drawing::Point(118, 120);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(164, 20);
			this->numericUpDown4->TabIndex = 33;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown5->Location = System::Drawing::Point(118, 81);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(164, 20);
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
			this->numericUpDown6->Size = System::Drawing::Size(164, 20);
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(808, 552);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabPage3->ResumeLayout(false);
			this->splitContainer4->Panel1->ResumeLayout(false);
			this->splitContainer4->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer4))->EndInit();
			this->splitContainer4->ResumeLayout(false);
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

private: void CreateGraph( ZedGraphControl ^zgc, int recvBytes ){
		//UNCOMMENT THIS IF PROBLEM//GraphPane ^myPane = zgc->GraphPane;

		// Set the titles and axis labels
			 /*
		myPane->Title->Text = "Voltage vs Time";
		myPane->XAxis->Title->Text = "Time (s)";
		myPane->YAxis->Title->Text = "Voltage (V)";
		*/

	   double tickStart = Environment::TickCount;


			 PointPairList ^ChannelA = gcnew PointPairList();
			 PointPairList ^ChannelB = gcnew PointPairList();
			 ifstream inFile;
			 ofstream outFile;
			 //For metadata file
			 ofstream outFile_Meta;
			 inFile.open("fwrite_test", ios::in | ios::binary);
			 std::string outFilePath = marshal_as<std::string>(textBox1->Text);
			 std::string PatientName = marshal_as<std::string>(textBox2->Text);
			 std::string Date = marshal_as<std::string>(textBox4->Text);
			 std::string outFileComplete = outFilePath + "\\" + PatientName + Date + ".csv";
			 //Create metadata file
			 std::string outFileMetadata = outFilePath + "\\" + PatientName + Date + "_SettingInfo.csv";
			  int16_t data;
			  LineItem ^myCurve1 = myPane->AddCurve("Channel A", ChannelA, Color::Blue, SymbolType::Diamond);
			  LineItem ^myCurve2 = myPane->AddCurve("Channel B", ChannelB, Color::Red, SymbolType::Diamond);

			  int count = 0;
			  int count2 = 0;
			  int16_t SE_data1;
			  int16_t SE_data2;
			
			  outFile.open(outFileComplete);

			  while(inFile.read((char *)&data, sizeof(int16_t))) 
			 {
				  
				  SE_data1 = data << 2;
				  SE_data2 = SE_data1 >> 2;
				//  data = data << 2; 
				//  data = data >> 2;
				  count++;
				 if (count%2 == 0)
				 {
					  //UNCOMMENT
					 if (checkFlag == 0)
					 {
						ChannelB->Add((count2/250000000.0), data);// (float)SE_data2/4096);
					 }
					 outFile << SE_data2 << endl;
					 count2++;
				 }
				 else
				 {
					 //UNCOMMENT
					if (checkFlag == 0)
					{
						ChannelA->Add((count2/250000000.0), data);// (float)SE_data2/4096); 
					}
					outFile << SE_data2 << ",";
				 }
				 
				 //if(count %100 == 0)
				 //{
				 ////UNCOMMENT
				 //zgc->AxisChange();
				 //zgc->Refresh();
				 //}
			  } //WHILE LOOP ENDS HERE
				zgc->AxisChange();
				zgc->Refresh();
			outFile.close();
			inFile.close();
			count = 0;

			//Write to metadata file

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
			int currentStartRow = 0;
			int currentEndRow = intSamplesPerStepValue/2 -1;
			
			//Write to Metadata file
			for (int i = 0; i < intStepNumValue; i++)
			{
				//currentFreq = prevFreq + intStepSizeValue;
				outFile_Meta << "FREQUENCY: " << currentFreq << " Start: " << currentStartRow << " End: " << currentEndRow << endl;
			    currentStartRow = currentStartRow + intSamplesPerStepValue/2;
				currentEndRow = currentStartRow + intSamplesPerStepValue/2 - 1;
				prevFreq = currentFreq;// + intStepSizeValue;
				currentFreq = prevFreq + intStepSizeValue;
			}

			//Close Metadata file
			outFile_Meta.close();
			

		 }
		 //button1 name change to startButton
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Send all controls
			 marshal_context ^ context = gcnew marshal_context();
			//Make connection to server
			 int connectFail = DsauClient::mkConnection("192.168.1.10");
			 //start clock
			 std::clock_t start;
			 double duration;
			 
			 //Is the plotting functionality turned off?
			 if (this-> checkBox2-> Checked)
			 {
				 checkFlag = 1;
			 }
			 else
			 {
				 checkFlag = 0;
			incnum++;
			labelSaveName->Text = "File will be saved as: " + textBox2->Text + textBox4->Text + "_" + incnum.ToString() + ".csv";

			 }
			 if (connectFail == 1)
			 {
				 ConnectError = gcnew Warning_DateandPatientName();
				 ConnectError->setErrorMessage("Unable to Connect to Server");
				 ConnectError->Show();
			 }
			 start = std::clock();
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
			 if (strcmp(laserDiodePattern, "Simultaneous") == 0)
			 {
				DsauClient::sendThis(LDP.append("1").append("fffff ")); //Simultaneous = 1
			 }
			 else
			 {
				 DsauClient::sendThis(LDP.append("2").append("fffff ")); //Sequential = 2
			 }
			 //DsauClient::rmConnection();
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
			
			 myPane->CurveList->Clear();
 			 string msgtype="s";
			 //string caddr= "192.168.1.10";
			 //DsauClient::mkConnection(caddr);
			 DsauClient::sendThis(msgtype);

			 int recvBytes = DsauClient::recvThis();
			 duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
			 CreateGraph(zedGraphControl1, recvBytes);
			 DsauClient::rmConnection();
			 //Get the timer value and display it on the GUI
			 
			 //convert from double to string
			 std::ostringstream durationVal;
			 durationVal << duration;
			 std::string strDurationVal = durationVal.str();
			 //convert from std::string to String^ 
			 String^ dur = context->marshal_as<String ^>(strDurationVal);
			 this->textBox5->Text = dur;
			 ofstream TimeFile;

			 std::string outFilePath = marshal_as<std::string>(textBox1->Text);
			 std::string outFileComplete = outFilePath + "\\" + "Times.csv";
			 TimeFile.open(outFileComplete, ios::out | ios::app);
			 TimeFile << duration << ","<< (int)stepSizeUpDown->Value << "," << (int)(samplesPerStepUpDown->Value) << endl;
			 TimeFile.close();

			//incnum++;
			//labelSaveName->Text = "File will be saved as: " + textBox2->Text + textBox4->Text + "_" + incnum.ToString() + ".csv";


		 }

private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
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

			 //create Pop-Up Window
			 pnw = gcnew ProfileNameWindow(stepSize, minFrequency, numOfSweeps, delayBetweenSweeps, stepsPerSweep, samplesPerStep, laserDiodePattern, profileNameCB, numElements);
			 //have PopUp window show up
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
			stepSizeUpDown->Text = marshal_as<System::String^>(currentElement ->Attribute("stepSize"));
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
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {

}

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
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
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
private: System::Void splitContainer2_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void profileManagerButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 marshal_context ^ context = gcnew marshal_context();
			 
//			 MPwin = gcnew ManageProfiles(numElements);//create Pop-Up Window
//			 MPwin->Show();//have PopUp window show up
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
						xmlDoc.DeleteNode(currentNode);
						profileNameCB->Items->Remove((profileNameCB->Text));
						numElements--;
						 break;
					 }
					 else
					 {
						currentNode = currentNode ->NextSibling();
					 }
				}
				
			}

			//delete context
			delete context;			
			xmlDoc.SaveFile("C:\\Users\\CME\\Desktop\\ProfileName.xml");
			
			
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			labelSaveName->Text = "File will be saved as: " + textBox2->Text + textBox4->Text + ".csv";

		 }
private: System::Void splitContainer1_SplitterMoved(System::Object^  sender, System::Windows::Forms::SplitterEventArgs^  e) {
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			labelSaveName->Text = "File will be saved as: " + textBox2->Text + textBox4->Text + ".csv";

		 }
};

}

