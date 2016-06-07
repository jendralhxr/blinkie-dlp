#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int waw, wew;
char check_background(){
	}
	
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{

Mat imagein, imageout, imagethres, imageback, imagebri;
Mat image;
bool background;
char filename[20];

imagethres= Mat(512, 512, CV_8UC1);
imageout = Mat(512, 512, CV_8UC1);
imageback = Mat(512, 512, CV_8UC1);
imagebri = Mat(512, 512, CV_8UC1);
image = Mat(512, 512, CV_8UC1);
	
//imagethres = imread( "thres.png", 1 );
//imageback = imread( "dark.bmp", 1 );
//imagebri = imread( "terang.bmp", 1 );
//imshow ("threshold",imagethres);
//imshow ("terang",imagebri);
//imshow ("background",imageback);

imagein = imread( argv[1], 1 );
cvtColor(imagein, image, CV_BGR2GRAY);
char temp;	
	 		
for (int n=0; n<8; n++){
	
	for (int j=0; j<image.rows; j++){
		for (int i=0; i<image.cols; i++){
				temp= image.data[j*512+i];
				if (temp & (1<<n)) imageout.data[j*512+i]=255;
				else imageout.data[j*512+i]=0;
				}
			}
	printf("bitplane%d.bmp\n",n);
	sprintf(filename,"bitplane%d.bmp",n);
	imwrite(filename,imageout);
	
}
		
imshow( "walao e", imagein);
waitKey(0);

 return 0;
}
