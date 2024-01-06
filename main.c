#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int sendMessage(int socket, char* message) {
    if (write(socket, message, strlen(message)) < 0) {
        printf("Chyba - send.\n");
        return -1;
    }
    return 0;
}

int receiveMessage(int socket, char* buffer) {
    bzero(buffer, 256);
    if (read(socket, buffer, 255) < 0) {
        printf("Chyba - recv.\n");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int socketPlayer1;
    int socketPlayer2;
    int sockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);

    clilen = sizeof(cli_addr);

    socketPlayer1 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (socketPlayer1 < 0)
        error("ERROR on accept");

    if (sendMessage(socketPlayer1, "hrac1") == -1) {
        return 1;
    }
    if (receiveMessage(socketPlayer1, buffer) == -1) {
        return 1;
    }

    socketPlayer2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (socketPlayer2 < 0)
        error("ERROR on accept");

    if (sendMessage(socketPlayer2, "hrac2") == -1) {
        return 1;
    }
    if (sendMessage(socketPlayer2, buffer) == -1) {
        return 1;
    }
    if (receiveMessage(socketPlayer2, buffer) == -1) {
        return 1;
    }
    if (sendMessage(socketPlayer1, buffer) == -1) {
        return 1;
    }

    // Game loop
    while (1) {
        if (receiveMessage(socketPlayer1, buffer) == -1) {
            break;
        }
        if (strcmp(buffer,"END") == 0) {
            break;
        }
        if (sendMessage(socketPlayer2, buffer) == -1) {
            break;
        }

        printf("Player 1 Position: %s\n", buffer);

        if (receiveMessage(socketPlayer2, buffer) == -1) {
            break;
        }
        if (strcmp(buffer,"END") == 0) {
            break;
        }
        if (sendMessage(socketPlayer1, buffer) == -1) {
            break;
        }

        printf("Player 2 Position: %s\n", buffer);
    }

    close(socketPlayer1);
    close(socketPlayer2);
    close(sockfd);
    return 0;
}
