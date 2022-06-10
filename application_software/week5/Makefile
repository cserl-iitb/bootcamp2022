
CC = gcc
LOAD_GEN_FILE = load_gen.c
SERVER_FILE = test_server.c

all: load_gen server

load_gen: $(LOAD_GEN_FILE)
	$(CC) $(LOAD_GEN_FILE) -pthread -o load_gen

server: $(SERVER_FILE)
	$(CC) $(SERVER_FILE) -pthread -ggdb3 -o server

clean:
	rm -f load_gen server *.log
