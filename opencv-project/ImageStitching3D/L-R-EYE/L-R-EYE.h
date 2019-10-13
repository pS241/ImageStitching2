#pragma once

#include "Main.h"
#include "..\Header\Header.h"






MyStitcher myStitcher = MyStitcher::setters();
MyCamSet myCamSet = MyCamSet::sett();






using namespace cv;
using namespace std;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	bool** p;
	int x = -1000;
	int y = -1000;
	int  setyx[2] = {};
	int Lefteye[2] = {}; 
	int Righteye[2] = {}; 
	
	

	/// <summary>
	/// Summary for LREYE
	/// </summary>
	public ref class LREYE : public System::Windows::Forms::Form
	{
	public:
		LREYE(void)
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
		~LREYE()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
			 System::Drawing::Image^ imagee;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton11;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(19, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(557, 405);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(582, 44);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(557, 405);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(170, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(213, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Picture for Left eye";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(742, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(228, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Picture for Right eye";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(14, 487);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(223, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Choose look in X os";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(353, 487);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(224, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Choose look in Y os";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(878, 617);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(261, 107);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Show Result";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LREYE::button2_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton1->Location = System::Drawing::Point(19, 628);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(37, 17);
			this->radioButton1->TabIndex = 9;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"0°";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton2->Location = System::Drawing::Point(203, 628);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(51, 17);
			this->radioButton2->TabIndex = 10;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"180°";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton3->Location = System::Drawing::Point(116, 552);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(44, 17);
			this->radioButton3->TabIndex = 11;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"90°";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton4->Location = System::Drawing::Point(49, 575);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(44, 17);
			this->radioButton4->TabIndex = 12;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"45°";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton4_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton5->Location = System::Drawing::Point(175, 575);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(51, 17);
			this->radioButton5->TabIndex = 13;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"135°";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton5_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton6->Location = System::Drawing::Point(175, 688);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(51, 17);
			this->radioButton6->TabIndex = 14;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"225°";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton6_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton7->Location = System::Drawing::Point(109, 707);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(51, 17);
			this->radioButton7->TabIndex = 15;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"270°";
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton7_CheckedChanged);
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton8->Location = System::Drawing::Point(42, 688);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(51, 17);
			this->radioButton8->TabIndex = 16;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"315°";
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton8_CheckedChanged);
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton9->Location = System::Drawing::Point(423, 628);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(44, 17);
			this->radioButton9->TabIndex = 17;
			this->radioButton9->TabStop = true;
			this->radioButton9->Text = L"90°";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton9_CheckedChanged);
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton10->Location = System::Drawing::Point(423, 566);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(37, 17);
			this->radioButton10->TabIndex = 18;
			this->radioButton10->TabStop = true;
			this->radioButton10->Text = L"0°";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton10_CheckedChanged);
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton11->Location = System::Drawing::Point(423, 688);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(51, 17);
			this->radioButton11->TabIndex = 19;
			this->radioButton11->TabStop = true;
			this->radioButton11->Text = L"180°";
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->CheckedChanged += gcnew System::EventHandler(this, &LREYE::radioButton11_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1063, 588);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"back";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LREYE::button1_Click);
			// 
			// LREYE
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1160, 736);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton11);
			this->Controls->Add(this->radioButton10);
			this->Controls->Add(this->radioButton9);
			this->Controls->Add(this->radioButton8);
			this->Controls->Add(this->radioButton7);
			this->Controls->Add(this->radioButton6);
			this->Controls->Add(this->radioButton5);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"LREYE";
			this->Text = L"LREYE";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		//RADI BUTTONY PRE X OS
		
		//Mat setrds[2];

		private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = 0;
			//int  setx[2] = { 40,-40 };
			setyx[0] = { 40 };
			setyx[1] = { -40 };
			//p=myCamSet.outl(setx, y, x);

			//Left eye cam
			Lefteye[0] = { 1 };
			Lefteye[1] = { 1 };

			//right eye cam
			Righteye[0] = { 5 };
			Righteye[1] = { 5 };

		}


		private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = 45;
			//int  setx[2] = { 85,5 };
			setyx[0] = { 85 };
			setyx[1] = { 5 };
			//p=myCamSet.outl(setx, y, x);

			//Left eye cam
			Lefteye[0] = { 0};
			Lefteye[1] = { 5 };

			//right eye cam
			Righteye[0] = { 1 };
			Righteye[1] = { 2 };
		}


		private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = 90;
			//int  setx[2] = { 130,50 };
			//p=myCamSet.outl(setx, y, x);
			setyx[0] = { 130 };
			setyx[1] = { 50 };

			//Left eye cam
			Lefteye[0] = { 1 };
			Lefteye[1] = { 0 };

			//right eye cam
			Righteye[0] = { 2 };
			Righteye[1] = { 3 };
		}

		private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = 135;
			//int  setx[2] = { 175,95 };
			//p=myCamSet.outl(setx, y, x);
			setyx[0] = { 175 };
			setyx[1] = { 95 };

			//Left eye cam
			Lefteye[0] = { 2 };
			Lefteye[1] = { 1 };

			//right eye cam
			Righteye[0] = { 3 };
			Righteye[1] = { 4 };
		}

		private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = 180;
			//int  setx[2] = { 140,-140 };
			//p=myCamSet.outl(setx, y, x);
			setyx[0] = { 140 };
			setyx[1] = { -140 };

			//Left eye cam
			Lefteye[0] = { 2 };
			Lefteye[1] = { 2 };

			//right eye cam
			Righteye[0] = { 4 };
			Righteye[1] = { 4 };
		}

		private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = -135;
			//int  setx[2] = { -95,-175 };
			//p=myCamSet.outl(setx, y, x);
			setyx[0] = { -95 };
			setyx[1] = { -175 };

			//Left eye cam
			Lefteye[0] = { 3 };
			Lefteye[1] = { 2 };

			//right eye cam
			Righteye[0] = { 4 };
			Righteye[1] = { 5 };
		}

		private: System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = -90;
			//int  setx[2] = { -50,-130 };
			//p=myCamSet.outl(setx, y, x);
			setyx[0] = { -50 };
			setyx[1] = { -130 };

			//Left eye cam
			Lefteye[0] = { 5 };
			Lefteye[1] = { 0 };

			//right eye cam
			Righteye[0] = { 4 };
			Righteye[1] = { 3 };
		}

		private: System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			x = -45;
			//int  setx[2] = { -5,-85 };
			//p=myCamSet.outl(setx, y, x);
			setyx[0] = { -5 };
			setyx[1] = { -85 };

			//Left eye cam
			Lefteye[0] = { 0 };
			Lefteye[1] = { 1 };

			//right eye cam
			Righteye[0] = { 5 };
			Righteye[1] = { 4 };
		}


		//RADIO BUTTONY PRE Y OS

		//HORE
		private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			y = 2;
		}
				 //ROVNO
		private: System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			y = 1;
		}
				 //DOLE

		private: System::Void radioButton11_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			y = 3;
		}


		 ///// CREAT XML FILE
		 void creatXml(string name) {
					 FileStorage fs(name, FileStorage::WRITE);
					 fs.open(name, FileStorage::WRITE);
					 fs.release();
				 }
		 //////////////////////////////////////////////////

				 //BUTTON


		


		
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

			//std::cout << " x %d " << x << '\n';
			//std::cout << " y %d " << y << '\n';
			//std::cout << " setyx0 %d " << setyx[0] << '\n';
			//std::cout << " setyx1 %d " << setyx[1] << '\n';

		
			Mat pano;

			std::string nameforXML;
			std::string nameforXML2;

			Mat image11;
			Mat image10;

			cv::vector<cv::Mat> pomArray;
			cv::vector<cv::Mat> pomArray2;

			nameforXML = "././XML//XLeft.xml";
			nameforXML2 = "././XML//XRight.xml";
			//std::string combination;
			
			

			//FileStorage fs2(nameforXML2, FileStorage::WRITE);
			//fs2.open(nameforXML2, FileStorage::WRITE);
			//fs2.release();

			p = (myCamSet.outl(setyx, y, x));

			for (int i = 0; i <= 5; i++) {
				if (i == Lefteye[1] ) { //|| i == Lefteye[1]
					for (int j = 0; j <= 5; j++) {
						std::string index99 = std::to_string(i + 1);

						if (((*(*(p + i) + j)) == 1)) {


							std::string index98 = std::to_string(j + 1);

							//if (i == 5 && j == 5) {

							//}

							//else {
								image10 = imread("././Data//v1-frames//CAM-MODEL//ohnisko" + index99 + "//cam" + index98 + "//frame" + index98 + ".JPG");
							resize(image10, image10, cv::Size(1500, 2000));
								
								pomArray.push_back(image10);
						//	}
						}
					}

				}


				if (i == Righteye[1]  ) { // || i == Righteye[1]
					for (int k = 0; k <= 5; k++) {
						std::string index89 = std::to_string(i + 1);

						if (((*(*(p + i) + k)) == 1)) {


							std::string index88 = std::to_string(k + 1);


							image11 = imread("././Data//v1-frames//CAM-MODEL//ohnisko" + index89 + "//cam" + index88 + "//frame" + index88 + ".JPG");
							resize(image11, image11, cv::Size(1500, 2000));
							pomArray2.push_back(image11);
						}
					}

				}



			}
			
			creatXml(nameforXML);
			pano.release();
			myStitcher.stitch(pomArray, pano, vector<vector<Rect> >(), nameforXML);

			

			//
			
			
			pano.release();
			creatXml(nameforXML2);
			myStitcher.stitch(pomArray2, pano, vector<vector<Rect> >(), nameforXML2);
			//
		
			Mat resized;
			Mat result= imread("././Data//ImagesReal//R3.jpg");
			
		

			resize(result, resized, cv::Size(557, 405), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//resultR3.jpg", resized);

			imagee = Image::FromFile("././Data//ImagesGUI//resultR3.jpg");

			pictureBox1->Image = imagee;



			result = imread("././Data//ImagesReal//R4.jpg");

		

			resize(result, resized, cv::Size(557, 405), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//resultR4.jpg", resized);

			imagee = Image::FromFile("././Data//ImagesGUI//resultR4.jpg");

			pictureBox3->Image = imagee;

			
			
			
			
			
		}
		
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			this->InitializeComponent();
			pictureBox1->Visible = false;
			pictureBox3->Visible = false;
			
			//this->Close();
			
		}
};
}
