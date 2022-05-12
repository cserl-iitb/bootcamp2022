# Bootcamp Week 2 : Application Software
# Simple echo client/server with multi-threading

## Overview

This week, we will build a simple client-server application. The client and server will exchange simple messages with each other. The server will also be multi-threaded to handle multiple clients concurrently. Please work thorugh the following tasks in order.

# Exercise 1: Understanding socket programming

We have given you C++ code for a simple client and server based on the socket API as the starting point of your exercises. Before you modify it, you must fully understand what the client and server are doing. 

Below are some helpful resources:

[Network I/O using sockets video lecture](https://youtu.be/2TrQXSFgqBY)

[Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/html/) 

Examples of socket programs in the textbook [Peterson and Davie, Sec 1.4](https://book.systemsapproach.org/foundation/software.html?highlight=socket#application-programming-interface-sockets)

[Learning Socket Programming in cpp](https://www.codingninjas.com/blog/2020/07/06/learning-socket-programming-in-c/)

[Socket Programming](https://www.geeksforgeeks.org/socket-programming-cc/)


A summary of the client-server communication system calls in the given code: 

1. **Socket:** Create a new communication endpoint
2. **Bind:** Attach a local address to a socket
3. **Listen:** Announce willingness to accept connections
4. **Accept:** Block caller until a connection request arrives, and accept new connection request. This creates a new socket file descriptor.
5. **Connect:** Actively attempt to establish a connection
6. **Write:** Write some data into the socket
7. **Read:** Read data from the socket
8. **Close:** Release the connection

Here is how you run the given skeleton code:

TBD

# Exercise 2: Introduction to multi-threading

In the above program, the main server thread is accepting the connection and serving it. Next, create a single thread to handle a connection.

# Exercise 3: Server thread pool

The final task for this week is to create a multi-threaded server by creating a pool of threads.