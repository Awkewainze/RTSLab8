//
// Created by root on 5/6/16.
//

#ifndef CLIENT_NETWORKSENDER_H
#define CLIENT_NETWORKSENDER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

class NetworkSender {

public:
    NetworkSender(const char* port, char*);
    void sendDataToServer(char*);
private:
    void error(char* msg);
    char buffer[256];
    int sockfd;
    int sockport;
    int newsockfd;
    socklen_t clilen;
    struct hostent *server;
    struct sockaddr_in serv_addr, cli_addr;

};


#endif //CLIENT_NETWORKSENDER_H
