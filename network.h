#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <list>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

// NETWORK PROTOCOL.
// We define a network interface for both the sender and receiver to use:
//		 e.g. request 1) <LENGTH_OF_LIST>
//            request 2) <string of node 1>
//            .....
//            request n) <string of node n-1>


// Sends any information necessary to reconstruct the list.
void sendList(int sock, std::list<std::string> &l) {
    // What is this line doing? Why do we need it?
    int len = htonl(l.size());

    if (send(sock, &len, sizeof(len), 0) == -1) {
		std::cout << "error in len send" << std::endl;
	}

    // TODO: Send strings of each node.
	// Remember: send(socket_fd, thing_to_send, size_of_thing, 0)
}

// Receives information describing a list and returns a reconstructed list.
std::list<std::string> recvList(int sock) {
    // What is the following code doing?
	int numStrings;

	int rval = recv(sock, &numStrings, sizeof(numStrings), MSG_WAITALL);
	if (rval == -1) {
		std::cout << "error while receing length!" << std::endl;
	}

    // What is this line doing? Why do we need it?
	numStrings = ntohl(numStrings);

	std::list<std::string> res;
	if (!numStrings) {
		return res;
	}

    // TODO: Receive strings of each node and recreate linked list.
    return std::list<std::string>();
}

#endif