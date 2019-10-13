#pragma once

#include "..\MyForm\MyForm.h"
#include "..\VideoForm\VideoForm.h"
#include "Main.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	//private: Form^ f1;
	public:
		Main(void)
		{
			InitializeComponent();
			//this->f1 = f1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:

	private: System::Windows::Forms::Button^  button3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(284, 311);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Image ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(416, 86);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(269, 311);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Video";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 537);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			
		

		}

		
		
#pragma endregion
		//img
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
			this->Hide();
			Project2::MyForm form;
			form.ShowDialog();
			this->Show();
		}
			 //video
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Hide();
			Project2::VideoForm form;
			form.ShowDialog();
			this->Show();

		}
	
	};
}
