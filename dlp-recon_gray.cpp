#include <cv.h>
#include <highgui.h>
#include <stdio.h>
	
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
Mat imagein, imageout;
Mat image, imagethresh;
bool background;

imagein= imread( "threshold.png", 1 );
cvtColor(imagein, imagethresh, CV_BGR2GRAY);
		
for (int n=1; n<argc; n++){
	//cout << argv[i] << endl;
	imagein = imread( argv[n], 1 );
	image = Mat(imagein.rows, imagein.cols, CV_8UC1);
	cvtColor(imagein, image, CV_BGR2GRAY);
	if (n==1) imageout = Mat(image.rows, image.cols, CV_8UC1);
	
	for (int j=0; j<image.rows; j++){
		for (int i=0; i<image.cols; i++){
			if (image.data[j*image.cols+i] > imagethresh.data[j*image.cols+i]){
				imageout.data[j*image.cols+i] |= (1<<(8-n));
				}
			}
		}
	}
	
 imshow( "walao e", imageout );
 waitKey(0);

 return 0;
}
