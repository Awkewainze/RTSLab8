//
// Created by root on 5/6/16.
//

#ifndef CLIENT_NETWORKSENDER_H
#define CLIENT_NETWORKSENDER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
//#include "Recorder.h"
//#include "AudioRecorder.h"
class NetworkSender {

public:
    NetworkSender(const char *ip, const char *port);
    void sendDataToServer(char*);
private:
    void error(char* msg);
    char buffer[256];
    int sock_fd,port,return_val;
    struct sockaddr_in serv_addr;
    struct hostent *server;

};


#endif //CLIENT_NETWORKSENDER_H
