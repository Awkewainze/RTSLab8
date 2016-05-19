//
// Created by Kevin Linsley on 5/12/16.
//

#include "AudioPlayer.h"
#include <cstdlib>
#define SAMPLING_RATE (22500)
#define NUMBER_OF_CHANNELS (2)
#define BYTES_PER_SAMPLE (2)

AudioPlayer::AudioPlayer(char* playbackHardware) {
    ai = new AudioInterface(playbackHardware, SAMPLING_RATE, NUMBER_OF_CHANNELS, SND_PCM_STREAM_PLAYBACK);
    ai->open();
    bufferSize = ai->getRequiredBufferSize();
    buffer = (char *) malloc(bufferSize);
}

AudioPlayer::~AudioPlayer(){
    ai->close();
    delete ai;
}
void AudioPlayer::play(char* source, int length) {
    for(int i = 0; i < length; i += bufferSize){
        int size = bufferSize;
        if(i + bufferSize > length)
            size = length - i;
        buffer = source + i;
        ai->write(buffer, size);
    }
}
