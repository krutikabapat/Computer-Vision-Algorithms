#include<opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(){

	Mat image;

	image = imread("/home/krutika/Documents/Summer_Projects/Computer_Vision_Course/opening.png",IMREAD_COLOR);
	int iteration = 4;
	int ero = 3;
	Mat element = getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(2 * ero + 1, 2 * ero + 1),cv::Point(ero, ero));
    
    
    // To perform Erosion and then dilation for performing OPening
    Mat imageMorphOpened;
    morphologyEx(image, imageMorphOpened, MORPH_OPEN, element, Point(-1,-1),iteration); 

    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    imshow("Original Image", image);

    // Display the image after morphological opening is done
    namedWindow("Opening", CV_WINDOW_AUTOSIZE);
    imshow("Opening", imageMorphOpened);  

waitKey(0);
return 1; 
}