//
// Created by baumgartd on 5/18/2016.
//

#ifndef RTSLAB8_VIDEORECORDER_H
#define RTSLAB8_VIDEORECORDER_H

#include <opencv2/opencv.hpp>
#include<mutex>
#include <thread>
#include "Recorder.h"
#include "NetworkSender.h"
using namespace cv;
using namespace std;

class VideoRecorder : Recorder {
public:
    VideoCapture capture;
    std::mutex cameraMutex;
    int height;
    int width;
    int recordTime;
    VideoRecorder(int,int,NetworkSender*);
    ~VideoRecorder();
    void record();
    bool kill;
    void stop();
};
#endif //RTSLAB8_VIDEORECORDER_H

