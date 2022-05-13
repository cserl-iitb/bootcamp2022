# Synchronization with xv6

Welcome to Week5's task. So far you have implemented simple and complex system calls in the xv6 operating system. You have also worked on a lazy memory allocation mechanism in xv6. We shall now focus on how xv6 implements concurrency. More specifically, we shall be looking into how spinlocks are implemented to prevent race conditions. After a good understanding has been gained, you shall then implement a custom spinlock that can be used by the user level applications.

Again, the problem statement has been designed to encourage learning. Do not hesitate to ping us if you are facing difficulties.



## Theory Prerequisites

- [Introduction to threads and concurrency](https://youtu.be/SVHLonf5AGY) and [Locks](https://youtu.be/EBevKfTDXUI)
- [Locking in xv6](https://youtu.be/icLsJLGbLuA)



## Before we begin

- Make sure you have the [source code](http://www.cse.iitb.ac.in/~puru/courses/autumn18/labs/xv6-public.tar.gz) for xv6, and that you know how to compile and run it
- You would be creating new system calls for this task, so make sure you understand the steps involved in doing so. (You have learnt this in Weeks 2 and 3)
- This lab’s code is present in `test-code` folder, and contains the following files: `Makefile`, `syscall.c`, `syscall.h`, `sysproc.c`, `test.c`, `user.h` and `usys.s`. These files add new system calls for the second part of the lab, and implements a new global counter that needs to be synchronized. 



## 1. Understanding Spinlock Implementation

This section tests your understanding of spinlocks' implementation in xv6. Go through `spinlocks.c` in xv6's source code and answer the following questions.

1. Which function is used to initialize a spinlock?
2. What do the attributes `name`, `locked` and `cpu` contain for a spinlock?
3. What functions are used for obtaining and releasing a spinlock?
4. What is the role of the `holding()` function?
5. What does `xchg()` do?
6. Why do we use `xchg()` instead of manually checking a lock's status using an `if` condition?
7. Why do we use `while` for checking the lock's condition instead of using an `if` condition?
8. Why is `asm volatile()` used in `release()` instead of using a simple C statement: `lk->locked = 0`?

Write your answers in a text file called `answers.txt`, and push it to your GitHub repository.



## 2. Implementing a Custom Spinlock

Now that you understand the essence behind xv6's implementation of spinlocks, this task requires you to make one yourself. Do read the problem statement carefully before you begin coding!

You are allowed to use the atomic `xchg()` function in your implementation of the following system calls.

- `int init_mylock()`

  Initialize a lock with `id` being its identifier. It is guaranteed that `0 ≤ id < 10`. This function returns `id` when a lock has been initialized successfully, and returns -1 in other cases.

- `int acquire_mylock(int id)`

  Attempt to acquire the custom spinlock with identifier `id`. If the lock is already acquired by some other process, then it should busily wait until it notices that the lock has been released. Returns 1 after acquiring the lock successfully and -1 in all other cases where there is an error.

- `int release_mylock(int id)`

  Release the custom spinlock with identifier `id`. Return 1 after releasing the lock successfully, and -1 in all other cases where there is an error.

- `int holding_mylock(int id)`

  Check the status of the custom spinlock denoted by identifier `id`. Return 0 if the lock is not currently held by any process, 1 if the lock is held by some process and -1 in other cases. (Such as checking the status of a lock that was not initialized)

The `test.c` file provided spawns two processes, one a child of the other. The patched files add two new system calls, `init_counter()` and `set_counter()`. The former initializes a global counter and sets its value to 0 and `set_counter(x)` sets the value of the counter to `x`.

It creates two processes which try to increment the global counter at once. This is a race condition, therefore running the testcase without locking the global variable would give a result that is less than expected. After locking the critical sections of the code however, the result should be the same every time.

After implementing the system calls given above, you need to modify `test.c` to use the locks implemented by you to correctly increment the counter.

### Hint

You know that the `id` is always less than 10. Consider two arrays `exists[10], status[10]` where `exists[id]` would be 1 if the lock has been initialized and 0 otherwise. Similarly, consider `status[id]` would store if the lock was being held by a process or if the lock was free.

Therefore, `init_mylock()` would simply iterate through the `exists` array and return the first spinlock that is uninitialized.
