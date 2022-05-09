Part B: New system calls in xv6

We will add a couple of new system calls to the xv6 kernel.

Ready? Start by understanding the system call path followed when a system call is invoked. A simple tutorial is linked here. You don't need to understand everything, just get an overview of the ow through kernel code on invocation of a system call and which les need to be modied to add a new system call.

Now look at an existing system call to understand how system calls are to be added. For example, look at how sysproc.c implements system calls like sys_fork (which calls functions in other les).

You will implement the following new system calls in xv6.

Hello xv6 World!
Implement a system call, called hello(), which prints Hi! Welcome to the world of xv6! to the console. You can use cprintf for printing in kernel mode.
Next, we will implement a system call called helloYou(name) that takes an argument char* name. It prints name to the console. You can use cprintf for printing in kernel mode.
Check out the open system call in sysfile.c that takes in multiple arguments like strings and integers, and return a simple integer value.

Also check argint, argptr, argstr functions and their descriptions in syscall.c.

Hints: You will need to modify a number of dierent les for this exercise, though the total number of lines of code you will be adding is quite small.

At a minimum, you will need to alter sysproc.c, syscall.h, syscall.c user.h, and usys.S to im- plement your new system calls.

You can test your implementation with provided testcases: hello.c and helloyou.c

Exploring OS State
We will be using the struct ptable in the remaining exercises. Whenever you access the ptable you must hold a lock - a synchronization primitive, before you start using it. Don't worry if you don't understand locks, we will learn about them in the upcoming weeks.

For now just make sure that if you need to use the ptable you follow the pattern :

. .
acquire(&ptable . lock );

// Make use of the ptable structure release(&ptable . lock ); // DO NOT FORGET THIS ! !

. .
got siblings?
We will implement a system call get_siblings_info() which prints the details of siblings (pro- cesses forked from the same parent process) of the calling process to the console.

get_siblings_info() should print process ID and process state of it's sibings in the follow- ing format.

...

Main Idea:

Find process ID of the calling process.
Find process ID of the parent process of the calling process.
Traverse the list of PCBs and compare their parent PID with parent of calling process.
Since this requires you to access the ptable, you will have to implement the main logic of your system call in proc.c le and then invoke this function from sysproc.h.

To implement this system call, you will need to understand struct ptable from proc.c and struct proc, enum procstate from proc.h.

Note: Details of calling process shouldn't be printed. Only sibling details should be printed.

You are given a sample my_siblings.c program that takes an integer n, followed by a combination of 0, 1 and 2 of length n, as command line arguments. This program creates n+1 child processes, the rst n child processes perform some task based on the input argument (0/1/2 specied for each of the n child processes). The last process executes your system call get_siblings_info()

and displays the output.

Add my_siblings.c as a user level program to test your implementation.

Sample run:

$ my siblings 6 1 2 1 0 2 0 4 RUNNABLE

5 ZOMBIE

6 RUNNABLE

7 SLEEPING

8 ZOMBIE

9 SLEEPING

parameterizing system calls (Optional - for those who want more challenge!) Implement a system call get_ancestors(), which takes a positive number n and a pointer
to an integer array as arguments.

get_ancestors(n, array)

This system call writes the process IDs of n parents of the calling process to the given array. Parent of calling process is at level 1. You can assume that the size of array is su cient enough

to hold the required details. If the number of ancestors is less than n, then the system call should collect PIDs till init process and return 0, otherwise, the system call should return 1.

To pass parameters to system call, understand how it is done for other system calls. You will have to use argint and argptr in syscall.c that we learnt in 1(b) of Part B.

Note: Make sure you handle the case when n is less than number of ancestors and you reach the init process.

You are also given a sample user-level program my_ancestors.c which takes two numbers as command line arguments and uses the system call. The rst argument is depth of forking and

the second is the parameter n passed to the system call. Add this as a user level program to xv6 and test your implementation.

Sample runs:

$ my_ancestors 6 10

Process: 97

Ancestors: 95 89 83 77 71 65 2 1 Return value: 0

the my_ancestors program creates 6 child process in a recursive manner and the get_ancestors(n, buf) system call is invoked from the 6th child process. Here, pid of the parent process is 65 and parent

pid of 6th child process is 95.

$ my_ancestors 5 3 Process: 59 Ancestors: 58 52 46 Return value: 1