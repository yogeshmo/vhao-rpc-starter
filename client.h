#ifndef CLIENT_H
#define CLIENT_H

#include "network.h"

void printList(std::list<std::string> &l) {
    for (std::string s : l) {
        std::cout << s << std::endl;
    }
}

// RPC which returns a list with char c appended to each string in the 
// input list.
std::list<std::string> client_append(int port, std::list<std::string> &l, char c) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cout << "error in socket!" << std::endl;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    struct hostent *host = gethostbyname("localhost");
    memcpy(&(addr.sin_addr), host->h_addr, host->h_length);
    addr.sin_port = htons(port);

    if(connect(sockfd, (sockaddr *) &addr, sizeof(addr)) == -1) {
        std::cout << "error in connect!" << std::endl;
    }

    // CONNECTED TO SERVER.
    // TODO: Finish client stub.

    return std::list<std::string>();
}

#endif