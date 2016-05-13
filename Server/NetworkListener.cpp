//
// Created by Kevin Linsley on 5/12/16.
//

#include "NetworkListener.h"


NetworkListener::NetworkListener(const char* port, Player player) {
    socketFd = socket(AF_INET, SOCK_STREAM, 0);

    // If the return is less than 0, then the socket failed to create.
    if (socketFd < 0)
    {
        error("ERROR opening socket");
    }

    // Initialize the buffer to all zeros.
    memset((void*) &serv_addr, 0, sizeof(serv_addr));

    // Obtain the port number as an integer.
    socketPort = atoi(port);

    // Setup the server address structure.
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(socketPort);
    // Bind the socket appropriately.
    if (bind(socketFd, (struct sockaddr *) &serv_addr,   sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding");
    }





}

void NetworkListener::getDataFromClient() {
    // Listen on the socket for an incoming connection.  The parameter is the number of connections that can be waiting / queued up.  5 is the maximum allowed by most systems.
    listen(socketFd, 5);
    clilen = sizeof(cli_addr);

    // Block until a client has connected to the server.  This returns a file descriptor for the connection.
    newsockfd = accept(socketFd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    // If the return is less than 0l, there is an error.
    if (newsockfd < 0) {
        error("ERROR on accept");
    }
    while (true){
        // Fill the buffer with all zeros.
        memset(&buffer[0], 0, sizeof(buffer));

        // Read from the buffer when data arrives.  The max that can be read is 255.
        int n = read(newsockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) { error("ERROR reading from socket"); }

        player.play(buffer, n);
    }
}

/*
 * This method will print an error message.
 * char *msg - This is the prelude to the error message that should be printed.
 */
void NetworkListener::error(char *msg)
{
    // Print the error to stderr using the perror method.  See page 328 in reference for details.
    perror(msg);
    // Exit the system with a negative 1 return, indicating an error.
    exit(-1);
}





