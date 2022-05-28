
CC = gcc
CLIENT_FILE = simple-client.c
SERVER_FILE = simple-server.c

all: client server

client: $(CLIENT_FILE)
	$(CC) $(CLIENT_FILE) -o client

server: $(SERVER_FILE)
	$(CC) $(SERVER_FILE) -o server

clean:
	rm -f client server
