# Bootcamp Week 4: Enhancements to HTTP server

This week, you will add more features to the simple HTTP server built in the previous week. 

## Worker thread pool

So far, your web server was handling multiple clients by creating a separate thread for each client. However, thread creation is a high overhead task. Therefore, real-life multi-threaded servers use a pool of reusable worker threads instead. The main server creates a pool of worker threads at the start. Whenever a new client connection is accepted, the server places the accepted client file descriptor in a queue/array shared with the workers. Each worker thread fetches a client from this queue, and serves it as long as the client is connected. Once the client finishes and terminates, the worker thread goes back to the queue to get the next client to handle. In this way, the same pool of worker threads can serve multiple clients.

Begin by watching this video to understand the multi-threaded design pattern of servers: [Video lecture on multi-threaded application design](https://youtu.be/TXZqpu4zmLI)

More video lectures on [Locking](https://youtu.be/EBevKfTDXUI) and [Condition Variables](https://youtu.be/rMpOfbaP2PQ)

To design a thread pool, you must first create multiple threads. Next, you will need a shared buffer or queue to store the accepted client file descriptors. You can use a large array or a C++  [queue](https://www.cplusplus.com/reference/queue/queue/) or any such data structure for this purpose. The main server thread and the worker threads must use locks to access this queue without race conditions. Next, the main server thread and worker threads will use condition variables to signal each other when clients are added or removed from the queue. Carefully study the various functions available to correctly use locks and condition variables from this [introduction to Pthread API](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf)

Once your worker thread dequeues a client socket file descriptor from the shared queue, the rest of the handling of the client request will be the same as before. You should be able to reuse all of your server HTTP processing in the code of the worker thread. Ensure that you release any locks that the thread is holding before performing operations like disk reads for files; otherwise, the other threads may stall for the lock. 

After you make these changes, your server will be able to handle multiple clients concurrently as before, but without having to create a new thread for every client. Start your server in one terminal. Open separate terminals to start several different clients, and check that all of them can correctly communicate with the echo server. You can also print out some debug output to check that clients are correctly being assigned to worker threads, and that the worker thread is serving another client after the first client terminates.

## Dynamic HTTP responses

The simple HTTP server built in the previous week could only handle static web pages stored in the file system. Modify the server to handle dynamic HTTP responses as well. That is, you can handle URLs that do not correspond to any file in the HTML root directory, but will instead run some function to generate a dynamic HTTP response. For example, the URL ```/hello``` can return a HTML web page that says Hello to the user. Or, the URL ```/hello?CSERL``` can return a HTML response that says ```Hello CSERL```. You can modify the function that generates HTML responses to handle a wide variety of URLs in this manner.

## Other features

You can add other enhancements to your web server to make it more realistic. Some suggestions are given below. You can support more types of HTTP requests from the HTTP specifications. You can return a more complete set of HTTP headers also in your responses. You can also support persistent connections and other features of HTTP 1.1. This part of the assignment is open-ended, and you can make your HTTP server as close to a real-world server as you wish. 
