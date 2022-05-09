
# Problem Statement

Write two ”CPP” socket programs, client.cpp and server.cpp, that communicate together using TCP. Multiple clients send hello messages to the server and the server sends reply messages to them.

1. client.cpp generates 50 threads and each thread corresponds to a separate client.
2. After generation of threads, client.c code sleeps for 20 seconds before joining the threads generated.
3. Each client thread establishes a socket connection with the server and sends a “Hello” message to it.
4. The Server after connecting with each client generates a thread corresponding to that client.
5. The Server thread receives incoming hello message from client, stores it in client_message array, appends “Read from client: ” string in front of  it and copies it to the buffer array. It finally sends the buffer message back to the client and closes the socket connection.
6. Server can serve at most 50 requests simultaneously and if the Server receives any further request above it, must wait for the ongoing requests to end before starting another cycle.
   
You have been provided with template codes (in cpp) for server and client, and you need to fill in the UNIMPLEMENTED/TO DO sections. Please Refrain from changing code not present in UNIMPLEMENTED/TO DO sections.

**Template codes (client.cpp and server.cpp) are present in this folder. Download it and fill the UNIMPLEMENTED/TO DO sections**

The client and server must both be on the same machine. The programs should take command line arguments as shown below.

./client <client_port> <server_port>
./server <server_port> <client_port>



## Compilation Instructions

```g++ client.cpp -o client -pthread```

```g++ server.cpp -o server -pthread```