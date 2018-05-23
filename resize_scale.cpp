#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
int main(void){

		Mat source, scaleup,scaledown;

		source = imread("/home/krutika/Documents/Summer_Projects/Computer_Vision_Course/book.jpg",IMREAD_COLOR);
		double scalex =0.8;
		double scaley = 0.8;

		//The resize function has the following prototype:resize(sourceImage, destinationImage, Size(,), scale factor in x direction, scale factor in y direction, interpolation method).We can either specify the Size(,) of the output to determine the height and width of the output or we can add the scaling factors and the Size will be calculated automatically.

		cv::resize(source,scaledown,Size(),scalex,scaley,INTER_LINEAR);
		cv::resize(source,scaleup,Size(), scalex*3, scaley*3, INTER_LINEAR );

		Mat crop = source(cv::Range(50,102), cv::Range(20,200));

		namedWindow("original", WINDOW_AUTOSIZE);
		namedWindow("Scaled Down", WINDOW_AUTOSIZE);
		namedWindow("Scaled Up", WINDOW_AUTOSIZE);
		namedWindow("Cropped Image", WINDOW_AUTOSIZE);

		imshow("Original", source);
		imshow("Scaled Down", scaledown);
		imshow("Scaled Up", scaleup);
		imshow("Cropped Image", crop);

waitKey(0);



}