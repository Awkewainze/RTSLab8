//
// Created by Kevin Linsley on 5/12/16.
//

#ifndef SERVER_AUDIOPLAYER_H
#define SERVER_AUDIOPLAYER_H
#include "Player.h"
#include "../AudioReferenceFiles/AudioInterface.h"
#include <alsa/asoundlib.h>

class AudioPlayer : public Player{
    AudioPlayer(char* playbackHardware);
    ~AudioPlayer();
    void play(char* source, int length);
    void open();
    void close();
private:
    AudioInterface *ai;
    int bufferSize;
    char* buffer;
};


#endif //SERVER_AUDIOPLAYER_H
