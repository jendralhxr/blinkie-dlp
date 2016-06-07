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
			image1.data[pointer]= grayToBinary(image1.data[pointer]);
			image1.data[pointer+1]= grayToBinary(image1.data[pointer+1]);
			image1.data[pointer+2]= grayToBinary(image1.data[pointer+2]);
			}
		}
	
	imshow("ori", image1);
 
 waitKey(0);

 return 0;
}
