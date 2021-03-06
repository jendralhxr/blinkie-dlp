#include <math.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

unsigned char lookup[256]={\
	0, 1, 3, 2, 7, 6, 4, 5, 15, 14, 12, 13, 8, 9, 11, 10, \
	31, 30, 28, 29, 24, 25, 27, 26, 16, 17, 19, 18, 23, 22, 20, 21, \
	63, 62, 60, 61, 56, 57, 59, 58, 48, 49, 51, 50, 55, 54, 52, 53, \
	32, 33, 35, 34, 39, 38, 36, 37, 47, 46, 44, 45, 40, 41, 43, 42, \
	127, 126, 124, 125, 120, 121, 123, 122, 112, 113, 115, 114, 119, 118, 116, 117, \
	96, 97, 99, 98, 103, 102, 100, 101, 111, 110, 108, 109, 104, 105, 107, 106, \
	64, 65, 67, 66, 71, 70, 68, 69, 79, 78, 76, 77, 72, 73, 75, 74, \
	95, 94, 92, 93, 88, 89, 91, 90, 80, 81, 83, 82, 87, 86, 84, 85, \
	255, 254, 252, 253, 248, 249, 251, 250, 240, 241, 243, 242, 247, 246, 244, 245, \
	224, 225, 227, 226, 231, 230, 228, 229, 239, 238, 236, 237, 232, 233, 235, 234, \
	192, 193, 195, 194, 199, 198, 196, 197, 207, 206, 204, 205, 200, 201, 203, 202, \
	223, 222, 220, 221, 216, 217, 219, 218, 208, 209, 211, 210, 215, 214, 212, 213, \
	128, 129, 131, 130, 135, 134, 132, 133, 143, 142, 140, 141, 136, 137, 139, 138, \
	159, 158, 156, 157, 152, 153, 155, 154, 144, 145, 147, 146, 151, 150, 148, 149, \
	191, 190, 188, 189, 184, 185, 187, 186, 176, 177, 179, 178, 183, 182, 180, 181, \
	160, 161, 163, 162, 167, 166, 164, 165, 175, 174, 172, 173, 168, 169, 171, 170, \
	};

unsigned int grayToBinary_t(unsigned int val){
	return(lookup[val]);
}

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
			image1.data[pointer]= grayToBinary_t(image1.data[pointer]);
			image1.data[pointer+1]= grayToBinary_t(image1.data[pointer+1]);
			image1.data[pointer+2]= grayToBinary_t(image1.data[pointer+2]);
			}
		}
	
	imshow("reconverted", image1);
 
 waitKey(0);

 return 0;
}
