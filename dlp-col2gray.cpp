#include <math.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

unsigned int binaryToGray(unsigned int num)
{
    return num ^ (num >> 1);
}

using namespace cv;
using namespace std;
unsigned char temp;
int pointer;
int main( int argc, char** argv )
{

Mat image1;

double mse;
	image1 = imread( argv[1], 1 );
	//image2 = imread( argv[2], 1 );
	
	for (int j=0; j<image1.rows; j++){
		for (int i=0; i<image1.cols; i++){
			pointer= (j*image1.cols+i)*3;
			image1.data[pointer]= binaryToGray(image1.data[pointer]);
			image1.data[pointer+1]= binaryToGray(image1.data[pointer+1]);
			image1.data[pointer+2]= binaryToGray(image1.data[pointer+2]);
			}
		}
	
	imshow("ori", image1);
 
 waitKey(0);

 return 0;
}
