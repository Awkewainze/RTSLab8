//
// Created by root on 5/6/16.
//

#include "NetworkSender.h"
#include "unistd.h"
#include <iostream>
using namespace std;
NetworkSender::NetworkSender(const char *ip,const char *p) {
    //obtain port number
    port = atoi(p);

    //create the socket
    sock_fd = socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd < 0)
        error("Error opening socket");

    //The machine that will receive the data
    server = gethostbyname(ip);
    if (server == NULL)
    {
        fprintf(stderr,"ERROR, no such host");
        exit(0);
    }

    //Fill the buffer with zeros
    memset((void*)&serv_addr,0, sizeof(serv_addr));

    //Set the address type
    serv_addr.sin_family = AF_INET;

    //Copy data

    memcpy((void*)&serv_addr.sin_addr.s_addr,(void*)server->h_addr,server->h_length);

    //Set host byte order to network byte order
    serv_addr.sin_port = htons(port);

    //Connect the socket
    if (connect(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
}

void NetworkSender::sendDataToServer(char *data) {
    //Send the data
  return_val = write(sock_fd,data,strlen(data));
	cout << data <<endl;
    if (return_val < 0)
        error("ERROR reading from socket");
}
void NetworkSender::error(char *msg) {
    perror(msg);
    exit(0);
}
