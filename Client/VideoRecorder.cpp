//
// Created by baumgartd on 5/18/2016.
//

#include "VideoRecorder.h"
#include <iostream>
using namespace cv;
using namespace std;

VideoRecorder::VideoRecorder(int h, int w, NetworkSender *networkSender) {
    height = h;
    width = w;
    kill = false;

    capture = new VideoCapture(0);
    capture->set(CV_CAP_PROP_FRAME_WIDTH,width);
    capture->set(CV_CAP_PROP_FRAME_HEIGHT,height);

    sender = networkSender;
}
VideoRecorder::~VideoRecorder() {
    delete(capture);
}
void VideoRecorder::record() {
    if(!capture->isOpened()){
        cout << "Failed to connect to the camera" << endl;
        exit(-1);
    }
    while(!kill) {

        Mat frame;
        bool success = capture->read(frame);
        if (!success) {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }
        char *data = reinterpret_cast<char*>(frame.data);
        sender->sendDataToServer(data);
    }
}
void VideoRecorder::stop() {
    kill = true;
}
