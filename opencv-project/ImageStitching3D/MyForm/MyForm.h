
#pragma once



#include "..\Header\Header.h"
#include "..\Main\Main.h"
#include "..\L-R-EYE\L-R-EYE.h"


using namespace cv;
using namespace std;


namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	bool comb = false;
	cv::vector<cv::Mat> images;
	cv::vector<cv::Mat> imagesV1;
	cv::vector<cv::Mat> imagesV2;
	std::string loadLeft; //obrazok v lavo
	std::string loadRight; //obrazok vpravo
	Mat image1, image2;
	Mat image3, image4, image5, image6, image7, image8, image9, image13, image14;
	MyStitcher myStitcher = MyStitcher::setters();
	MyStitcher myStitcher2 = MyStitcher::setters();
	MyCamSet myCamSet = MyCamSet::sett();
	
	Mat pano; //vystupny obrazok
	std::string combo1 = "a";
	std::string combo2 = "a";
	std::string combo3 = "a";
	std::string combo4 = "a";
	std::string combo5 = "a";
	std::string combo6 = "a";
	std::vector<std::string> files;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	//private: Form^ f1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//this->f1 = f1;
		}
		//public:
		//	MyForm(void)  
		//{
		//	InitializeComponent();
			
		//}

		protected:
			/// <summary>
		/// Clean up any resources being used.
		/// </summary>
			~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::Control^ control;
		private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button3;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::Button^  button6;
		private: System::Windows::Forms::Button^  button7;
		private: System::Windows::Forms::Button^  button10;
		private: System::Windows::Forms::Button^  button11;
		private: System::Windows::Forms::Button^  button12;
		private: System::Windows::Forms::Button^  button13;

		private: System::Windows::Forms::PictureBox^  pictureBox1;
				 System::Drawing::Image^ imagee;
		private: System::Windows::Forms::PictureBox^  pictureBox2;
		private: System::Windows::Forms::PictureBox^  pictureBox3;
		private: System::Windows::Forms::PictureBox^  pictureBox4;
		private: System::Windows::Forms::PictureBox^  pictureBox5;
	
		private: System::Windows::Forms::ComboBox^  comboBox1;
		private: System::Windows::Forms::ComboBox^  comboBox2;
		private: System::Windows::Forms::ComboBox^  comboBox3;
		private: System::Windows::Forms::ComboBox^  comboBox4;
		private: System::Windows::Forms::ComboBox^  comboBox5;
		private: System::Windows::Forms::ComboBox^  comboBox6;
		private: System::Windows::Forms::ComboBox^  comboBox7;
	

		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Label^  label2;
		private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button9;


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
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(598, 726);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 20);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Set combination";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::newCombination);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkRed;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(27, 362);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 26);
			this->button2->TabIndex = 1;
			this->button2->Text = L"LoadImages";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::LoadImages);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(857, 13);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(136, 19);
			this->button3->TabIndex = 34;
			this->button3->Text = L"Choose combination";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::changeCombination);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Black;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->Location = System::Drawing::Point(356, 8);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(136, 26);
			this->button4->TabIndex = 3;
			this->button4->Text = L"LoadFirstImage";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::LoadFirstImage);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Black;
			this->button6->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button6->Location = System::Drawing::Point(338, 362);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(106, 26);
			this->button6->TabIndex = 18;
			this->button6->Text = L"SURF";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::SURF);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Black;
			this->button7->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button7->Location = System::Drawing::Point(448, 362);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(106, 26);
			this->button7->TabIndex = 21;
			this->button7->Text = L"MatchKeypoints";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::MatchKeypoints);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::Black;
			this->button10->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button10->Location = System::Drawing::Point(513, 8);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(136, 26);
			this->button10->TabIndex = 16;
			this->button10->Text = L"LoadSecondImage";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::LoadSecondImage);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::Black;
			this->button11->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button11->Location = System::Drawing::Point(559, 362);
			this->button11->Margin = System::Windows::Forms::Padding(2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(106, 26);
			this->button11->TabIndex = 22;
			this->button11->Text = L"Homography";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::Homography);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::DarkRed;
			this->button12->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button12->Location = System::Drawing::Point(717, 362);
			this->button12->Margin = System::Windows::Forms::Padding(2);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(136, 26);
			this->button12->TabIndex = 23;
			this->button12->Text = L"Warp";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::Warp);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::DarkRed;
			this->button13->Font = (gcnew System::Drawing::Font(L"Segoe Print", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button13->Location = System::Drawing::Point(857, 362);
			this->button13->Margin = System::Windows::Forms::Padding(2);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(136, 26);
			this->button13->TabIndex = 24;
			this->button13->Text = L"Result";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::Result);
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"./image.png";
			this->pictureBox1->Location = System::Drawing::Point(12, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 293);
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->ImageLocation = L"./image.png";
			this->pictureBox2->Location = System::Drawing::Point(513, 39);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(480, 293);
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(27, 418);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(480, 293);
			this->pictureBox3->TabIndex = 19;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(513, 418);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(480, 293);
			this->pictureBox4->TabIndex = 20;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(27, 418);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(966, 293);
			this->pictureBox5->TabIndex = 25;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Visible = false;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"cam1", L"cam2", L"cam3", L"cam4", L"cam5", L"cam6" });
			this->comboBox1->Location = System::Drawing::Point(27, 726);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 21);
			this->comboBox1->TabIndex = 26;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"cam1", L"cam2", L"cam3", L"cam4", L"cam5", L"cam6" });
			this->comboBox2->Location = System::Drawing::Point(122, 726);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(92, 21);
			this->comboBox2->TabIndex = 27;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"cam1", L"cam2", L"cam3", L"cam4", L"cam5", L"cam6" });
			this->comboBox3->Location = System::Drawing::Point(218, 726);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(92, 21);
			this->comboBox3->TabIndex = 29;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"cam1", L"cam2", L"cam3", L"cam4", L"cam5", L"cam6" });
			this->comboBox4->Location = System::Drawing::Point(313, 726);
			this->comboBox4->Margin = System::Windows::Forms::Padding(2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(92, 21);
			this->comboBox4->TabIndex = 30;
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"cam1", L"cam2", L"cam3", L"cam4", L"cam5", L"cam6" });
			this->comboBox5->Location = System::Drawing::Point(408, 726);
			this->comboBox5->Margin = System::Windows::Forms::Padding(2);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(92, 21);
			this->comboBox5->TabIndex = 31;
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"cam1", L"cam2", L"cam3", L"cam4", L"cam5", L"cam6" });
			this->comboBox6->Location = System::Drawing::Point(503, 726);
			this->comboBox6->Margin = System::Windows::Forms::Padding(2);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(92, 21);
			this->comboBox6->TabIndex = 32;
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Location = System::Drawing::Point(710, 13);
			this->comboBox7->Margin = System::Windows::Forms::Padding(2);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(144, 21);
			this->comboBox7->TabIndex = 33;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(193, 364);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 20);
			this->label1->TabIndex = 35;
			this->label1->Text = L"New combination";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 402);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(531, 13);
			this->label2->TabIndex = 43;
			this->label2->Text = L"Note: images shown in these picture boxes are resized and they are just for bette"
				L"r visualization, full sized images";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(556, 402);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 13);
			this->label3->TabIndex = 44;
			this->label3->Text = L"are in folder ./ImagesReal";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(124, 9);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(109, 26);
			this->button8->TabIndex = 46;
			this->button8->Text = L"Video ";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 8);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(106, 26);
			this->button5->TabIndex = 47;
			this->button5->Text = L"Menu";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(240, 8);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(98, 27);
			this->button9->TabIndex = 48;
			this->button9->Text = L"3D imagess";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1004, 757);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->comboBox7);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Image Stitching";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		

		DIR* dir = opendir("././XML//");
		dirent* pdir;
		

		// LOAD IMG

		private: System::Void LoadFirstImage(System::Object^  sender, System::EventArgs^  e) {

			OpenFileDialog^ openFileDialogInterpolation = gcnew OpenFileDialog;

				if (openFileDialogInterpolation->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					MessageBox::Show(openFileDialogInterpolation->FileName, "Path:");
					loadLeft = msclr::interop::marshal_as<std::string>(openFileDialogInterpolation->FileName);
				}

			image1 = imread(loadLeft);

			images.push_back(image1);
	
			Mat resized;

			resize(image1, resized, cv::Size(480, 293), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//firstShow.jpg", resized);

			imagee = Image::FromFile("././Data//ImagesGUI//firstShow.jpg");

			pictureBox1->Image = imagee;


		}

		private: System::Void LoadSecondImage(System::Object^  sender, System::EventArgs^  e) {
		
			OpenFileDialog^ openFileDialogInterpolation = gcnew OpenFileDialog;

				if (openFileDialogInterpolation->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					MessageBox::Show(openFileDialogInterpolation->FileName, "Path:");
					loadRight = msclr::interop::marshal_as<std::string>(openFileDialogInterpolation->FileName);
			}
		
			image2 = imread(loadRight);

			images.push_back(image2);
	
			Mat resized;

			resize(image2, resized, cv::Size(480, 293), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//secondShow.jpg", resized);

			imagee = Image::FromFile("././Data//ImagesGUI//secondShow.jpg");

			pictureBox2->Image = imagee;


		}


		// TELO programu
		
		private: System::Void LoadImages(System::Object^  sender, System::EventArgs^  e) {

				
			images.clear();
			
			image4 = imread("././Data//v1-frames//CAM-MODEL//ohnisko3//cam1//frame1.JPG");
			image8 = imread("././Data//v1-frames//CAM-MODEL//ohnisko3//cam6//frame6.JPG");
			
			images.push_back(image4);
			images.push_back(image8);
		

			} 

		private: System::Void SURF(System::Object^  sender, System::EventArgs^  e) {

			pictureBox5->Visible = false;
			pictureBox3->Visible = true;
			pictureBox4->Visible = true;
			
			
			myStitcher.SURF(images, pano, vector<vector<Rect> >());

			Mat surf1 = imread("././Data//ImagesReal//surf1.jpg");
			Mat surf2 = imread("././Data//ImagesReal//surf2.jpg");

			Mat resized;

			resize(surf1, resized, cv::Size(480, 293), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//surf1Show.jpg", resized);

			imagee = Image::FromFile("././Data//ImagesGUI//surf1Show.jpg");

			pictureBox3->Image = imagee;

			Mat resized2;

			resize(surf2, resized2, cv::Size(480, 293), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//surf2Show.jpg", resized2);

			imagee = Image::FromFile("././Data//ImagesGUI//surf2Show.jpg");

			pictureBox4->Image = imagee;
		}

		private: System::Void MatchKeypoints(System::Object^  sender, System::EventArgs^  e) {


			pictureBox3->Visible = false;
			pictureBox4->Visible = false;
			pictureBox5->Visible = true;

			myStitcher.matchPoints();

			Mat matched = imread("././Data//ImagesReal//matched.jpg");

			Mat resized;

			resize(matched, resized, cv::Size(966, 293), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//matched.jpg", resized);

			imagee = Image::FromFile("././Data//ImagesGUI//matched.jpg");

			pictureBox5->Image = imagee;
		}

		private: System::Void Homography(System::Object^  sender, System::EventArgs^  e) {

			myStitcher.rotation_homography();

			System::String^ sysString;

			this->comboBox7->Items->Clear();

			while (pdir = readdir(dir)) {

				sysString = msclr::interop::marshal_as<System::String^>(pdir->d_name);

				if (sysString != "." && sysString != ".." && sysString != "X.xml") {
					this->comboBox7->Items->Add(sysString);
				}
			}

			myStitcher.setNewCombination();

		}

		private: System::Void Warp(System::Object^  sender, System::EventArgs^  e) {

			pictureBox5->Visible = false;
			pictureBox3->Visible = true;
			pictureBox4->Visible = true;
			
			
			myStitcher.warp2();
			
			/*
			Mat warp1 = imread("./ImagesReal//imgWarped.jpg");
			//Mat warp2 = imread("./ImagesReal//imgWarped2.jpg");

			Mat resized;

			resize(warp1, resized, cv::Size(480, 293), 0, 0, CV_INTER_LINEAR);

			imwrite("./ImagesGUI//warp1Show.jpg", resized);

			imagee = Image::FromFile("./ImagesGUI//warp1Show.jpg");

			pictureBox3->Image = imagee;
			*/
			//Mat resized2;

			//resize(warp2, resized2, cv::Size(480, 293), 0, 0, CV_INTER_LINEAR);

			//imwrite("./ImagesGUI//warp2Show.jpg", resized2);

			//imagee = Image::FromFile("./ImagesGUI//warp2Show.jpg");

			//pictureBox4->Image = imagee;

		}

		private: System::Void Result(System::Object^  sender, System::EventArgs^  e) {
			pictureBox3->Visible = false;
			pictureBox4->Visible = false;
			pictureBox5->Visible = true;

			Mat result = imread("././Data//ImagesReal//R2.jpg");

			Mat resized;

			resize(result, resized, cv::Size(966, 293), 0, 0, CV_INTER_LINEAR);

			imwrite("././Data//ImagesGUI//result1Show.jpg", resized);

			imagee = Image::FromFile("././Data//ImagesGUI//result1Show.jpg");

			pictureBox5->Image = imagee;
			

		}


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		//kombinacie pre XML vytvorenie novych
		private: System::Void newCombination(System::Object^  sender, System::EventArgs^  e) {

			comb = true;

			if (comboBox1->SelectedItem == "cam1" || comboBox1->SelectedItem == "cam2" || comboBox1->SelectedItem == "cam3" || comboBox1->SelectedItem == "cam4" || comboBox1->SelectedItem == "cam5" || comboBox1->SelectedItem == "cam6") {
				combo1 = msclr::interop::marshal_as<std::string>(comboBox1->SelectedItem->ToString());
			}

			if (comboBox2->SelectedItem == "cam1" || comboBox2->SelectedItem == "cam2" || comboBox2->SelectedItem == "cam3" || comboBox2->SelectedItem == "cam4" || comboBox2->SelectedItem == "cam5" || comboBox2->SelectedItem == "cam6") {
				combo2 = msclr::interop::marshal_as<std::string>(comboBox2->SelectedItem->ToString());
			}

			if (comboBox3->SelectedItem == "cam1" || comboBox3->SelectedItem == "cam2" || comboBox3->SelectedItem == "cam3" || comboBox3->SelectedItem == "cam4" || comboBox3->SelectedItem == "cam5" || comboBox3->SelectedItem == "cam6") {
				combo3 = msclr::interop::marshal_as<std::string>(comboBox3->SelectedItem->ToString());
			}
	
			if (comboBox4->SelectedItem == "cam1" || comboBox4->SelectedItem == "cam2" || comboBox4->SelectedItem == "cam3" || comboBox4->SelectedItem == "cam4" || comboBox4->SelectedItem == "cam5" || comboBox4->SelectedItem == "cam6") {
				combo4 = msclr::interop::marshal_as<std::string>(comboBox4->SelectedItem->ToString());
			}

			if (comboBox5->SelectedItem == "cam1" || comboBox5->SelectedItem == "cam2" || comboBox5->SelectedItem == "cam3" || comboBox5->SelectedItem == "cam4" || comboBox5->SelectedItem == "cam5" || comboBox5->SelectedItem == "cam6") {
				combo5 = msclr::interop::marshal_as<std::string>(comboBox5->SelectedItem->ToString());
			}
	
			if (comboBox6->SelectedItem == "cam1" || comboBox6->SelectedItem == "cam2" || comboBox6->SelectedItem == "cam3" || comboBox6->SelectedItem == "cam4" || comboBox6->SelectedItem == "cam5" || comboBox6->SelectedItem == "cam6") {
				combo6 = msclr::interop::marshal_as<std::string>(comboBox6->SelectedItem->ToString());
			}

			if (myStitcher.checkCameras(combo1, combo2, combo3, combo4, combo5, combo6)) {
				MessageBox::Show("Combination exists");
			}
			else {
				myStitcher.setCameras();
				MessageBox::Show("XML file created");
			}

			myStitcher.setNewCombination();

		}


		// zmena kombinacii
		private: System::Void changeCombination(System::Object^  sender, System::EventArgs^  e) {

			comb = true;
			std::string combination = msclr::interop::marshal_as<std::string>(comboBox7->SelectedItem->ToString());

			myStitcher.setCombination(combination);

		}

		// na vyber uz z existujucich kombinacii	hnet sa loadnu ked sa spusti program
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

			System::String^ sysString;
			while (pdir = readdir(dir)) {

				sysString = msclr::interop::marshal_as<System::String^>(pdir->d_name);

				if (sysString != "." && sysString != ".." && sysString != "X.xml") {
					this->comboBox7->Items->Add(sysString);
				}
			}

		}
		
		

		/////////////////////////////////////////////zmena okien, menu//////////////////////////////////////////////////////////
		//video
		private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
			//Project2::VideoForm form;
			//form.ShowDialog();
			//this->Show();
		}
				
		//menu
		private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
		}

	


	
				 //3D images

		private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Hide();
			Project2::LREYE form;
			form.ShowDialog();
			this->Show();
		}
			
};
 
}