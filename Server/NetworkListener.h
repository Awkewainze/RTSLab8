//
// Created by Kevin Linsley on 5/12/16.
//

#ifndef SERVER_NETWORKLISTENER_H
#define SERVER_NETWORKLISTENER_H
#include <sys/socket.h>


class NetworkListener {
    NetworkListener(int fd, int port);
    void waitForClient();
private:
    int socketFd;
    int socketPort;
};


#endif //SERVER_NETWORKLISTENER_H
