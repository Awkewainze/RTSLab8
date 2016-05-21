//
// Created by root on 5/6/16.
//


#include "AudioRecorder.h"
#include <alsa/asoundlib.h>
#include <thread>
#include <iostream>
#define SAMPLING_RATE (22500)
#define NUMBER_OF_CHANNELS (2)
#define BYTES_PER_SAMPLE (2)
using namespace std;
AudioRecorder::AudioRecorder(char *deviceName, int duration,NetworkSender *networkSender) {
    ai = new AudioInterface(deviceName,SAMPLING_RATE,NUMBER_OF_CHANNELS,SND_PCM_STREAM_CAPTURE);
    ai->open();
    bufferSize = ai->getRequiredBufferSize();
    buffer = (char*)malloc(bufferSize);
    secondsToCapture = duration;
    sender = networkSender;
}
AudioRecorder::~AudioRecorder() {
    ai->close();
    delete ai;
}
void AudioRecorder::record() {
        int rc = 1;
        // Determine how many bytes need to be captured.
        int bytesToCapture = SAMPLING_RATE * secondsToCapture * NUMBER_OF_CHANNELS * BYTES_PER_SAMPLE;
        do {
            // Fill the buffer with all zeros.
            memset(buffer, 0, bufferSize);

            // Capture from the sound card
            int readSize =  ai->read(buffer);

            //Send capture to server
            sender->sendDataToServer(buffer,readSize);

            //Reduce bytes needed to capture
            bytesToCapture-=bufferSize;


        } while ((bytesToCapture > 0)&&(rc>0));
}
