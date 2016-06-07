#define THRESHOLD_BACKGROUND 20
#define THRESHOLD_LOGIC 75

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
unsigned int waw;


for (int j=0; j<512; j++){
	for (int i=0; i<512; i++){
		waw= 0;
		waw+= 16*((j%16)^((j%16)>>1)); // rows pattern
		waw+= (i%16)^((i%16)>>1); // collumn pattern
		imageout.data[j*512+i]= waw;
		//std::cout << j << i << waw << std::endl;
		}
	}	
					
 imshow("walao e", imageout );
 
 waitKey(0);

 return 0;
}
