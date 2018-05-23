#include<iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(){
    Mat image;
image = cv::imread("book.jpg",IMREAD_COLOR);
cv::Mat B(image,cv::Rect(15,15,50,50));// crop operation
cv::Mat C = image.clone(); // Clone Image

 A.copyTo(C,mask);

namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
imshow("Original Image", image);

namedWindow("Cropped Image", CV_WINDOW_AUTOSIZE);
imshow("Crooped Image", B);

namedWindow("Cloned Image",CV_WINDOW_AUTOSIZE);
imshow("Cloned Image",C);
namedWindow("Masked Image",CV_WINDOW_AUTOSIZE);
imshow("Masked Image",C);




waitKey(0);
return 0;
}