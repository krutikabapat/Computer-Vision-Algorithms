#include<iostream>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main()
{

	Mat image;

	image = imread("/home/krutika/Documents/Summer_Projects/Computer_Vision_Course/book.jpg",IMREAD_COLOR);


	Mat source, rotation, result;
	double rotangle = 30;
	double scale = 2;
	Point2f center(image.cols/3, image.rows/3);

	rotation = cv::getRotationMatrix2D(center, rotangle, scale);
	// To rotate the image,  fix the center, rotation angle nd scaling.

	cv::warpAffine(image,result,rotation, Size(image.cols,image.rows));


	namedWindow("Original Image", WINDOW_AUTOSIZE);
	namedWindow("Rotated Image", WINDOW_AUTOSIZE);

		// Display images
	imshow("Original Image", image);
	imshow("Rotated Image", result);

	waitKey(0);

}