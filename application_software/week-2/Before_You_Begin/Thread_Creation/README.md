# Thread Creation

## What is a Thread?
A thread is a path of execution within a process. A process can contain multiple threads.

## Why Multithreading?
The idea is to achieve parallelism by dividing a process into multiple threads. For example, in a browser, multiple tabs can be different threads. MS Word uses multiple threads: one thread to format the text, another thread to process inputs, etc.

## How to Create Threads in cpp?
We can make use of the pthread library present in cpp. In the included libraries of the server code you can find:

```#include <pthread.h>```

You can create a thread using the pthread_create() function present in this library and join threads using the pthread_join() function. Of Course they require some arguments, For complete understanding **go through sections 27.1 and 27.2** of [Thread API](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf)


