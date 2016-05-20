//
// Created by root on 5/6/16.
//

#ifndef CLIENT_RECORDER_H
#define CLIENT_RECORDER_H


#include <thread>
#include "NetworkSender.h"
class NetworkSender;
class Recorder {
public:
    virtual void record() = 0;
    std::thread thread;
    bool threadRunning;
    NetworkSender* sender;
};


#endif //CLIENT_RECORDER_H
