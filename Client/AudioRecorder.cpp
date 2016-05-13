//
// Created by root on 5/6/16.
//


#include "AudioRecorder.h"
#include <alsa/asoundlib.h>
#include <cstdlib>

#define SAMPLING_RATE (22500)
#define NUMBER_OF_CHANNELS (2)
#define BYTES_PER_SAMPLE (2)

AudioRecorder::AudioRecorder(char *deviceName, int duration) {
    ai = new AudioInterface(deviceName,SAMPLING_RATE,NUMBER_OF_CHANNELS,SND_PCM_STREAM_CAPTURE);
    ai->open();
    bufferSize = ai->getRequiredBufferSize();
    buffer = (char*)malloc(bufferSize);
    threadRunning = true;
    secondsToCapture = duration;
}
AudioRecorder::~AudioRecorder() {
    ai->close();
    delete ai;
}
void AudioRecorder::record() {
    while (threadRunning){
        // Determine how many bytes need to be captured.
        int bytesToCapture = SAMPLING_RATE * secondsToCapture * NUMBER_OF_CHANNELS * BYTES_PER_SAMPLE;
        do {
            // Fill the buffer with all zeros.
            memset(buffer, 0, bufferSize);

            // Capture from the soundcard
            ai->read(buffer);

            // Write to the file.
            ai->write( buffer, bufferSize);
            //TODO - send to server
            bytesToCapture-=bufferSize;


        } while (bytesToCapture > 0);
        threadRunning = false;
    }
}

thread AudioRecorder::getThread() {
    return thread;
}
void AudioRecorder::stop() {
    threadRunning = false;
}
void AudioRecorder::start() {
    thread (record);
}
