

#include "..\Header\Header.h"
#include<sstream>







Mat K;
Mat H;

std::string combination;
std::string combination2;
std::string camName;
std::string nameforXML;
std::string nameforXML2;

std::string cam1 = "cam1";
std::string cam2 = "cam2";
std::string cam3 = "cam3";
std::string cam4 = "cam4";
std::string cam5 = "cam5";
std::string cam6 = "cam6";



double seamScale = 1;
double workingSeam = 1;
double warpedScale = 0;
double workingScale = 1;

std::vector<cv::Mat> imgs;
std::vector<cv::Mat> imgs2;
std::vector<cv::Mat> imgs3;
cv::vector<cv::Mat> imgs4;


//std::vector<detail::ImageFeatures> keypointsF;



//std::vector<cv::Mat> Vystup_IMG; //vytupne pole obrazkov

///warp funkcia premenne 

cv::Mat img_warped, img_warpedSeam, img_warpedSeam2,img_warped2, img_warpedSeam3, img_warped3;
Mat dila, maskSeam;
Mat maskWarped, maskWarped2, mask, maskWarped3;
//Mat full_img, img;
Mat full_img2, img2;

Mat t(3, 3, CV_64FC1);

Mat u(3, 3, CV_64FC1);

Mat t2(3, 3, CV_64FC1);

Mat u2(3, 3, CV_64FC1);

using namespace std;


std::vector<detail::ImageFeatures> keypointsF; //added
std::vector<detail::ImageFeatures> keypointsF2; //added
std::vector<detail::MatchesInfo> matchesF;     //added
std::vector<cv::Mat> seamImages;  // added
std::vector<cv::Size> full_imgSize; //ADDED
std::vector<std::vector<cv::Rect> > regions; // added



bool blenderPrep = false;
bool composePrep = false;


MyStitcher MyStitcher::setters()
{
	MyStitcher stitcher;

	stitcher.setWave(true);
	stitcher.setWaveType(detail::WAVE_CORRECT_HORIZ);
	stitcher.setKeypointMatcher(new detail::BestOf2NearestMatcher());
	stitcher.setBundle(new detail::BundleAdjusterRay());
	stitcher.setKeypointDetector(new detail::SurfFeaturesFinder());
	stitcher.setWarp(new PlaneWarper2());
	stitcher.setGraphCut(new detail::GraphCutSeamFinder(detail::GraphCutSeamFinderBase::COST_COLOR));
	stitcher.setExposureCompensator(new detail::BlocksGainCompensator());
	stitcher.setBlender(new detail::MultiBandBlender());
	stitcher.setBlender2(new detail::FeatherBlender());

	return stitcher;
}

string type2str(int type) {
	string r;

	uchar depth = type & CV_MAT_DEPTH_MASK;
	uchar chans = 1 + (type >> CV_CN_SHIFT);

	switch (depth) {
	case CV_8U:  r = "8U"; break;
	case CV_8S:  r = "8S"; break;
	case CV_16U: r = "16U"; break;
	case CV_16S: r = "16S"; break;
	case CV_32S: r = "32S"; break;
	case CV_32F: r = "32F"; break;
	case CV_64F: r = "64F"; break;
	default:     r = "User"; break;
	}

	r += "C";
	r += (chans + '0');

	return r;
}



int kokotinka = 1;
void MyStitcher::stitch(InputArray images, OutputArray pano, const vector<vector<Rect> > &rois, string nameXML)
{
	


	std::cout << "warpedScale stitch " << warpedScale << '\n';
	printf("Combination destination %s\n", combination.c_str());
	

	images.getMatVector(imgs);

	if (kokotinka == 1) {
		keypointsF.reserve(36);
		seamImages.reserve(36);
	
	//keypointsF2.resize(imgs.size());
	keypointsF.resize(imgs.size());
	
	seamImages.resize(imgs.size());
	full_imgSize.resize(imgs.size());
	//kokotinka = kokotinka + 1;
	}
	else {
		
		printf("Combination destination %s\n", combination.c_str());
		keypointsF2.resize(imgs.size());
		
		printf("Combination destination %s\n", combination.c_str());
		keypointsF.resize(imgs.size());
		seamImages.resize(imgs.size());
		full_imgSize.resize(imgs.size());
		
	}

	setNewCombination2(nameXML);
	SURF(imgs, pano, vector<vector<Rect> >());
} 


void MyStitcher::SURF(InputArray images, OutputArray pano, const vector<vector<Rect> > &rois)
{
	Mat full_img, img;
	
	
	images.getMatVector(imgs);
	regions = rois;

	bool workingSet = false;
	bool seamSet = false;
	//keypointsF.resize(imgs.size());
	//seamImages.resize(imgs.size());
	//full_imgSize.resize(imgs.size());
	Mat outImg1, outImg2, outImg3;
	for (size_t i = 0; i < imgs.size(); ++i)
	{
		full_img = imgs[i];
		full_imgSize[i] = full_img.size();
		img = full_img;

		//////////////////nie pre cam3 cam4
		if (!workingSet)
		{
			workingScale = min(1.0, sqrt(0.1* 1e6 / full_img.size().area())); //hladanie bodov na zmensenom obrazku
			workingSet = true;
		}

		resize(full_img, img, Size(), workingScale, workingScale);

		if (!seamSet)
		{
			seamScale = min(1.0, sqrt(0.6* 1e6 / full_img.size().area()));//hladanie bodov na zmensenom obrazku
			workingSeam = seamScale / workingScale;
			seamSet = true;
		}
		/////////////////////////////
			std::clock_t start;
			double duration;

			start = std::clock();
			(*keypoints)(img, keypointsF[i]);
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		//printf("pocet %d\n", keypointsF[i].keypoints.size());
		std::cout << "printf surf: " << duration << '\n';

		////////////////////nie pre cam3 cam4
		keypointsF[i].img_idx = (int)i;
		resize(full_img, img, Size(), seamScale, seamScale);
		seamImages[i] = img.clone();
		///////////////////////
		resize(img, img, Size(), seamScale, seamScale);

	}

	
	drawKeypoints(imgs[0], keypointsF[0].keypoints, outImg1, Scalar(255, 255, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	drawKeypoints(imgs[1], keypointsF[1].keypoints, outImg2, Scalar(255, 255, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	//drawKeypoints(imgs[2], keypointsF[2].keypoints, outImg3, Scalar(255, 255, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	full_img.release();
	img.release();
	//imshow("blabla",outImg1);
	//imshow("blabla2", outImg2);

	imwrite("././Data//ImagesReal//surf1.jpg", outImg1);
	imwrite("././Data//ImagesReal//surf2.jpg", outImg2);
	std::cout << "Surf Done " << '\n';
	//imwrite("./ImagesReal//surf3.jpg", outImg3);
	outImg1.release();
	outImg2.release();
	
	matchPoints();

}

void MyStitcher::matchPoints() {

	keypoints->collectGarbage();

	(*matchedPoints)(keypointsF, matchesF);

	Mat matched,matched2;

	drawMatches(imgs[0], keypointsF[0].keypoints, imgs[1], keypointsF[1].keypoints, matchesF[1].matches, matched, Scalar(255, 255, 255));
	//drawMatches(imgs[1], keypointsF[1].keypoints, imgs[2], keypointsF[2].keypoints, matchesF[2].matches, matched2, Scalar(255, 255, 255));

	imwrite("././Data//ImagesReal//matched.jpg", matched);
	//imwrite("./ImagesReal//matched2.jpg", matched2);
	//matched.release();
	//matched2.release();
	rotation_homography();
}

void MyStitcher::rotation_homography()
{

	FileStorage fs1(combination, FileStorage::WRITE);
	fs1.open(combination, FileStorage::WRITE);


	printf("combinationROTATION  MATRIX %s\n", combination.c_str());

	detail::HomographyBasedEstimator estimator;
	estimator(keypointsF, matchesF, cameras_); //klucove body, spojene klucove body, kamera (npr obrazok 1)

	for (size_t i = 0; i < cameras_.size(); ++i)
	{
		Mat R;
		cameras_[i].R.convertTo(R, CV_32F);
		cameras_[i].R = R;

	}

	bundle->setConfThresh(1);
	(*bundle)(keypointsF, matchesF, cameras_);
	//cv::Mat H = cv::findHomography(keypointsF[0], keypointsF[1]);
	// Find median focal length and use it as final image scale
	vector<double> focals;

	for (size_t i = 0; i < cameras_.size(); ++i)
	{
		focals.push_back(cameras_[i].focal);
	}

	std::sort(focals.begin(), focals.end());

	if (focals.size() % 2 == 1)
		warpedScale = static_cast<float>(focals[focals.size() / 2]);
	else
		warpedScale = static_cast<float>(focals[focals.size() / 2 - 1] + focals[focals.size() / 2]) * 0.5f;


	

	//printf("warped images scale %.20lf\n", warpedScale);



	/*if (wave_correct)
	{
		vector<Mat> rmats;

		for (size_t i = 0; i < cameras_.size(); ++i) {
			rmats.push_back(cameras_[i].R);
		}

		detail::waveCorrect(rmats, wave_correct_kind_);

		for (size_t i = 0; i < cameras_.size(); ++i) {
			cameras_[i].R = rmats[i];
			//cameras_[i].focal *= 1 / work_scale_;
			//cameras_[i].ppx *= 1 / work_scale_;
			//cameras_[i].ppy *= 1 / work_scale_;

		}
	}*/

	for (size_t i = 0; i < imgs.size(); ++i)
	{
		cameras_[i].K().convertTo(K, CV_32F);

		std::string a = "K";
		std::string b = "R";

		int temp = 0;
		temp = i;

		int temp2 = 0;
		temp2 = i;

		a.append(std::to_string(temp));
		fs1 << a << K;

		a.clear();

		b.append(std::to_string(temp2));
		fs1 << b << cameras_[i].R;

		b.clear();
	}

	fs1 << "W" << warpedScale;


	
	for (size_t i = 0; i < imgs.size(); ++i) {
		cameras_[i].focal *= 1 / workingScale;
		cameras_[i].ppx *= 1 / workingScale;
		cameras_[i].ppy *= 1 / workingScale;
	}
	//
	for (size_t i = 0; i < imgs.size(); ++i)
	{
		cameras_[i].K().convertTo(K, CV_32F);

		std::string a = "K2";
		std::string b = "R2";

		int temp = 0;
		temp = i;

		int temp2 = 0;
		temp2 = i;

		a.append(std::to_string(temp));
		fs1 << a << K;

		a.clear();

		b.append(std::to_string(temp2));
		fs1 << b << cameras_[i].R;

		b.clear();
	}

	fs1.release();

	std::cout << "Homograpfy matrix completed " << '\n';
	//keypointsF.clear();
	//focals.clear();
	warp2();
}

/*void MyStitcher::warp(int a)
{
	//printf("number %d x %d y %d\n", number, x, y);
	int x = -1;
	int y = -1;
	int  number = 1;
	int madafaka = a;

	FileStorage fs(combination, FileStorage::READ);
	fs.open(combination, FileStorage::READ);

	std::clock_t start;
	double duration;
	double duration2;
	start = std::clock();

	Mat t(3, 3, CV_64FC1);

	Mat u(3, 3, CV_64FC1);

	Mat t2(3, 3, CV_64FC1);

	Mat u2(3, 3, CV_64FC1);

	fs["W"] >> warpedScale;

	//printf("warped images scale %.20lf\n", warpedScale);
	vector<Point> corners(imgs.size());
	vector<Size> sizes(imgs.size());
	vector<Mat> images_warped(imgs.size());
	vector<Mat> masks(imgs.size());
	vector<Mat> masks_warped(imgs.size());
	Ptr<detail::RotationWarper> w;
	Mat full_img, img;
	Mat full_img2, img2;
	for (int j = 0; j <= 1; j++) {
		if (madafaka == 0) {


			//printf("* 2Debug: %d asasas %d asfasf %d \n", x, y, number);
			for (size_t i = 0; i < imgs.size(); ++i)
			{

				resize(imgs[i], img, Size(), seamScale, seamScale);
				seamImages[i] = img.clone();
			}


			//vypis zmensenych obrazkov
			imwrite("./ImagesReal//seamEstFirst.jpg", seamImages[0]);
			imwrite("./ImagesReal//seamEstSecond.jpg", seamImages[1]);



			for (size_t i = 0; i < imgs.size(); ++i)
			{
				masks[i].create(seamImages[i].size(), CV_8U);
				masks[i].setTo(Scalar::all(255));
			}

			imwrite("./ImagesReal//seam11.jpg", masks[0]);
			imwrite("./ImagesReal//seam22.jpg", masks[1]);


			Ptr<detail::RotationWarper> ue = waarp->create(float(warpedScale * workingSeam));

			for (size_t i = 0; i < imgs.size(); ++i)
			{
				std::string a = "K";
				std::string b = "R";

				int temp = 0;
				temp = i;

				int temp2 = 0;
				temp2 = i;

				a.append(std::to_string(temp));
				fs[a] >> u;

				b.append(std::to_string(temp2));
				fs[b] >> t;

				u.at<float>(0, 0) *= (float)workingSeam;
				u.at<float>(0, 2) *= (float)workingSeam;
				u.at<float>(1, 1) *= (float)workingSeam;
				u.at<float>(1, 2) *= (float)workingSeam;

				corners[i] = ue->warp(seamImages[i], u, t, INTER_LINEAR, BORDER_REFLECT, images_warped[i]);
				sizes[i] = images_warped[i].size();

				ue->warp(masks[i], u, t, INTER_NEAREST, BORDER_CONSTANT, masks_warped[i]);

			}

			vector<Mat> images_warped_f(imgs.size());

			for (size_t i = 0; i < imgs.size(); ++i)
				images_warped[i].convertTo(images_warped_f[i], CV_32F);

			// Find seams
			exposure->feed(corners, images_warped, masks_warped);
			graphCut->find(images_warped_f, corners, masks_warped);

			//printf("prvy corner %d %d\n", corners[0].x, corners[0].y);
			//printf("druhy corner %d %d\n", corners[1].x, corners[1].y);
			imwrite("./ImagesReal//seam1.jpg", masks_warped[0]);
			imwrite("./ImagesReal//seam2.jpg", masks_warped[1]);

			// Release unused memory
			seamImages.clear();
			images_warped.clear();
			images_warped_f.clear();
			masks.clear();

			double compose_work_aspect = 1;

			for (size_t img_idx = 0; img_idx < imgs.size(); ++img_idx)
			{
				std::cout << "forko %d " << img_idx << '\n';
				std::cout << "forko size%d " << imgs.size() << '\n';
				// Read image and resize it if necessary
				full_img = imgs[img_idx]; //tu je pridelenie konkretneho obrazka


				if (!composePrep)
				{
					composePrep = true;
					compose_work_aspect = 1 / workingScale;
					warpedScale *= static_cast<float>(compose_work_aspect);
					w = waarp->create((float)warpedScale); //scalovanie warpnuteho img

														   // Update corners and sizes
					for (size_t i = 0; i < imgs.size(); ++i)
					{

						// Update corner and size
						Size sz = full_imgSize[i];

						std::string a = "K2";
						std::string b = "R2";

						int temp = 0;
						temp = i;

						int temp2 = 0;
						temp2 = i;

						a.append(std::to_string(temp));
						fs[a] >> u2;

						b.append(std::to_string(temp2));
						fs[b] >> t2;

						Rect roi;

						roi = w->warpRoi(sz, u2, t2);

						corners[i] = roi.tl();
						sizes[i] = roi.size();

					}
				}

				img = full_img;
				//img2 = full_img2;
				full_img.release();
				//full_img2.release();
				img_size = img.size();

				std::string a = "K2";
				std::string b = "R2";

				int temp = 0;
				temp = img_idx;

				int temp2 = 0;
				temp2 = img_idx;

				a.append(std::to_string(temp));
				fs[a] >> u2;

				b.append(std::to_string(temp2));
				fs[b] >> t2;

				//Point2f ae(0, 0); //311 230 -- 432 310
				//Point2f test = w->warpPoint(ae, u2, t2);
				//printf("last %lf %lf\n", test.x, test.y);

				// Warp the current image
				w->warp(img, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped);
				imwrite("./ImagesReal//WTF1.jpg", img_warped);
				//w->warp(img2, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped2);

				// Warp the current image mask
				mask.create(img_size, CV_8U);
				mask.setTo(Scalar::all(255));

				//Mat warpNormal = img;

				//Mat warped, warped2;
				//warpNormal.convertTo(warped, CV_8U);
				//warpNormal.convertTo(warped2, CV_8U);

				//w->warp(img, u2, t2, INTER_NEAREST, BORDER_CONSTANT, warped);
				//imwrite("./ImagesReal//WTF2.jpg", warped);

				//w->warp(img2, u2, t2, INTER_NEAREST, BORDER_CONSTANT, warped2);


				w->warp(mask, u2, t2, INTER_NEAREST, BORDER_CONSTANT, maskWarped);
				//w->warp(mask, u2, t2, INTER_NEAREST, BORDER_CONSTANT, maskWarped2);
				//maskWarped.size();
				imwrite("./ImagesReal//seamM1.jpg", maskWarped);
				//imwrite("./ImagesReal//seamMM1.jpg", maskWarped2);

				//std::string index = std::to_string(img_idx + 1);
				//std::string warp = "warp" + index;
				//imwrite("./ImagesReal//" + warp + ".jpg", warped);
				//std::string index = std::to_string(img_idx + 2);
				//std::string warp = "warp" + index;
				//imwrite("./ImagesReal//" + warp + ".jpg", warped2);

				//exposure_comp_->apply((int)img_idx, corners[img_idx], img_warped, mask_warped);

				// Make sure seam mask has proper size
				dilate(masks_warped[img_idx], dila, Mat());
				resize(dila, maskSeam, maskWarped.size());

				maskWarped = maskSeam & maskWarped;
				//maskWarped2 = maskSeam & maskWarped2; //seam_mask &



				img_warped.convertTo(img_warpedSeam, CV_16S);
				//img_warped.convertTo(img_warpedSeam2, CV_16S);
				img_warped.release();
				img.release();
				img2.release();
				mask.release();

				if (!blenderPrep)
				{
					blender_->prepare(corners, sizes);
					blender_Origo->prepare(corners, sizes);

					blenderPrep = true;
				}
				//tu vlozit vystrihnuty kod
				// Blend the current image


				blender_->feed(img_warpedSeam, maskWarped, corners[img_idx]);
				//blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);

				Mat result, result_mask;
				Mat result2, result_mask2;
				Mat result3, result_mask3;
				blender_->blend(result, result_mask);
				imwrite("./ImagesReal//R1.jpg", result);


				//std::clock_t start1;
				//double duration3;
				//start1 = std::clock();
				////////////////////////////////////////////////////vlozenie do 1 ohybu druhy obrazok
				///*
				//full_img = imgs[img_idx+1];
				//img = full_img;
				//full_img.release();
				//img_size = img.size();

				//cv::Mat dst;
				//cv::resize(img, dst, maskWarped.size());
				//img = dst;


				//img.convertTo(img_warpedSeam, CV_16S);
				//img.release();

				//blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);
				//blender_Origo->blend(result2, result_mask);
				//imwrite("./ImagesReal//R2.jpg", result2);
				///
				//////////////////////////////////////////////////////////////////////druhy obrazok na ohyb ***
				//duration3 = (std::clock() - start1) / (double)CLOCKS_PER_SEC;
				//std::cout << "printf casik: " << duration3 << '\n';


				img_idx = img_idx + 1;
				full_img = imgs[img_idx];
				img = full_img;
				full_img.release();
				img_size = img.size();

				a = "K2";
				b = "R2";

				temp = 0;
				temp = img_idx;

				temp2 = 0;
				temp2 = img_idx;

				a.append(std::to_string(temp));
				fs[a] >> u2;

				b.append(std::to_string(temp2));
				fs[b] >> t2;

				//Point2f ae(0, 0); //311 230 -- 432 310
				//Point2f test = w->warpPoint(ae, u2, t2);
				//printf("last %lf %lf\n", test.x, test.y);

				// Warp the current image
				w->warp(img, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped);
				imwrite("./ImagesReal//imgWarped.jpg", img_warped);
				//w->warp(img2, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped2);

				// Warp the current image mask
				mask.create(img_size, CV_8U);
				mask.setTo(Scalar::all(255));

				// warpNormal = img;

				//warped, warped2;
				//warpNormal.convertTo(warped, CV_8U);
				//warpNormal.convertTo(warped2, CV_8U);

				//w->warp(img, u2, t2, INTER_NEAREST, BORDER_CONSTANT, warped);

				//w->warp(img2, u2, t2, INTER_NEAREST, BORDER_CONSTANT, warped2);


				w->warp(mask, u2, t2, INTER_NEAREST, BORDER_CONSTANT, maskWarped);
				//w->warp(mask, u2, t2, INTER_NEAREST, BORDER_CONSTANT, maskWarped2);

				//std::string index1 = std::to_string(img_idx + 1);
				//std::string warp1 = "warp" + index1;
				//imwrite("./ImagesReal//" + warp1 + ".jpg", warped2);

				imwrite("./ImagesReal//seamM2.jpg", maskWarped);
				//imwrite("./ImagesReal//seamMM2.jpg", maskWarped2);

				//std::string index = std::to_string(img_idx + 2);
				//std::string warp = "warp" + index;
				//imwrite("./ImagesReal//" + warp + ".jpg", warped2);

				//exposure_comp_->apply((int)img_idx, corners[img_idx], img_warped, mask_warped);

				// Make sure seam mask has proper size
				dilate(masks_warped[img_idx], dila, Mat());
				resize(dila, maskSeam, maskWarped.size());



				maskWarped = maskSeam & maskWarped;
				//maskWarped2 = maskSeam & maskWarped2; //seam_mask &



				img_warped.convertTo(img_warpedSeam, CV_16S);
				//img_warped.convertTo(img_warpedSeam2, CV_16S);
				img_warped.release();
				img.release();
				//img2.release();
				mask.release();


				blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);
				blender_Origo->blend(result2, result_mask2);
				imwrite("./ImagesReal//R2.jpg", result2);
				////////////////////////////////////////////////////vlozenie do 2 ohybu prvy obrazok
				///*
				//full_img = imgs[img_idx-1];
				//img = full_img;
				//full_img.release();
				//img_size = img.size();

				//cv::Mat dst;
				//cv::resize(img, dst, maskWarped.size());
				//img = dst;


				//img.convertTo(img_warpedSeam, CV_16S);


				//blender_->feed(img_warpedSeam, maskWarped, corners[img_idx]);
				//blender_->blend(result3, result_mask2);
				//imwrite("./ImagesReal//R99.jpg", result3);
				///
				////////////////////////////////////////////////////////////////////////////////////////////////


			}
			std::cout << "printf casicok : " << duration << '\n';
		}
		else {
			double compose_work_aspect = 1;

			//for (size_t img_idx = 0; img_idx < imgs.size(); ++img_idx)
			//{
			//for (size_t img_idx = 1; img_idx < imgs.size(); ++img_idx)
			//{
			dilate(masks_warped[0], dila, Mat());
			resize(dila, maskSeam, maskWarped.size());



			//maskWarped = maskSeam & maskWarped;
			//maskWarped2 = maskSeam & maskWarped2; 
			//img_warped.release();
			//img.release();
			//mask.release();

			if (!blenderPrep)
			{
				blender_->prepare(corners, sizes);
				blender_Origo->prepare(corners, sizes);

				blenderPrep = true;
			}
			//tu vlozit vystrihnuty kod
			// Blend the current image

			//blender_->feed(img_warpedSeam, maskWarped, corners[0]);
			//blender_Origo->feed(img_warpedSeam2, maskWarped2, corners[0]);

			blender_->feed(img_warpedSeam, maskWarped, corners[0]);
			blender_Origo->feed(img_warpedSeam2, maskWarped2, corners[0]);


			//blender_->feed(img_warpedSeam, maskWarped, corners[1]);
			//blender_Origo->feed(img_warpedSeam2, maskWarped2, corners[1]);




			std::cout << "else c0 " << corners[0] << '\n';
			std::cout << "else c1 " << corners[1] << '\n';
			//}
			//}

			duration2 = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "printf: " << duration2 - duration << '\n';
		}

		if (j == 0) {
			Mat result, result_mask;
			blender_->blend(result, result_mask);

			result.convertTo(panoO, CV_8U);
			//imwrite("./ImagesReal//B1.jpg", result);
			//imwrite("./ImagesReal//B11.jpg", panoO);

			Mat resultOrigo, result_maskOrigo;
			blender_Origo->blend(resultOrigo, result_maskOrigo);

			resultOrigo.convertTo(panoOrigo, CV_8U);
			//imwrite("./ImagesReal//B2.jpg", resultOrigo);
			//imwrite("./ImagesReal//B22.jpg", panoOrigo);
			//imshow("blabla2", panoOrigo);

			Mat substract = panoOrigo - panoO;
			//imwrite("./ImagesReal//SUBS.jpg", substract);
			//imshow("original", substract);

			Mat src, src_gray;

			substract.copyTo(src);

			cvtColor(src, src_gray, CV_BGR2GRAY);
			GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
			vector<Vec3f> circles;


			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "printf: " << duration << '\n';
			madafaka = 1;
			blenderPrep = false;
			imwrite("./ImagesReal//Result.jpg", panoOrigo);
		}
		else {

			Mat result, result_mask;
			blender_->blend(result, result_mask);

			result.convertTo(panoO, CV_8U);

			Mat resultOrigo, result_maskOrigo;
			blender_Origo->blend(resultOrigo, result_maskOrigo);

			resultOrigo.convertTo(panoOrigo, CV_8U);

			Mat substract = panoOrigo - panoO;

			//imshow("original", substract);

			Mat src, src_gray;

			substract.copyTo(src);

			cvtColor(src, src_gray, CV_BGR2GRAY);
			GaussianBlur(src_gray, src_gray, Size(9, 9), 2, 2);
			vector<Vec3f> circles;


			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "printf: " << duration << '\n';
			madafaka = 1;
			blenderPrep = false;
			imwrite("./ImagesReal//Result2.jpg", panoOrigo);


		}
	}

}*/

//Praca s kamerami
bool MyStitcher::checkCameras(string c1, string c2, string c3, string c4, string c5, string c6) {

	camName = "././XML//X";

	if (c1 != "a") {
		camName.append(c1);
	}
	if (c2 != "a") {
		camName.append(c2);
	}
	if (c3 != "a") {
		camName.append(c3);
	}
	if (c4 != "a") {
		camName.append(c4);
	}
	if (c5 != "a") {
		camName.append(c5);
	}
	if (c6 != "a") {
		camName.append(c6);
	}

	std::string xml = ".xml";
	camName.append(xml);

	//printf("name %s\n", camName.c_str());

	if (FILE *file = fopen(camName.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

void MyStitcher::setCameras() {

	FileStorage fs(camName, FileStorage::WRITE);
	fs.open(camName, FileStorage::WRITE);
	fs.release();

}
int jebemto = 1;
void MyStitcher::setNewCombination() {

	//nameforXML = "./XML//XLeft.xml";
	combination = camName.c_str();
	//combination = nameforXML.c_str();
	

}


void MyStitcher::setNewCombination2(string xmlString) {

	combination = xmlString.c_str();
	

}

void MyStitcher::setCombination(string comb) {
	
	combination = "././XML//";
	combination.append(comb);

}




/*void MyStitcher::points() {

	vector<Mat> original(imgs.size());

	for (int i = 0; i < imgs.size(); i++) {

		original[i] = imgs[i];

		for (int j = 1; j <= 8; j++) {

			Point2f a((original[i].cols / 9)*j, original[i].rows / 2);

			cv::circle(original[i], a, 8, (0, 0, 255), -1);
		}
	}

	imwrite("./ImagesReal//pointImage1.jpg", original[0]);
	imwrite("./ImagesReal//pointImage2.jpg", original[1]);

}*/

/*void MyStitcher::leftPoints() {

	Mat original = panoO;

	cv::circle(original, pointsFinal[1], 8, (0, 0, 255), -1);
	cv::circle(original, pointsFinal[2], 8, (0, 0, 255), -1);
	cv::circle(original, pointsFinal[3], 8, (0, 0, 255), -1);
	cv::circle(original, pointsFinal[4], 8, (0, 0, 255), -1);
	cv::circle(original, pointsFinal[5], 8, (0, 0, 255), -1);
	cv::circle(original, pointsFinal[6], 8, (0, 0, 255), -1);
	cv::circle(original, pointsFinal[7], 8, (0, 0, 255), -1);
	cv::circle(original, pointsFinal[8], 8, (0, 0, 255), -1);

	imwrite("./ImagesReal//resultPointsLeft.jpg", original);

}*/

/*void MyStitcher::pointsInWarp() {

}*/
//std::vector<std::vector<cv::Point> > corners;
//std::vector<Point> corners;






int  chuj = 1;
void MyStitcher::warp2()
{
	Mat full_img, img;
	Size img_size;
	FileStorage fs(combination, FileStorage::READ);
	fs.open(combination, FileStorage::READ);
	printf("warp combination %s\n", combination.c_str());


	vector<Point> corners(imgs.size());
	//std::cout << "printf vector : " << corners<< '\n';
	//Point corners(imgs.size());

	vector<Size> sizes(imgs.size());
	vector<Mat> images_warped(imgs.size());
	vector<Mat> masks(imgs.size());
	vector<Mat> masks_warped(imgs.size());
	Ptr<detail::RotationWarper> w;
	vector<Mat> images_warped_f(imgs.size());


	std::clock_t start;
	double duration;
	start = std::clock();

	//new Mat;
	//Mat img_warped,img_warpedSeam, img_warpedSeam2, img_warped2, img_warpedSeam3, img_warped3;



	fs["W"] >> warpedScale;

	std::cout << "warpedScale warp2 zaciatok " << warpedScale << '\n';
	
	//Mat img_warped, img_warpedSeam, img_warpedSeam2, img_warped2, img_warpedSeam3, img_warped3;
	//printf("warped images scale %.20lf\n", warpedScale);
	//
	
	//Point *corners;
	//Mat full_img2, img2;
	
	//;
			//printf("* 2Debug: %d asasas %d asfasf %d \n", x, y, number);7
	std::cout << "Warp processing started... " << '\n';
	for (size_t i = 0; i < imgs.size(); ++i)
	{
		//imgs[i] = img;
		resize(imgs[i], img, Size(), seamScale, seamScale);
		seamImages[i] = img.clone();
	}


	//vypis zmensenych obrazkov
	//imwrite("./ImagesReal//seamEstFirst.jpg", seamImages[0]);
	//imwrite("./ImagesReal//seamEstSecond.jpg", seamImages[1]);



	for (size_t i = 0; i < imgs.size(); ++i)
	{
		masks[i].create(seamImages[i].size(), CV_8U);
		masks[i].setTo(Scalar::all(255));
	}

	//imwrite("./ImagesReal//seam11.jpg", masks[0]);
	//imwrite("./ImagesReal//seam22.jpg", masks[1]);


	Ptr<detail::RotationWarper> ue = waarp->create(float(warpedScale * workingSeam));

	for (size_t i = 0; i < imgs.size(); ++i)
	{
		std::string a = "K";
		std::string b = "R";

		int temp = 0;
		temp = i;

		int temp2 = 0;
		temp2 = i;

		a.append(std::to_string(temp));
		fs[a] >> u;

		b.append(std::to_string(temp2));
		fs[b] >> t;

		u.at<float>(0, 0) *= (float)workingSeam;
		u.at<float>(0, 2) *= (float)workingSeam;
		u.at<float>(1, 1) *= (float)workingSeam;
		u.at<float>(1, 2) *= (float)workingSeam;

		corners[i] = ue->warp(seamImages[i], u, t, INTER_LINEAR, BORDER_REFLECT, images_warped[i]);
		//corners2[i] = corners[i];
		sizes[i] = images_warped[i].size();


		//corners[i] = *corners2[i];
		//corners.push_back(corners2[i]);
		//std::cout << "printf vector : " << corners2[i] << '\n';
		//std::cout << "printf vector : " << corners[i] << '\n';
		//std::cout << "printf vector2 : " << corners2[i] << '\n';
		ue->warp(masks[i], u, t, INTER_NEAREST, BORDER_CONSTANT, masks_warped[i]);
		//std::cout << "printf vector po ife c21 : " << corners2[1] << '\n';
	}
	//std::cout << "printf vector po ife c20 : " << corners2[0] << '\n';
	//std::cout << "printf vector po ife c21 : " << corners2[1] << '\n';



	try {
		for (size_t i = 0; i < imgs.size(); ++i)
			images_warped[i].convertTo(images_warped_f[i], CV_32F);
		// Find seams
		exposure->feed(corners, images_warped, masks_warped);
		//std::cout << "printf vector : " << corners << '\n';
		graphCut->find(images_warped_f, corners, masks_warped);

		//printf("prvy corner %d %d\n", corners[0].x, corners[0].y);
	//printf("druhy corner %d %d\n", corners[1].x, corners[1].y);
		imwrite("././Data//ImagesReal//seam1.jpg", masks_warped[0]);
		imwrite("././Data//ImagesReal//seam2.jpg", masks_warped[1]);
		//imwrite("./ImagesReal//seam3.jpg", masks_warped[2]);

		// Release unused memory
		seamImages.clear();
		images_warped.clear();
		images_warped_f.clear();
		masks.clear();


	}
	catch (int err_code) {
		// code to handle ExceptionName exception
		cout << "ERROR CODE " << err_code;
	}

		double compose_work_aspect = 1;
		if (!composePrep)
		{
			composePrep = true;
			compose_work_aspect = 1 / workingScale;
			warpedScale *= static_cast<float>(compose_work_aspect);
			w = waarp->create((float)warpedScale); //scalovanie warpnuteho img

												   // Update corners and sizes
			for (size_t i = 0; i < imgs.size(); ++i)
			{

				// Update corner and size
				Size sz = full_imgSize[i];

				std::string a = "K2";
				std::string b = "R2";

				int temp = 0;
				temp = i;

				int temp2 = 0;
				temp2 = i;

				a.append(std::to_string(temp));
				fs[a] >> u2;

				b.append(std::to_string(temp2));
				fs[b] >> t2;

				Rect roi;

				roi = w->warpRoi(sz, u2, t2);

				corners[i] = roi.tl();
				//corners2[i] = roi.tl();
				//std::cout << "printf vector roi: " << corners[i] << '\n';

				sizes[i] = roi.size();

			}
		}

		for (size_t img_idx = 0; img_idx < imgs.size(); ++img_idx)
		{
			Mat result, result_mask;
			Mat result2, result_mask2;
			Mat result3, result_mask3;

			// Read image and resize it if necessary
			full_img = imgs[img_idx]; //tu je pridelenie konkretneho obrazka
			img = full_img;
			full_img.release();
			img_size = img.size();

			std::string a = "K2";
			std::string b = "R2";

			int temp = 0;
			temp = img_idx;

			int temp2 = 0;
			temp2 = img_idx;

			a.append(std::to_string(temp));
			fs[a] >> u2;

			b.append(std::to_string(temp2));
			fs[b] >> t2;

			
			// Warp the current image
				
			
			//if (chuj == 1){
				w->warp(img, u2, t2, INTER_LINEAR, BORDER_REFLECT,  img_warped);
				//w->warp(img, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped2);
		//	}
		//	else {
		//		w->warp(img, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped2);
		//	}
			imwrite("././Data//ImagesReal//imgWarped.jpg", img_warped);
			//imwrite("./ImagesReal//imgWarped2.jpg", img_warped2);
			// Warp the current image mask
			mask.create(img_size, CV_8U);
			mask.setTo(Scalar::all(255));

			w->warp(mask, u2, t2, INTER_NEAREST, BORDER_CONSTANT, maskWarped);
			imwrite("././Data//ImagesReal//seamM1.jpg", maskWarped);
			//std::cout << "maskWarped : " << maskWarped ;
			
			// Make sure seam mask has proper size
			dilate(masks_warped[img_idx], dila, Mat());
			resize(dila, maskSeam, maskWarped.size());

			maskWarped = maskSeam & maskWarped;

			//imgs4.push_back(img_warped);

			img_warped.convertTo(img_warpedSeam, CV_16S);
			img_warped.release();
			img.release();
			img2.release();
			mask.release();

		if (!blenderPrep)
		{
			blender_->prepare(corners, sizes);
			blender_Origo->prepare(corners, sizes);

			blenderPrep = true;
		}


		
		

		if (img_idx == 0) {
			blender_->feed(img_warpedSeam, maskWarped, corners[img_idx]);
			blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);
			blender_->blend(result, result_mask);
			imwrite("././Data//ImagesReal//R1.jpg", result);

			std::cout << "Warping: "<< img_idx+1 << "/"<< imgs.size()<< '\n';
			
		}
		
		if (img_idx == imgs.size() - 1) {
			blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);
			blender_Origo->blend(result2, result_mask2);
			if (chuj == 1){
			imwrite("././Data//ImagesReal//R3.jpg", result2);
			chuj = chuj + 1;
			 blenderPrep = false;
			 composePrep = false;
			 img_warped.release();
			 maskWarped.release();
			 imgs.clear();
			 warpedScale = 0;
		
			
			}
			else {
				imwrite("././Data//ImagesReal//R4.jpg", result2);
				chuj = 1;
				blenderPrep = false;
				composePrep = false;
				img_warped.release();
				maskWarped.release();
				imgs.clear();
				warpedScale = 0;
				full_img.release();
				img.release();
				
				


			}
			std::cout << "Warping: " << img_idx + 1 << "/" << imgs.size() << '\n';
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "Warp done, duration time is " << duration << " second"<< '\n';
			//imgs.clear();
			
			
		}

		else {
			blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);
			std::cout << "Warping: " << img_idx + 1 << "/" << imgs.size() << '\n';
		
		}

		
		

	}

	

}



int dvakone = 1;
void MyStitcher::warp()
{
	Mat full_img, img;
	Size img_size;
	FileStorage fs(combination, FileStorage::READ);
	fs.open(combination, FileStorage::READ);






	std::clock_t start;
	double duration;
	start = std::clock();



	fs["W"] >> warpedScale;



	//printf("warped images scale %.20lf\n", warpedScale);
	//
	vector<Point> corners(imgs.size());
	//std::cout << "printf vector : " << corners<< '\n';
	//Point corners(imgs.size());

	vector<Size> sizes(imgs.size());
	vector<Mat> images_warped(imgs.size());
	vector<Mat> masks(imgs.size());
	vector<Mat> masks_warped(imgs.size());
	Ptr<detail::RotationWarper> w;
	vector<Mat> images_warped_f(imgs.size());
	//Point *corners;
	Mat full_img2, img2;
	//;
			//printf("* 2Debug: %d asasas %d asfasf %d \n", x, y, number);
	for (size_t i = 0; i < imgs.size(); ++i)
	{

		resize(imgs[i], img, Size(), seamScale, seamScale);
		seamImages[i] = img.clone();
	}


	//vypis zmensenych obrazkov
	//imwrite("./ImagesReal//seamEstFirst.jpg", seamImages[0]);
	//imwrite("./ImagesReal//seamEstSecond.jpg", seamImages[1]);



	for (size_t i = 0; i < imgs.size(); ++i)
	{
		masks[i].create(seamImages[i].size(), CV_8U);
		masks[i].setTo(Scalar::all(255));
	}

	//imwrite("./ImagesReal//seam11.jpg", masks[0]);
	//imwrite("./ImagesReal//seam22.jpg", masks[1]);


	Ptr<detail::RotationWarper> ue = waarp->create(float(warpedScale * workingSeam));

	for (size_t i = 0; i < imgs.size(); ++i)
	{
		std::string a = "K";
		std::string b = "R";

		int temp = 0;
		temp = i;

		int temp2 = 0;
		temp2 = i;

		a.append(std::to_string(temp));
		fs[a] >> u;

		b.append(std::to_string(temp2));
		fs[b] >> t;

		u.at<float>(0, 0) *= (float)workingSeam;
		u.at<float>(0, 2) *= (float)workingSeam;
		u.at<float>(1, 1) *= (float)workingSeam;
		u.at<float>(1, 2) *= (float)workingSeam;

		corners[i] = ue->warp(seamImages[i], u, t, INTER_LINEAR, BORDER_REFLECT, images_warped[i]);
		//corners2[i] = corners[i];
		sizes[i] = images_warped[i].size();


		//corners[i] = *corners2[i];
		//corners.push_back(corners2[i]);
		//std::cout << "printf vector : " << corners2[i] << '\n';
		//std::cout << "printf vector : " << corners[i] << '\n';
		//std::cout << "printf vector2 : " << corners2[i] << '\n';
		ue->warp(masks[i], u, t, INTER_NEAREST, BORDER_CONSTANT, masks_warped[i]);
		//std::cout << "printf vector po ife c21 : " << corners2[1] << '\n';
	}
	//std::cout << "printf vector po ife c20 : " << corners2[0] << '\n';
	//std::cout << "printf vector po ife c21 : " << corners2[1] << '\n';



	try {
		for (size_t i = 0; i < imgs.size(); ++i)
			images_warped[i].convertTo(images_warped_f[i], CV_32F);
		// Find seams
		exposure->feed(corners, images_warped, masks_warped);
		//std::cout << "printf vector : " << corners << '\n';
		graphCut->find(images_warped_f, corners, masks_warped);

		//printf("prvy corner %d %d\n", corners[0].x, corners[0].y);
	//printf("druhy corner %d %d\n", corners[1].x, corners[1].y);
		imwrite("././Data//ImagesReal//seam1.jpg", masks_warped[0]);
		imwrite("././Data//ImagesReal//seam2.jpg", masks_warped[1]);
		

		// Release unused memory
		seamImages.clear();
		images_warped.clear();
		images_warped_f.clear();
		masks.clear();


	}
	catch (int err_code) {
		// code to handle ExceptionName exception
		cout << "ERROR CODE " << err_code;
	}








	double compose_work_aspect = 1;

	for (size_t img_idx = 0; img_idx < imgs.size(); ++img_idx)
	{
		// Read image and resize it if necessary
		full_img = imgs[img_idx]; //tu je pridelenie konkretneho obrazka


		if (!composePrep)
		{
			composePrep = true;
			compose_work_aspect = 1 / workingScale;
			warpedScale *= static_cast<float>(compose_work_aspect);
			w = waarp->create((float)warpedScale); //scalovanie warpnuteho img

												   // Update corners and sizes
			for (size_t i = 0; i < imgs.size(); ++i)
			{

				// Update corner and size
				Size sz = full_imgSize[i];

				std::string a = "K2";
				std::string b = "R2";

				int temp = 0;
				temp = i;

				int temp2 = 0;
				temp2 = i;

				a.append(std::to_string(temp));
				fs[a] >> u2;

				b.append(std::to_string(temp2));
				fs[b] >> t2;

				Rect roi;

				roi = w->warpRoi(sz, u2, t2);

				corners[i] = roi.tl();
				//corners2[i] = roi.tl();
				//std::cout << "printf vector roi: " << corners[i] << '\n';

				sizes[i] = roi.size();

			}
		}

		img = full_img;
		full_img.release();
		img_size = img.size();

		std::string a = "K2";
		std::string b = "R2";

		int temp = 0;
		temp = img_idx;

		int temp2 = 0;
		temp2 = img_idx;

		a.append(std::to_string(temp));
		fs[a] >> u2;

		b.append(std::to_string(temp2));
		fs[b] >> t2;

		// Warp the current image
		w->warp(img, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped);
		imwrite("././Data//ImagesReal//imgWarped.jpg", img_warped);

		// Warp the current image mask
		mask.create(img_size, CV_8U);
		mask.setTo(Scalar::all(255));

		w->warp(mask, u2, t2, INTER_NEAREST, BORDER_CONSTANT, maskWarped);
		imwrite("././Data//ImagesReal//seamM1.jpg", maskWarped);
		//std::cout << "maskWarped : " << maskWarped ;

		// Make sure seam mask has proper size
		dilate(masks_warped[img_idx], dila, Mat());
		resize(dila, maskSeam, maskWarped.size());

		maskWarped = maskSeam & maskWarped;

		//imgs4.push_back(img_warped);

		img_warped.convertTo(img_warpedSeam, CV_16S);
		img_warped.release();
		img.release();
		img2.release();
		mask.release();

		if (!blenderPrep)
		{
			blender_->prepare(corners, sizes);
			blender_Origo->prepare(corners, sizes);

			blenderPrep = true;
		}


		// Blend the current image
		blender_->feed(img_warpedSeam, maskWarped, corners[img_idx]);
		blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);
		//std::cout << "blen 1 image cor : " << corners[img_idx];
		Mat result, result_mask;
		Mat result2, result_mask2;
		Mat result3, result_mask3;
		blender_->blend(result, result_mask);
		imwrite("././Data//ImagesReal//R1.jpg", result);

		////////////////////////////////////////////////////vlozenie do 1 ohybu druhy obrazok
		/*
		full_img = imgs[img_idx+1];
		img = full_img;
		full_img.release();
		img_size = img.size();

		cv::Mat dst;
		cv::resize(img, dst, maskWarped.size());
		img = dst;


		img.convertTo(img_warpedSeam, CV_16S);
		//img.release();

		//blender_Origo->feed(img_warpedSeam, maskWarped, corners[img_idx]);
		//blender_Origo->blend(result2, result_mask);
		//imwrite("./ImagesReal//R2.jpg", result2);
		*/
		//*****************************************druhy obrazok na ohyb ************************

		img_idx = img_idx + 1;
		full_img = imgs[img_idx];
		img = full_img;
		full_img.release();
		img_size = img.size();

		a = "K2";
		b = "R2";

		temp = 0;
		temp = img_idx;

		temp2 = 0;
		temp2 = img_idx;

		a.append(std::to_string(temp));
		fs[a] >> u;

		b.append(std::to_string(temp2));
		fs[b] >> t;



		// Warp the current image
		w->warp(img, u, t, INTER_LINEAR, BORDER_REFLECT, img_warped2);
		imwrite("././Data//ImagesReal//imgWarped2.jpg", img_warped2);

		imgs4.push_back(img_warped2);
		//w->warp(img2, u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped2);

		// Warp the current image mask
		mask.create(img_size, CV_8U);
		mask.setTo(Scalar::all(255));

		w->warp(mask, u, t, INTER_NEAREST, BORDER_CONSTANT, maskWarped2);

		imwrite("././Data//ImagesReal//seamM2.jpg", maskWarped2);

		dilate(masks_warped[img_idx], dila, Mat());
		resize(dila, maskSeam, maskWarped2.size());

		maskWarped2 = maskSeam & maskWarped2;

		img_warped2.convertTo(img_warpedSeam2, CV_16S);
		img_warped2.release();
		img.release();
		mask.release();



		blender_Origo->feed(img_warpedSeam2, maskWarped2, corners[img_idx]);
		blender_Origo->blend(result2, result_mask2);
		imwrite("././Data//ImagesReal//R3.jpg", result2);



	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf casicok : " << duration << '\n';
	corners2.push_back(corners[0]);
	corners2.push_back(corners[1]);
	sizes2.push_back(sizes[0]);
	sizes2.push_back(sizes[1]);

	imgs.clear();
}



int ananas = 1;

 void MyStitcher::warp( InputArray imagesVideo1, InputArray imagesVideo2) {

	Mat result, result_mask;
	Mat result2, result_mask2;

	cv::Mat dst;
	std::clock_t start;
	double duration = 0;
	Ptr<detail::RotationWarper> w;
	int pom = 0;
	
	imagesVideo1.getMatVector(imgs3);
	imagesVideo2.getMatVector(imgs2);

	start = std::clock();

		blenderPrep = false;
		////////////////////////////////////////////1 obrazok
		cv::resize(imgs3[pom], dst, maskWarped.size());
		w = waarp->create((float)warpedScale);
		
		///imwrite("./v1-frames//VR2//WTFpred.jpg", img);
		w->warp(imgs3[pom], u2, t2, INTER_LINEAR, BORDER_REFLECT, img_warped);
		//img = imgs4[0];

		///imwrite("./v1-frames//VR2//WTF1.jpg", img_warped);

		img_warped.convertTo(img_warpedSeam, CV_16S);
		img_warped.release();

	
		blender_->prepare(corners2, sizes2);
		blender_Origo->prepare(corners2, sizes2);

		
		///imwrite("./v1-frames//VR2//seamM1.jpg", maskWarped);


		blender_->feed(img_warpedSeam, maskWarped, corners2[0]); //img_idx
		blender_Origo->feed(img_warpedSeam, maskWarped, corners2[0]);//img_idx
		blender_->blend(result, result_mask);
	
		///imwrite("./v1-frames//VR2//R1.jpg", result);
		

		//////////////////////////////////////////////////2hy obrazok

		cv::resize(imgs2[pom], dst, maskWarped2.size());
		///imwrite("./v1-frames//VR2//WTF2pred.jpg", img);
		w->warp(imgs2[pom], u, t, INTER_LINEAR, BORDER_REFLECT, img_warped2);
		///imwrite("./v1-frames//VR2//WTF2.jpg", img_warped2);
		img_warped2.convertTo(img_warpedSeam2, CV_16S);
		blender_Origo->feed(img_warpedSeam2, maskWarped2, corners2[1]);
		blender_Origo->blend(result2, result_mask2);
		
		std::string index4 = std::to_string(ananas);
		std::string warp4 = "Result" + index4;
		imwrite("././Data//v1-frames//T3//" + warp4 + ".jpg", result2);
	
		ananas += 1;
		
	
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "printf casicok2 : " << duration << '\n';

 }







	