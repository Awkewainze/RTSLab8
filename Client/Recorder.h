//
// Created by root on 5/6/16.
//

#ifndef CLIENT_RECORDER_H
#define CLIENT_RECORDER_H


#include <thread>
#include "NetworkSender.h"

class Recorder {
public:

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void getThread() = 0;
    virtual void record() = 0;
    virtual void getData() = 0;
    std::thread thread;
    bool threadRunning;
    NetworkSender* sender;
};


#endif //CLIENT_RECORDER_H
