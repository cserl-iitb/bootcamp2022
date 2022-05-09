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


