//
// Created by Kevin Linsley on 5/12/16.
//

#ifndef SERVER_VIDEOPLAYER_H
#define SERVER_VIDEOPLAYER_H
#include "Player.h"

class VideoPlayer : public Player {
    void play(char* source, int length);
};


#endif //SERVER_VIDEOPLAYER_H
