// Mio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "opencv2\opencv.hpp"

extern "C"
{
#include "libavcodec\avcodec.h"
#include "libavformat\avformat.h"
#include "libswscale\swscale.h"

}

#pragma comment(lib, "avcodec.lib")

using namespace std;

int main(int argc, char **argv)
{
	// Default device of computer
	int const device(0);

	// Escape key : 
	char escapeKey(0);

	cv::VideoCapture webcam(device);

	// Checking if the webcam device is opened
	if (!webcam.isOpened())
		return -1;

	cv::namedWindow("Stream", CV_WINDOW_AUTOSIZE);

	cv::Mat frame;

	while ((escapeKey != 27) && ( webcam.isOpened() ) )
	{
		// Read frame and check for error
		if (!webcam.read(frame)) {
			cout << "Error while fetching the frame \n";
		}

		// DO YOUR THINGS HERE LOL
		cv::imshow("Stream", frame);

		escapeKey = cv::waitKey(1);
	}





    return 0;
}



