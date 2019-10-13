#pragma once
#pragma omp parallel 
//#include "MyForm.h"


#include "..\Header\Header.h"
#include "Main.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	CvCapture* capture;
	CvCapture* capture2;
	IplImage* frame;
	IplImage* frame2;
	Mat pano2;

	
	std::string nameforXML; 
	std::string nameforXML2;
	cv::vector<cv::Mat> imagesVideo1;
	cv::vector<cv::Mat> imagesVideo2;
	cv::vector<cv::Mat> imagesVideoRS;
	cv::vector<cv::Mat> pomArray;
	cv::vector<cv::Mat> pomArray2;



	Mat image10;
	Mat image11;
	Mat image99;
	Mat image98;
	int cOfFrames= 0;

	int pomm[2] = { 1,2 };
	int pomm2[2] = { 3,4 };

	DIR* dir = opendir("././XML//");
	dirent* pdir;
	//cv::vector<cv::Mat> images;

	/// <summary>
	/// Summary for VideoForm
	/// </summary>
	public ref class VideoForm : public System::Windows::Forms::Form
	{
	public:
		VideoForm(void)
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
		~VideoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	
	


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
		

			
			
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Menu";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VideoForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(131, 15);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 37);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Image";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(13, 58);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(227, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Load First Video";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &VideoForm::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 98);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(459, 394);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(256, 47);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(216, 45);
			this->trackBar1->TabIndex = 4;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &VideoForm::timer1_Tick_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(13, 513);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Codec:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(13, 542);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Time:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 566);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Frame No.:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 588);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Video Resolution:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 613);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Video Frame Rate: ";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(585, 58);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(273, 34);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Load Second Video";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &VideoForm::button4_Click);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(882, 47);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(162, 45);
			this->trackBar2->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(817, 513);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Codec:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(817, 543);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(30, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Time";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(817, 567);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Frame No.:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(817, 589);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(90, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Video Resolution:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(817, 614);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Video Frame Rate: ";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(585, 98);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(459, 394);
			this->pictureBox2->TabIndex = 18;
			this->pictureBox2->TabStop = false;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(489, 124);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 67);
			this->button5->TabIndex = 19;
			this->button5->Text = L"Play";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &VideoForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button6->Location = System::Drawing::Point(489, 217);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 67);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Pause";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &VideoForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button7->Location = System::Drawing::Point(489, 309);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 67);
			this->button7->TabIndex = 21;
			this->button7->Text = L"Stop";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &VideoForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button8->Location = System::Drawing::Point(380, 567);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(293, 80);
			this->button8->TabIndex = 22;
			this->button8->Text = L"Resutl";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &VideoForm::button8_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(13, 638);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(113, 13);
			this->label11->TabIndex = 23;
			this->label11->Text = L"Number of total frames";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(817, 638);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(113, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Number of total frames";
		
	
		

			// 
			// VideoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1060, 660);
		
			
		
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"VideoForm";
			this->Text = L"VideoForm";
			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//menu
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
		
	}
			 //img
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		
	}
	//nacitanie prveho videa
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		
		Mat frameDetected;

		openFileDialog1->Filter = "AVI files (*.avi)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		openFileDialog1->FileName = "";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *fileName = (char*) Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
			capture = cvCaptureFromFile(fileName);
			trackBar1->Minimum = 0;
			trackBar1->Maximum = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
			frame = cvQueryFrame(capture);
			//images[0].push_back(frame);
			pictureBox1->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
			/*System::Drawing::Graphics^ graphics2 = pictureBox1->CreateGraphics();
			System::IntPtr ptr2(frameDetected.ptr());
			System::Drawing::Bitmap^ b2 = gcnew System::Drawing::Bitmap(frameDetected.cols,
				frameDetected.rows, frameDetected.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
			System::Drawing::RectangleF rect2(0, 0, pictureBox1->Width, pictureBox1->Height);
			graphics2->DrawImage(b2, rect2);*/
			
		
		}
		
	}

	//track bar for first video
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
	}
	
	//load druheho videa
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->Filter = "AVI files (*.avi)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		openFileDialog1->FileName = "";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *fileName = (char*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName).ToPointer();
			capture2 = cvCaptureFromFile(fileName);
			trackBar2->Minimum = 0;
			trackBar2->Maximum = (int)cvGetCaptureProperty(capture2, CV_CAP_PROP_FRAME_COUNT);
			//capture2.set(CV_CAP_PROP_FRAME_HEIGHT, 400);
			frame2 = cvQueryFrame(capture2);
			
		
			pictureBox2->Image = gcnew System::Drawing::Bitmap(frame2->width, frame2->height, frame2->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame2->imageData);
		}


	}

	private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		cvSetCaptureProperty(capture2, CV_CAP_PROP_POS_FRAMES, trackBar1->Value);
	}
	
	//casovac na spustanie videa
			// int i = 0;
	private: System::Void timer1_Tick_1(System::Object^  sender, System::EventArgs^  e)
	{
	
		try
		{
			
			

			frame = cvQueryFrame(capture) ;
			frame2 = cvQueryFrame(capture2);
			
			if (frame != NULL && frame2 != NULL) {
				Mat resized, image1, frameDetected;
				pictureBox1->Image = gcnew System::Drawing::Bitmap(frame->width, frame->height, frame->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame->imageData);
				
				
				std::string index1 = std::to_string(cOfFrames);
				std::string str = "frame" + index1;
				
				imagesVideo2.clear();

				imagesVideo2.push_back(frame2);
				imwrite("././Data//v1-frames//T2//" + str + ".jpg", imagesVideo2[0]);

				//if (cOfFrames >= 35) {
				

			
				imagesVideo1.clear();

				imagesVideo1.push_back(frame);
				//std::string index2 = std::to_string(cOfFrames-35);
				//std::string str2 = "frame" + index2;

				
				imwrite("././Data//v1-frames//T1//" + str + ".jpg", imagesVideo1[0]);
				
				

				if (cOfFrames == 0) {
					//imshow("c", imagesVideo2[10]);


					image10 = imread("././Data//v1-frames//T1//frame0.jpg");
					//imagesVideoRS.push_back(image10);

					image11 = imread("././Data//v1-frames//T2//frame0.jpg");

					pomArray.push_back(image10);
					pomArray.push_back(image11);


					System::String^ xmlstring;
					std::string combination;
					//System::String^ combination;

					//this->comboBox7->Items->Clear();

					while (pdir = readdir(dir)) {

						xmlstring = msclr::interop::marshal_as<System::String^>(pdir->d_name);
						if (xmlstring != "." && xmlstring != ".." && xmlstring != "X.xml") {
							//this->comboBox7->Items->Add(sysString);
							combination = msclr::interop::marshal_as<std::string>(xmlstring);
						}
					}

					//std::string combination = msclr::interop::marshal_as<std::string>(xmlstring);

					myStitcher.setCombination(combination);
					myStitcher.SURF(pomArray, pano2, vector<vector<Rect> >());
					myStitcher.matchPoints();
					myStitcher.rotation_homography();
					myStitcher.warp();

				}
				else {



					myStitcher.warp(imagesVideo1, imagesVideo2);

				}

				//imshow("c", imagesVideo1[0]);
				//imshow("b", imagesVideo2[0]);

				
				pictureBox2->Image = gcnew System::Drawing::Bitmap(frame2->width, frame2->height, frame2->widthStep, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame2->imageData);

				pictureBox1->Refresh();
				pictureBox2->Refresh();


				/*System::Drawing::Graphics^ graphics2 = pictureBox2->CreateGraphics();
				System::IntPtr ptr2(frameDetected.ptr());
				System::Drawing::Bitmap^ b2 = gcnew System::Drawing::Bitmap(frameDetected.cols,
					frameDetected.rows, frameDetected.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
				System::Drawing::RectangleF rect2(0, 0, pictureBox2->Width, pictureBox2->Height);
				graphics2->DrawImage(b2, rect2);*/


			
				trackBar1->Value = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES);
				trackBar2->Value = (int)cvGetCaptureProperty(capture2, CV_CAP_PROP_POS_FRAMES);
				double codec_double = cvGetCaptureProperty(capture, CV_CAP_PROP_FOURCC);
				double codec_double2 = cvGetCaptureProperty(capture2, CV_CAP_PROP_FOURCC);
				label1->Text = "Codec: " + System::Text::Encoding::UTF8->GetString(BitConverter::GetBytes((int)codec_double));
				label2->Text = "Time: " + (TimeSpan::FromMilliseconds(cvGetCaptureProperty(capture, CV_CAP_PROP_POS_MSEC)).ToString())->Substring(0, 8);
				label3->Text = "Frame No.: " + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES);
				label4->Text = "Video Resolution: " + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT) + " X " + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
				label5->Text = "Video Frame Rate: " + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
				label11->Text = "Number of total frames: " + (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);

				label6->Text = "Codec: " + System::Text::Encoding::UTF8->GetString(BitConverter::GetBytes((int)codec_double2));
				label7->Text = "Time: " + (TimeSpan::FromMilliseconds(cvGetCaptureProperty(capture2, CV_CAP_PROP_POS_MSEC)).ToString())->Substring(0, 8);
				label8->Text = "Frame No.: " + (int)cvGetCaptureProperty(capture2, CV_CAP_PROP_POS_FRAMES);
				label9->Text = "Video Resolution: " + (int)cvGetCaptureProperty(capture2, CV_CAP_PROP_FRAME_HEIGHT) + " X " + (int)cvGetCaptureProperty(capture2, CV_CAP_PROP_FRAME_WIDTH);
				label10->Text = "Video Frame Rate: " + (int)cvGetCaptureProperty(capture2, CV_CAP_PROP_FPS);
				label12->Text = "Number of total frames: " + (int)cvGetCaptureProperty(capture2, CV_CAP_PROP_FRAME_COUNT);

				cOfFrames += 1;
				
			}

		}
		catch (...) {}
	}

	


	//start button
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Start();
	}
	//stop button
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		cvReleaseCapture(&capture);
		timer1->Stop();
		label1->Text = "Codec: ";
		label2->Text = "Time: " ;
		label3->Text = "Frame No.: ";
		label4->Text = "Video Resolution: ";
		label5->Text = "Video Frame Rate: ";
		label11->Text = "Number of total frames: ";

		label6->Text = "Codec: ";
		label7->Text = "Time: ";
		label8->Text = "Frame No.: ";
		label9->Text = "Video Resolution: ";
		label10->Text = "Video Frame Rate: ";
		label12->Text = "Number of total frames: ";
	}
	//Pause buton
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Stop();
		
	
		
	}



	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		
			std::string index1 = std::to_string(0);
			image10 = imread("././Data//v1-frames//T3//Result" + index1 + ".jpg");
			imagesVideoRS.push_back(image10);
		
		int width = imagesVideoRS[0].size().width;
		int height = imagesVideoRS[0].size().height;
		cv::VideoWriter video;
		video.open("././Data//Video//COOOL2.avi", CV_FOURCC('M', 'J', 'P', 'G'), 24, cv::Size(width, height));
	

		for (int i = 0; i <= 100; i++) {

			std::string index2 = std::to_string(i);
			image10 = imread("././Data//v1-frames//T3//Result" + index2 + ".jpg");
			
			video.write(image10);
		}

		
		video.release();
		std::cout << "Video is ready." ;

	}

	

		

};
}
