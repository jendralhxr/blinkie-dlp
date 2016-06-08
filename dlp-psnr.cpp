#include <math.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

//int waw, wew;
	
using namespace cv;
using namespace std;
unsigned char temp;
int main( int argc, char** argv )
{

Mat image1, image2;
Mat imagedark, imagebright;

bool background;
double mse;
	image1 = imread( argv[1], 1 );
	image2 = imread( argv[2], 1 );
	
	imagedark = Mat(image1.rows, image1.cols, CV_8UC1);
	imagebright = Mat(image2.rows, image2.cols, CV_8UC1);
	
	cvtColor(image1, imagedark, CV_BGR2GRAY);
	cvtColor(image2, imagebright, CV_BGR2GRAY);
	
	for (int j=0; j<imagedark.rows; j++){
		for (int i=0; i<imagedark.cols; i++){
			mse += pow(imagedark.data[j*imagedark.cols+i]-imagebright.data[j*imagedark.cols+i],2);
			}
		}
	
	if (mse==0) printf("0.0\n");
	printf("mse: %f\n",mse/imagedark.cols/imagedark.rows);
	
// imshow( "bright", imagebright );
// imshow( "dark", imagedark);
 
 waitKey(0);

 return 0;
}
