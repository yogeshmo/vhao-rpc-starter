// Credit to Brendan Campbell for original server.cpp code. 
// Modified by vhao.

#include "server.h"

#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "ERROR: Usage is './server <port>'" << endl;
        return 0;
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int yesval = 1;
    int port = atoi(argv[1]);

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yesval, sizeof(yesval));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(sockfd, (sockaddr *) &addr, sizeof(addr)) == -1) {
        cout << "error in bind!" << endl;
    }

    socklen_t length = sizeof(addr);
    if (getsockname(sockfd, (sockaddr *) &addr, &length) == -1) {
        perror("Error getting port of socket");
        return -1;
    }
    port = ntohs(addr.sin_port);

    printf("Server listening on port %d...\n", port);

    listen(sockfd, 5);

    while (true) {
        int connectionfd = accept(sockfd, 0, 0);
        if (connectionfd == -1) {
            perror("Error accepting connection");
            return -1;
        }
        thread(server_append, connectionfd).detach();
    }
}