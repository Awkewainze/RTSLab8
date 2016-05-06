#ifndef LAB_5_CAMERA_H
#define LAB_5_CAMERA_H

#include "GPIO.h"
#include "pthread.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using namespace exploringBB;

class Camera {
public:
    Camera(int port, int pinNumber, int width, int height);
    Camera(Camera& c);
    virtual ~Camera();
    void run();
    void shutdown();
    void start();
    void takePicture(int pictureType, int number);

private:
    thread cameraThread;
    GPIO* light;
    std::mutex mutex_;
    VideoCapture* capture;
    bool running;
    int height;
    int width;
};


#endif //LAB_5_CAMERA_H
