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

double mse;
	image1 = imread( argv[1], 1 );
	image2 = imread( argv[2], 1 );

	for (int j=0; j<image1.rows; j++){
		for (int i=0; i<image1.cols; i++){
			mse += pow(image1.data[(3*j*image1.cols+i)]-image2.data[(3*j*image1.cols+i)],2);
			mse += pow(image1.data[(3*j*image1.cols+i)+1]-image2.data[(3*j*image1.cols+i)+1],2);
			mse += pow(image1.data[(3*j*image1.cols+i)+2]-image2.data[(3*j*image1.cols+i)+2],2);
//			printf("%d %d %f\n",j, i, mse);
			}
		}
	if (mse==0) printf("0.0\n");
	else printf("mse: %f\n",mse,(mse/image1.cols/image1.rows));
 
 waitKey(0);

 return 0;
}
