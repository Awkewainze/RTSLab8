
#ifndef SERVER_VIDPLAYER_H
#define SERVER_VIDPLAYER_H
#include "Player.h"
#include "VideoPlayer.h"

class vidPlayer: public Player{

 public:
  vidPlayer(VideoPlayer *player);
  void play(char* source, int length);

 private:
  VideoPlayer *player;
  char buffer[692100];
  int currentIndex;
};

#endif
