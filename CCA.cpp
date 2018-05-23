#include<iostream>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
using namespace std;
using namespace cv;

void dcc(Mat &imge);

int main(int argc, char**argv)
{
		Mat image = imread("/home/krutika/Documents/Summer_Projects/Computer_Vision_Course/opening.png",IMREAD_COLOR);
		Mat imThresh;
		
		threshold(image, imThresh,127,255,THRESH_BINARY);
		Mat imLabels;
 	 connectedComponents(imThresh, imLabels);
 
  // Display the labels
  dcc(imLabels);
 
 }


void dcc(Mat &imge)
 {
  // Make a copy of the image
  Mat imLabels = imge.clone();
 
  
  Point minLoc, maxLoc;
  double min, max;
 
  
  minMaxLoc(imLabels, &min, &max, &minLoc, &maxLoc);
 
  // Normalize the image so the min value is 0 and max value is 255.
  imLabels = 255 * (imLabels - min) / (max - min);
 
  // Convert image to 8-bits
  imLabels.convertTo(imLabels, CV_8U);
 
  // Apply a color map
  Mat imColorMap;
  applyColorMap(imLabels, imColorMap, COLORMAP_JET);
 
  // Display colormapped labels
  imshow("Labels", imColorMap);
  imwrite("connectedComponents.png", imColorMap);
  waitKey(0);
 
 }

