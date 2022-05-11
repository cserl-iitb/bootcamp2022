# Before You Begin

Familiarize yourself with the functions used in the template provided in problem statement


In Summary:

**Procedure in Client-Server Communication:**
1. **Socket:** Create a new communication
2. **Bind:** Attach a local address to a socket
3. **Listen:** Announce willingness to accept connections
4. **Accept:** Block caller until a connection request arrives
5. **Connect:** Actively attempt to establish a connection
6. **Write:** Write some data into the socket
7. **Read:** Read data from the socket
8. **Close:** Release the connection



Go through the specific functions and arguments required from blogs [Learning Socket Programming in cpp](https://www.codingninjas.com/blog/2020/07/06/learning-socket-programming-in-c/) and [Socket Programming](https://www.geeksforgeeks.org/socket-programming-cc/) from gfg to get a more thorough understanding of the concepts.


Feel free to go through socket programming basics from [Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/html/). You can also see simple examples of socket programs in the prescribed textbook [Peterson and Davie, Sec 1.4](https://book.systemsapproach.org/foundation/software.html?highlight=socket#application-programming-interface-sockets).


# Thread Creation

## What is a Thread?
A thread is a path of execution within a process. A process can contain multiple threads.

## Why Multithreading?
The idea is to achieve parallelism by dividing a process into multiple threads. For example, in a browser, multiple tabs can be different threads. MS Word uses multiple threads: one thread to format the text, another thread to process inputs, etc.

## How to Create Threads in cpp?
We can make use of the pthread library present in cpp. In the included libraries of the server code you can find:

```#include <pthread.h>```

You can create a thread using the pthread_create() function present in this library and join threads using the pthread_join() function. Of Course they require some arguments, For complete understanding **go through sections 27.1 and 27.2** of [Thread API](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf)


# Thread Synchronization

## What is Thread Synchronization?
Thread synchronization is defined as a mechanism which ensures that two or more concurrent threads do not simultaneously execute some particular program segment known as a **critical section**. Processes’ access to critical sections is controlled by using synchronization techniques. When one thread starts executing the critical section (a serialized segment of the program) the other thread should wait until the first thread finishes. If proper synchronization techniques are not applied, it may cause a **race condition** where the values of variables may be unpredictable and vary depending on the timings of context switches of the processes or threads.

## What is mutex?
A Mutex is a lock that we set before using a shared resource and release after using it. When the lock is set, no other thread can access the locked region of code. This ensures synchronized access of shared resources in the code.

## Working of a mutex:
1. Suppose one thread has locked a region of code using mutex and is executing that piece of code.
2. Now if the scheduler decides to do a context switch, then all the other threads which are ready to execute the same region are unblocked.
3. Only one of all the threads would make it to the execution but if this thread tries to execute the same region of code that is already locked then it will again go to sleep.
4. Context switch will take place again and again but no thread would be able to execute the locked region of code until the mutex lock over it is released.
5. Mutex lock will only be released by the thread who locked it.
6. So this ensures that once a thread has locked a piece of code then no other thread can execute the same region until it is unlocked by the thread who locked it.

## How to do this in cpp?
We can make use of the same pthread library for implementing mutex locks also, **go through section 27.3** of [Thread API](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf) for implementation related information.

## Practice Exercise for Mutex:

Write a program that has a counter as a global variable. Spawn 10 threads in the program, and let each thread increment the counter 1000 times in a loop. Print the final value of the counter after all the threads finish—the expected value of the counter is 10000. Run this program first without using locking across threads, and observe the incorrect updation of the counter due to race conditions (the final value will be slightly less than 10000). 
Next, use locks when accessing the shared counter and verify that the counter is now updated correctly

## Relavant Reading

[Mutex lock for Linux Thread Synchronization](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)


## What is a Condition Variable?

A condition variable (CV) is a queue that a thread can put itself into when waiting on some condition. Another thread that makes the condition true an signal the CV to wake up a waiting thread.
Note: Signal wakes up one thread, signal broadcast wakes up all waiting threads.

## Why Condition Variable?

Locks allow only one type of synchronization between threads which is mutual exclusion. Waiting and Signaling is another common requirement in multi-threaded applications. For eg. if thread T1 wants to continue only after T2 has finished some task.

## How to do this in cpp?

Please Read section 27.4 of [Thread API](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf) and get familiarised with the logic and functions involved.

## Relavant Reading

[Conditional wait and signal in multi-threading](https://www.geeksforgeeks.org/condition-wait-signal-multi-threading/)




