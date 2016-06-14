#include "opencv2/opencv.hpp"

unsigned int binaryToGray(unsigned int num)
{
    return num ^ (num >> 1);
}

using namespace cv;
int main(int argc, char** argv)
{
	Mat disp;
	Mat temp;
	
    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    Mat frame;
    Size size(512,1024);
    
    if(!cap.open(0))
        return 0;
    for(;;)
    {
          cap >> frame;
          if( frame.empty() ) break; // end of video stream
          cvtColor(frame, temp, CV_BGR2GRAY);
          
		resize(temp, disp, size, CV_INTER_AREA);
	
		for (int offset=disp.rows*disp.cols; offset>-1; offset--){
			disp.data[offset]= binaryToGray(disp.data[offset]);
			}
		// may need to scale/resize
		
          imshow("this is you, smile! :)", disp);
          if( waitKey(1) == 27 ) break; // stop capturing by pressing ESC 
    }
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}
