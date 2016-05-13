//
// Created by root on 5/6/16.
//

#include "NetworkSender.h"

NetworkSender::NetworkSender(const char *port,char *serverName) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // If the return is less than 0, then the socket failed to create.
    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    // Get the hostname.
    server = gethostbyname(serverName);
    // If the server is NULL, there is no such host.
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Initialize the buffer to all zeros.
    memset((void*) &serv_addr, 0, sizeof(serv_addr));

    // Obtain the port number as an integer.
    sockport = atoi(port);

    // Setup the server address structure.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(socketPort);

    memcpy((void*)&serv_addr.sin_addr.s_addr,(void*)server->h_addr, server->h_length);

    // Connect to Socket
    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
    {
        error("ERROR connecting");
    }
}

void NetworkSender::sendDataToServer(char *data) {

    //memset((void*)&buffer[0], 0, sizeof(buffer));
    int n = write(sockfd,data,255);

    // iF N IS LESS THAN 0, AN ERROR HAS OCCURRED WRITING TO THE SOCKET.
    if (n < 0)
    {
        error("ERROR writing to socket");
    }
}
