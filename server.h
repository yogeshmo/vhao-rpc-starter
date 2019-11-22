#ifndef SERVER_H
#define SERVER_H

#include "network.h"

// Receives a list from a client and appends the requested character to the
// end of each string in the list before sending it back.
void server_append(int sock) {
	// TODO: Implement this.
	// Remember: recv(socket_fd, var_receiving_into, sizeof_var, MSG_WAITALL)
}

#endif