//
// Created by root on 5/13/16.
//

#ifndef CLIENT_VIDEORECORDER_H
#define CLIENT_VIDEORECORDER_H


#include "Recorder.h"
#include <opencv2/opencv.hpp>

using namespace cv;

class VideoRecorder : Recorder {
public:
    VideoRecorder(char*, int);
    ~VideoRecorder();
    void record();
    void getThread();
    void start();
    void stop();
    void getData();
private:
    VideoCapture *camera;
    bool running;
    char* buffer;
    int bufferSize;
    int secondsToCapture;
};


#endif //CLIENT_VIDEORECORDER_H
