//
// Created by root on 5/6/16.
//

#ifndef CLIENT_RECORDER_H
#define CLIENT_RECORDER_H


#include <thread>
#include "NetworkSender.h"

class Recorder {
public:
    virtual void start();
    virtual void stop();
    virtual std::thread* getThread();
    virtual void record();
    virtual void getData();
    std::thread* thread;
    bool threadRunning;
};


#endif //CLIENT_RECORDER_H
