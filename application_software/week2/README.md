# Bootcamp Week 2 : Application Software
# Simple echo client/server with multi-threading

This week, we will build a simple echo client-server application. The client and server will exchange simple messages with each other, where the server simply echoes back the message received from the client. The server will also be multi-threaded to handle multiple clients concurrently. Please work thorugh the following tasks in order.

# Exercise 1: Understanding socket programming

Your first task is to write a simple C/C++ client-server programs using the socket API. In this exercise, the client should send a message to the server, and the server should simply echo it back to the client. That is, it must send the same message back to the client. The server should keep doing this as long as the client is connected to it. 

Below are two video lectures to understand the concepts involved (you can watch either one):

[Network I/O using sockets video lecture 1](https://youtu.be/2TrQXSFgqBY)

[Network I/O using sockets video lecture 2](https://youtu.be/UIH-cqUjcM0)

Now, consider the simple client and server programs provided to you in this repository. You can use them as a guide to write your own code. The server program takes one command line argument: the port number on which to listen. The client program takes two arguments: the server hostname and port number. You can give localhost as the hostname if you are running the client and server on the same machine. Once the client and server are connected to each other, the client sends a message to the server and gets a reply back. 

Here is the output from these sample programs

   ```console
    $gcc server.c -o server
    $./server 5000
    Here is the message: Hello
 ```
   ```console
    $gcc client.c -o client
    $./client localhost 5000
    Please enter the message: Hello
    I got your message
```

Please understand these sample programs and all the socket-related system calls completely. Then, use this code as a template to write your own echo client and server in C or C++. Unlike this sample server, your server must echo back exactly the message received from the client. Also, it must repeatedly read data from the client and echo is back, and not just quit after one message exchange. Complete writing this simple echo client and server before you proceed to the next exercise.

**Other additional references to understand socket programming:** 

[Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/html/) 

Examples of socket programs in the textbook [Peterson and Davie, Sec 1.4](https://book.systemsapproach.org/foundation/software.html?highlight=socket#application-programming-interface-sockets)

[Learning Socket Programming in cpp](https://www.codingninjas.com/blog/2020/07/06/learning-socket-programming-in-c/)

[Socket Programming](https://www.geeksforgeeks.org/socket-programming-cc/)


# Exercise 2: Introduction to multi-threading

In the above program, the main server thread is accepting the connection and serving it. Next, create a single thread to handle a connection.

# Exercise 3: Server thread pool

The final task for this week is to create a multi-threaded server by creating a pool of threads.