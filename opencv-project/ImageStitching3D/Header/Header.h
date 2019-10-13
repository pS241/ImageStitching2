#pragma once
#include <stdio.h>
#include <iostream>
#include <dirent.h>
#include <string> 
#include <iostream>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

#include "opencv/highgui.h"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/stitching/stitcher.hpp"
#include "opencv2/stitching/warpers.hpp"
#include "opencv2/stitching/detail/matchers.hpp"
#include "opencv2/stitching/detail/motion_estimators.hpp"
#include "opencv2/stitching/detail/exposure_compensate.hpp"
#include "opencv2/stitching/detail/seam_finders.hpp"
#include "opencv2/stitching/detail/blenders.hpp"
#include "opencv2/stitching/detail/camera.hpp"


//#include "MyForm.h"
//#include "VideoForm.h"
//#include "Main.h"



using namespace cv::detail;
using namespace std;
using namespace cv;



namespace cv {
	class CV_EXPORTS MyStitcher
	{
	public:static  MyStitcher setters();
		 
		//setters
		void setWave(bool wave) { wave_correct = wave; }

		void setWaveType(detail::WaveCorrectKind kind) { wave_correct_kind_ = kind; }

		void setKeypointDetector(Ptr<detail::FeaturesFinder> features_finder) { keypoints = features_finder; }

		void setKeypointMatcher(Ptr<detail::FeaturesMatcher> features_matcher) { matchedPoints = features_matcher; }

		void setMatchingMask(const cv::Mat &mask) { CV_Assert(mask.type() == CV_8U && mask.cols == mask.rows); matching_mask_ = mask.clone(); }

		void setBundle(Ptr<detail::BundleAdjusterBase> bundle_adjuster) { bundle = bundle_adjuster; }

		void setWarp(Ptr<WarperCreator> creator) { waarp = creator; }

		void setExposureCompensator(Ptr<detail::ExposureCompensator> exposure_comp) { exposure = exposure_comp; }

		void setGraphCut(Ptr<detail::SeamFinder> seam_finder) { graphCut = seam_finder; }

		void setBlender(Ptr<detail::Blender> b) { blender_ = b; }
		void setBlender2(Ptr<detail::Blender> b) { blender_Origo = b; }

		bool checkCameras(string c1, string c2, string c3, string c4, string c5, string c6);
		void setCameras();
		void setNewCombination();
		//void setNewCombination2();
		void setNewCombination2(string xmlString);
		void setCombination(string comb);
		//void resetni();
		//void stitch(InputArray images, OutputArray pano, const vector<vector<Rect> > &rois);
		void stitch(InputArray images, OutputArray pano, const vector<vector<Rect>>& rois, string nameXML);
		void SURF(InputArray images, OutputArray pano, const vector<vector<Rect>>& rois);
		//void SURF();
		void matchPoints();
		void rotation_homography();
		//void warp(int a);
		void warp();
		void warp2();
		//void warp3();
		//void warpedPicture(InputArray image);
		//void warp(int a, int b, InputArray images);
		//int *warp(InputArray imagesVideo1, InputArray imagesVideo2);
	
		//void warp(InputArray images, InputArray imagesVideo1, InputArray imagesVideo2);
		//void warp(int a, int b);
		//void points();
		//void leftPoints();
		//void pointsInWarp();
		//int chose(int a[], int b[]);

		std::vector<detail::CameraParams> cameras() const { return cameras_; }
	
		//warpImg *getImage(int i);
		void warp(InputArray imagesVideo1, InputArray imagesVideo2 ); // VIDEO WARP
		

	private:


		 MyStitcher() {}

		//warpImg *slideArray[10];


		Ptr<detail::FeaturesFinder> keypoints;
		Ptr<detail::FeaturesMatcher> matchedPoints;
		Ptr<detail::BundleAdjusterBase> bundle;
		Ptr<detail::ExposureCompensator> exposure;
		Ptr<detail::SeamFinder> graphCut;
		Ptr<detail::Blender> blender_;
		Ptr<detail::Blender> blender_Origo;

		Ptr<WarperCreator> waarp;

		cv::Mat matching_mask_;
		cv::Mat panoO;

		cv::Mat panoOrigo;

		std::vector<detail::CameraParams> cameras_;

		
		

		detail::WaveCorrectKind wave_correct_kind_;
		std::vector<Point> corners2;
		std::vector<Size> sizes2;
		std::vector<Size> matrix1;
		std::vector<Size> matrix2;
		//std::vector<cv::Point> *corners;





		bool wave_correct;
	};

	class CV_EXPORTS MyCamSet {

	public:static  MyCamSet sett();

		   bool** outl(int horizont[], int vertical, int pom);

		 

	private : 
		MyCamSet() {}
		

	};
	
	
}




