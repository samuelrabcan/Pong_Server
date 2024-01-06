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

int main(int argc, char *argv[])
{
    int socketPlayer1;
    int socketPlayer2;
    int sockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    long n;

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
//
    //int playerCount = 0;
    socketPlayer1 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (socketPlayer1 < 0)
        error("ERROR on accept");

    // Pošli správu prvemu hráčovi, že je hráč 1
    char *player1Message = "hrac1";
    write(socketPlayer1, player1Message, strlen(player1Message));

    n = read(socketPlayer1, buffer, 255);
    if (n < 0) error("ERROR reading from socket");

    socketPlayer2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (socketPlayer2 < 0)
        error("ERROR on accept");

    // Pošli správu druhému hráčovi, že je hráč 2
    char *player2Message = "hrac2";
    write(socketPlayer2, player2Message, strlen(player2Message));

    n = write(socketPlayer2, buffer, 255);
    if (n < 0) error("ERROR writing to socket");

    n = read(socketPlayer2, buffer, 255);
    if (n < 0) error("ERROR reading from socket");

    n = write(socketPlayer1, buffer, 255);
    if (n < 0) error("ERROR writing to socket");


    while (1) {
        bzero(buffer, 256);
        n = read(socketPlayer1, buffer, 255);
        if (n < 0) error("ERROR reading from socket");
        if (strcmp(buffer,"END") == 0) {
            break;
        }
        n = write(socketPlayer2, buffer, 255);
        if (n < 0) error("ERROR writing to socket");

        printf("Player 1 Position: %s\n", buffer);
        bzero(buffer, 256);

        n = read(socketPlayer2, buffer, 255);
        if (n < 0) error("ERROR reading from socket");
        if (strcmp(buffer,"END") == 0) {
            break;
        }
        n = write(socketPlayer1, buffer, 255);
        if (n < 0) error("ERROR writing to socket");

        printf("Player 2 Position: %s\n", buffer);
    }
    close(socketPlayer1);
    close(socketPlayer2);
    close(sockfd);
    return 0;
}
