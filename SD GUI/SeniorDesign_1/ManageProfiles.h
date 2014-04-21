#pragma once
#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <string>


#include <stdlib.h>
#include "msclr\marshal_cppstd.h"
#include "ProfileNameWindow.h"
#include "Warning_DateandPatientName.h"
#include <stdint.h>

namespace SeniorDesign_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace tinyxml2;
	using namespace std;
	/// <summary>
	/// Summary for ManageProfiles
	/// </summary>
	public ref class ManageProfiles : public System::Windows::Forms::Form
	{
	public:
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
		int numElements_pnw;
		ManageProfiles(int numElementsIn)
		{
			InitializeComponent();
			//
			numElements_pnw = numElementsIn;
			//TODO: Add the constructor code here
				marshal_context ^ context = gcnew marshal_context();
		//	const char* choice = context->marshal_as<const char*>(listBox1->SelectedValue);
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile("C:\\Users\\Yan Zhang\\Desktop\\ProfileName.xml");
			tinyxml2::XMLNode *currentNode = xmlDoc.FirstChild();
			tinyxml2::XMLElement *rootElement= currentNode ->ToElement();
			string rootName = rootElement ->Name();
			string attributeName;
			string elementName;
			tinyxml2::XMLElement *currentElement;

			//Search through file
			for (int i = 0; i<numElements_pnw; i++)
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
					listBox1->Items->Add(marshal_as<System::String^>(elementName));
					//get attribute
						currentNode = currentNode ->NextSibling();
					 
				}
				
			}
			delete context;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ManageProfiles()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  removeButton;
	private: System::Windows::Forms::Label^  labelFrequency;
	private: System::Windows::Forms::Label^  labelStepSize;
	private: System::Windows::Forms::Label^  labelSteps;
	private: System::Windows::Forms::Label^  labelSampleSize;
	private: System::Windows::Forms::Label^  labelNumSweeps;
	private: System::Windows::Forms::Label^  labelDelay;






	protected: 

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->removeButton = (gcnew System::Windows::Forms::Button());
			this->labelFrequency = (gcnew System::Windows::Forms::Label());
			this->labelStepSize = (gcnew System::Windows::Forms::Label());
			this->labelSteps = (gcnew System::Windows::Forms::Label());
			this->labelSampleSize = (gcnew System::Windows::Forms::Label());
			this->labelNumSweeps = (gcnew System::Windows::Forms::Label());
			this->labelDelay = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(129, 134);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ManageProfiles::listBox1_SelectedIndexChanged);
			// 
			// removeButton
			// 
			this->removeButton->Location = System::Drawing::Point(26, 149);
			this->removeButton->Name = L"removeButton";
			this->removeButton->Size = System::Drawing::Size(75, 23);
			this->removeButton->TabIndex = 1;
			this->removeButton->Text = L"Remove Profile";
			this->removeButton->UseVisualStyleBackColor = true;
			this->removeButton->Click += gcnew System::EventHandler(this, &ManageProfiles::removeButton_Click);
			// 
			// labelFrequency
			// 
			this->labelFrequency->AutoSize = true;
			this->labelFrequency->Location = System::Drawing::Point(169, 26);
			this->labelFrequency->Name = L"labelFrequency";
			this->labelFrequency->Size = System::Drawing::Size(82, 13);
			this->labelFrequency->TabIndex = 2;
			this->labelFrequency->Text = L"Start Frequency";
			// 
			// labelStepSize
			// 
			this->labelStepSize->AutoSize = true;
			this->labelStepSize->Location = System::Drawing::Point(169, 44);
			this->labelStepSize->Name = L"labelStepSize";
			this->labelStepSize->Size = System::Drawing::Size(52, 13);
			this->labelStepSize->TabIndex = 3;
			this->labelStepSize->Text = L"Step Size";
			// 
			// labelSteps
			// 
			this->labelSteps->AutoSize = true;
			this->labelSteps->Location = System::Drawing::Point(169, 59);
			this->labelSteps->Name = L"labelSteps";
			this->labelSteps->Size = System::Drawing::Size(34, 13);
			this->labelSteps->TabIndex = 4;
			this->labelSteps->Text = L"Steps";
			// 
			// labelSampleSize
			// 
			this->labelSampleSize->AutoSize = true;
			this->labelSampleSize->Location = System::Drawing::Point(169, 74);
			this->labelSampleSize->Name = L"labelSampleSize";
			this->labelSampleSize->Size = System::Drawing::Size(65, 13);
			this->labelSampleSize->TabIndex = 5;
			this->labelSampleSize->Text = L"Sample Size";
			// 
			// labelNumSweeps
			// 
			this->labelNumSweeps->AutoSize = true;
			this->labelNumSweeps->Location = System::Drawing::Point(169, 91);
			this->labelNumSweeps->Name = L"labelNumSweeps";
			this->labelNumSweeps->Size = System::Drawing::Size(67, 13);
			this->labelNumSweeps->TabIndex = 6;
			this->labelNumSweeps->Text = L"# of Sweeps";
			// 
			// labelDelay
			// 
			this->labelDelay->AutoSize = true;
			this->labelDelay->Location = System::Drawing::Point(169, 107);
			this->labelDelay->Name = L"labelDelay";
			this->labelDelay->Size = System::Drawing::Size(119, 13);
			this->labelDelay->TabIndex = 7;
			this->labelDelay->Text = L"Delay between Sweeps";
			// 
			// ManageProfiles
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 277);
			this->Controls->Add(this->labelDelay);
			this->Controls->Add(this->labelNumSweeps);
			this->Controls->Add(this->labelSampleSize);
			this->Controls->Add(this->labelSteps);
			this->Controls->Add(this->labelStepSize);
			this->Controls->Add(this->labelFrequency);
			this->Controls->Add(this->removeButton);
			this->Controls->Add(this->listBox1);
			this->Name = L"ManageProfiles";
			this->Text = L"ManageProfiles";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	marshal_context ^ context = gcnew marshal_context();
		//	const char* choice = context->marshal_as<const char*>(listBox1->SelectedValue);
			string choice = context->marshal_as<string>(listBox1->SelectedItem->ToString());
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile("C:\\Users\\Yan Zhang\\Desktop\\ProfileName.xml");
			tinyxml2::XMLNode *currentNode = xmlDoc.FirstChild();
			tinyxml2::XMLElement *rootElement= currentNode ->ToElement();
			string rootName = rootElement ->Name();
			string attributeName;
			string elementName;
			tinyxml2::XMLElement *currentElement;

			//Search through file
			for (int i = 0; i<numElements_pnw; i++)
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


			////Change attribute strings back to compatible type for the numeric up down and combo boxes

			labelStepSize->Text = "Step Size:" + marshal_as<System::String^>(currentElement ->Attribute("stepSize"));
			labelFrequency->Text ="Frequency:" + marshal_as<System::String^>(currentElement ->Attribute("MinFrequency"));
			labelNumSweeps->Text ="Number of Sweeps:" +  marshal_as<System::String^>(currentElement ->Attribute("NumOfSweeps"));
			labelDelay->Text = "Delay:" + marshal_as<System::String^>(currentElement ->Attribute("DelayBetweenSweeps"));
			labelSteps->Text ="Steps:" +  marshal_as<System::String^>(currentElement ->Attribute("StepsPerSweep"));
			labelSampleSize->Text ="Sample Size:" +  marshal_as<System::String^>(currentElement ->Attribute("SamplesPerStep"));

			//delete context
			delete context;			
			 
			 
			 
			 }
private: System::Void removeButton_Click(System::Object^  sender, System::EventArgs^  e) {


	marshal_context ^ context = gcnew marshal_context();
		string choice = context->marshal_as<string>(listBox1->SelectedItem->ToString());
			tinyxml2::XMLDocument xmlDoc;
			xmlDoc.LoadFile("C:\\Users\\Yan Zhang\\Desktop\\ProfileName.xml");
			tinyxml2::XMLNode *currentNode = xmlDoc.FirstChild();
			tinyxml2::XMLElement *rootElement= currentNode ->ToElement();
			string rootName = rootElement ->Name();
			string attributeName;
			string elementName;
			tinyxml2::XMLElement *currentElement;

			//Search through file
			for (int i = 0; i<numElements_pnw; i++)
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
					//	listBox1->Items->Remove(marshal_as<System::String^>(elementName));
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
			xmlDoc.SaveFile("C:\\Users\\Yan Zhang\\Desktop\\ProfileName.xml");
		 }
};
}
