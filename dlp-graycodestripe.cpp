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

Mat imagein, imageout;
Mat image;
bool background;

imageout = Mat(512, 512, CV_8UC1);
unsigned int n, waw;

for (int j=0; j<512; j++){
	for (int i=0; i<512; i++){
		waw=255*i/512;
		imageout.data[j*512+i]= waw ^ (waw>>1);
		//std::cout << j << i << waw << std::endl;
	
		}
	}	
					
 imshow( "walao e", imageout );
 
 waitKey(0);

 return 0;
}
