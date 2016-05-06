#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

/*
 * This method will print an error message.
 * char *msg - This is the prelude to the error message that should be printed.
 */
void error(char *msg)
{
  // Print the error to stderr using the perror method.  See page 328 in reference for details.
    perror(msg);
    // Exit the system with a negative 1 return, indicating an error.
    exit(-1);
}

/*
 * This is the main method for the client.
 * There are two parameters.  argc must be 3.
 * argv[0] is the program name.
 * argv[1] is the name of the remote machine.
 * argv[2] is the port number.
 */
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    // Read the port number from the command line.
    portno = atoi(argv[2]);

    // Open a socket. See man socket for details. 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // If the socket is less than 0, there is an error opening the socket.
    // Otherwise, the socket has been opened.
    if (sockfd < 0)
    { 
        error("ERROR opening socket");
    }

    // Get the hostname.
    server = gethostbyname(argv[1]);

    // If the server is NULL, there is no such host.
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Set the values in the buffer to zero.
    memset((void*)&serv_addr, 0, sizeof(serv_addr));

    // Set up the server address type.
    serv_addr.sin_family = AF_INET;

    // Copy the data.
    memcpy((void*)&serv_addr.sin_addr.s_addr,(void*)server->h_addr, server->h_length);

    // Convert the byte ordering from the host byte ordering to the network byte ordering.
    serv_addr.sin_port = htons(portno);
    
    // connect to the socket. 
    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0) 
    {
	    error("ERROR connecting");
    }
    // Prompt the user to enter a message.
    printf("Please enter the message: ");

    // Fill the buffer with zeros.
    memset((void*)&buffer[0], 0, sizeof(buffer));

    // Read a string from the keyboard.
    fgets(buffer,255,stdin);

    // Write the buffer to the socket.
    n = write(sockfd,buffer,strlen(buffer));

    // iF N IS LESS THAN 0, AN ERROR HAS OCCURRED WRITING TO THE SOCKET.
    if (n < 0)
    { 
       error("ERROR writing to socket");
    }    
    
    // Fill the buffer again with zeros.
    memset((void*)&buffer[0], 0, sizeof(buffer)); 

    // Read data from the socket into the buffer.
    n = read(sockfd,buffer,255);

    // If n is less than 0, an error has occurred reading from the socket.
    if (n < 0) 
    {
       error("ERROR reading from socket");
    } 
    
    // Print the buffer out to the console.
    printf("%s\n",buffer);

    // Fill the buffer again with zeros.
    memset((void*)&buffer[0], 0, sizeof(buffer)); 

    // Read data from the socket into the buffer.
    n = read(sockfd,buffer,255);

    // If n is less than 0, an error has occurred reading from the socket.
    if (n < 0) 
    {
       error("ERROR reading from socket");
    } 
    
    // Print the buffer out to the console.
    printf("%s\n",buffer);

    return 0;
}
