#include "opencv2/opencv.hpp"

unsigned int binaryToGray(unsigned int num)
{
    return num ^ (num >> 1);
}

using namespace cv;
int main(int argc, char** argv)
{
	Mat disp;
	Mat disp2;
	Mat temp;
	
    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    Mat frame;
    Size size(512,512);
    
    if(!cap.open(0))
        return 0;
    for(;;)
    {
          cap >> frame;
          if( frame.empty() ) break; // end of video stream
          cvtColor(frame, temp, CV_BGR2GRAY);
        
		resize(temp, disp, size, CV_INTER_AREA); // resize
	
	for (int offset=disp.rows*disp.cols; offset>-1; offset--){
			disp.data[offset]= binaryToGray(disp.data[offset]);
			}
			
		  cvtColor(disp, disp2, CV_GRAY2BGR);  // b
    
    // all bright and all dark
    
    
	for (int offset=disp2.rows*disp2.cols*3; offset>-1; offset-=3){
			disp2.data[offset] |= 0b00000010; // blue channel
			disp2.data[offset] &= 0b11111110;
		}
        
          imshow("this is you, smile! :)", disp2);
          if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC 
    }
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}
