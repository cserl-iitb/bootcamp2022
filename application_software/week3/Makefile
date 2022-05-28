
CC = g++ -Wno-write-strings
SERVER_FILE = simple_server.cpp
HTTP_SERVER_FILE = http_server.cpp

all: server

server: $(SERVER_FILE) $(HTTP_SERVER_FILE)
	$(CC) $(SERVER_FILE) $(HTTP_SERVER_FILE) -o server

clean:
	rm -f server
