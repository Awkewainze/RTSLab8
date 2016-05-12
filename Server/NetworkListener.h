//
// Created by Kevin Linsley on 5/12/16.
//

#ifndef SERVER_NETWORKLISTENER_H
#define SERVER_NETWORKLISTENER_H
#include <sys/socket.h>


class NetworkListener {
    NetworkListener();
    void waitForAudio();
    void waitForVideo();
private:
    int audioSocketFd;
    int audioPort;
    int videoSocketFd;
    int videoPort;
};


#endif //SERVER_NETWORKLISTENER_H
