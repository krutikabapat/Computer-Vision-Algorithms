#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <vector>
// Affine transform is stored in a 2 cross 3 matrix 
// where first column is rotation
// sceond is scale and shear
//third is translation

using namespace cv;
using namespace std;
int main(void)
{
// Read image
Mat source = imread("/home/krutika/Documents/Summer_Projects/Computer_Vision_Course/opening.png",IMREAD_COLOR);

// Create 2 warp matrices for different transformations
Mat warpMat = (Mat_<double>(2,3) << 1.2, 0.2, 2, -0.3, 1.3, 1 );

// Another Matrix
Mat warpMat2 = (Mat_<double>(2,3) << 1.2, 0.3, 2, 0.2, 1.3, 1);

Mat result,result2;

// Use warp affine
cv::warpAffine(source, result, warpMat, Size(1.5*source.rows,1.4*source.cols), INTER_LINEAR, BORDER_REFLECT_101);
cv::warpAffine(source, result2, warpMat2, Size(1.5*source.rows, 1.4*source.cols), INTER_LINEAR, BORDER_REFLECT_101);

// Display images
imshow("Original", source);
imshow("Result", result);
imshow("Result2", result2);
waitKey(0);
destroyAllWindows();
}