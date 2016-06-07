/*
imageout = Mat(352, 512, CV_8UC3);
for (int j=0; j<imageout.rows; j++){
	for (int i=0; i<imageout.cols; i++){
		imageout.data[3*(j*imageout.cols+i)] = 255;
		imageout.data[3*(j*imageout.cols+i)+1] = 0;
		imageout.data[3*(j*imageout.cols+i)+2] = 0;
		}
	}
 * */

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
int offset;

char seq, color;		
for (int n=1; n<argc; n++){
	color= (n-1)/8;
	seq--;
	if(seq==~0) seq=7;
	cout << argv[n] << ' ' << (int) color << ' ' << (int) seq << endl;
	
	imagein = imread( argv[n], 1 );
	if (n==1){
		image = Mat(imagein.rows, imagein.cols, CV_8UC1);
		imageout = Mat(imagein.rows, imagein.cols, CV_8UC3);
		}
	cvtColor(imagein, image, CV_BGR2GRAY);
	
	for (int j=0; j<image.rows; j++){
		for (int i=0; i<image.cols; i++){
			//if (image.data[j*image.cols+i] > 50){
			if (image.data[j*image.cols+i] > imagethresh.data[j*image.cols+i]){
				switch(color){ // DLP sequence
					case 0: break; // blue
					case 1: offset= 2; break; // red
					case 2: offset= 1; break; // green
					}
				imageout.data[3*(j*imageout.cols+i)+offset] |= 1 << seq;
				}
			}
		}
	
		
		
	}
	
	
 imshow( "walao e", imageout );
 //imshow( "thre", imagethresh);
 
 waitKey(0);

 return 0;
}
