#include "vidPlayer.h"
#include <QMetaObject>
vidPlayer::vidPlayer(VideoPlayer *player){
  this->player = player;
  this->currentIndex = 0;
}

void vidPlayer::play(char* source, int length){
    int used = 0;
    if(currentIndex + length >= 692100){
        char cpy[692100];
        used = 692100 - currentIndex;
        strncpy(buffer + currentIndex, source, used);
        strncpy(cpy, buffer, 692100);
        player->play(cpy, currentIndex + length);
        currentIndex = 0;
    }
    strncpy(buffer + currentIndex, source + used, length - used);
    currentIndex += length - used;
}
