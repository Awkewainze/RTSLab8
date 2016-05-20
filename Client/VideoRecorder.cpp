//
// Created by root on 5/13/16.
//

#include "VideoRecorder.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

VideoRecorder::VideoRecorder(char *, int) {
    running = true;
    buffer = new char[bufferSize];
}

VideoRecorder::~VideoRecorder() {
    delete [] buffer;
    delete camera;
}

void VideoRecorder::record() {

}

void VideoRecorder::getThread() {

}

void VideoRecorder::start(){
    running = true;
    if(!camera->isOpened()){
        cout << "Error opening video stream or file" << endl;
        return;
    }

    double frame_width=camera->get(CV_CAP_PROP_FRAME_WIDTH);
    double frame_height=camera->get(CV_CAP_PROP_FRAME_HEIGHT);
    VideoWriter video("out.avi", CV_FOURCC('M','J','P','G'), 10, Size((int)frame_width,(int)frame_height), true);

    while(running){

        Mat frame;
        *camera >> frame;
        video.write(frame);
        imshow( "Frame", frame );
    }
}

void VideoRecorder::stop() {
    running = false;
}

void VideoRecorder::getData() {
    Recorder::getData();
}











