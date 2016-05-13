//
// Created by root on 5/6/16.
//

#ifndef CLIENT_AUDIORECORDER_H
#define CLIENT_AUDIORECORDER_H


#include "Recorder.h"
#include "../AudioReferenceFiles/AudioInterface.h"
class AudioRecorder: Recorder {
public:
    AudioRecorder(char*,int);
    ~AudioRecorder();

private:
    AudioInterface *ai;
    char* buffer;
    int bufferSie;
};


#endif //CLIENT_AUDIORECORDER_H
