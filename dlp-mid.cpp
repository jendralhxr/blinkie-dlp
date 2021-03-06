#include <math.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}	

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
			imagebright.data[j*imagebright.cols+i]= grayToBinary(imagedark.data[j*imagedark.cols+i]);
			//mse += pow(imagedark.data[j*imagedark.cols+i]-imagebright.data[j*imagedark.cols+i],2);
			}
		}
	
	printf("mse: %f\n",sqrt(mse/262144));
	imwrite(argv[3], imageinterpolate);
	imshow("interpolate", imageinterpolate);

// imshow( "bright", imagebright );
// imshow( "dark", imagedark);
 
 waitKey(0);

 return 0;
}
