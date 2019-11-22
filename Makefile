CC=g++ -g -Wall -std=c++11

CLIENT_SOURCES=client.cpp
CLIENT_OBJS=${CLIENT_SOURCES:.cpp=.o}

SERVER_SOURCES=server.cpp
SERVER_OBJS=${SERVER_SOURCES:.cpp=.o}

all: client server


client: ${CLIENT_OBJS}
	${CC} -o $@ $^ -ldl

server: ${SERVER_OBJS}
	${CC} -o $@ $^ -ldl -pthread

# Generic rules for compiling a source file to an object file
%.o: %.cpp
	${CC} -c $<
%.o: %.cc
	${CC} -c $<

clean:
	rm -f ${CLIENT_OBJS} ${SERVER_OBJS} client server