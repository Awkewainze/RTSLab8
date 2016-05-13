//
// Created by Kevin Linsley on 5/12/16.
//

#ifndef SERVER_NETWORKLISTENER_H
#define SERVER_NETWORKLISTENER_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include "Player.h"
#include "VideoPlayer.h"
#include "AudioPlayer.h"


class NetworkListener {
public:
    NetworkListener(const char* port, Player player);
    void getDataFromClient();
private:
    void error(char* msg);
    Player player;
    char buffer[256];
    int socketFd;
    int socketPort;
    int newsockfd;
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
};


#endif //SERVER_NETWORKLISTENER_H
