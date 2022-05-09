Systems Bootcamp

OS Internals Track

Week-2

May 9, 2022

Background material for the lab

- You must cover these - Lectures 1, 2, 22, 3, 23, 4 from [Lectures on Operating Systems, in ](https://www.cse.iitb.ac.in/~mythili/os/)the order specied here.
- (Optional) Chapters 0, 1 from [this book](https://pdos.csail.mit.edu/6.828/2017/xv6/book-rev10.pdf)
- Link to the [PDF formatted xv6 source code if y](https://pdos.csail.mit.edu/6.828/2017/xv6/xv6-rev10.pdf)ou want the whole xv6 kernel code in one place. This doesn't include the user programs like ls, echo etc.

Before you begin the assignment

1. Download, install, and run the original xv6 OS code. You can use your regular desktop/laptop to run xv6; it runs on an x86 emulator called QEMU that emulates x86 hardware on your local machine. In the xv6 folder, run make, followed by make qemu or make-qemu-nox, to boot xv6 and open a shell. Detailed instructions are available [here.](https://www.cse.iitb.ac.in/~parthsangani/cs347m_s21/)
1. We have modied some xv6 les for this lab, and these patched les are provided as part of this lab's code. Before you begin the lab, copy the patched les into the main xv6 code directory.
1. For this lab, you will need to understand and modify following les: proc.c, proc.h, syscall.c, syscall.h, sysproc.c, defs.h, user.h, and usys.S. Below are some details on these les. You may want to revisit this for Part B.
- user.h contains the system call denitions in xv6.
- usys.S contains a list of system calls exported by the kernel, and the corresponding invocation of the trap instruction.
- syscall.h contains a mapping from system call name to system call number. Every system call must have a number assigned here.
- syscall.c contains helper functions to parse system call arguments, and pointers to the actual system call implementations.
- sysproc.c contains the implementations of process related system calls. All the new system calls that you add will be implemented here.
- defs.h is a header le with function denitions in the kernel.
- proc.h contains the struct proc structure.
- proc.c contains implementations of various process related system calls, and the scheduler func- tion. This le also contains the denition of ptable, so any code that must traverse the process list in xv6 must be written here.

gdbinit:jpg

Figure 1: GDB auto loading declined

Part A: User Programs in xv6

1. Debugging user programs on xv6 with gdb

Look at `Remote Debugging xv6 under QEMU' section of this[ page](https://web.archive.org/web/20190308091152/http://zoo.cs.yale.edu:80/classes/cs422/2011/lec/l2-hw) for details on how to start de- bugging xv6 using gdb.

Execute the user program debug and observe that the bubble sort implemented does not give the correct results. You have to nd the bug and make the program give the correct result.

1) In xv6 folder, run make followed by make qemu-gdb to run the QEMU emulator in debug-mode.
1) In other terminal, in the xv6 folder, run gdb kernel. This will automatically connect this gdb session to the xv6 session. If you see the error message as in gure 1,[ follo](#_page1_x268.41_y88.88)w the on screen instruction and alter .gdbinit as suggested on screen and redo the steps.
1) If the gdb sesssion does not connect to the xv6 session automatically, from the gdb interface run (gdb) target remote localhost:26000 where 26000 is the TCP port that step 1 reported at the end (this might change).
1) Load the user executable with (gdb) file debug.o.
1) Place a breakpoint (gdb) break main and continue with (gdb) continue
1) Now you can use the gdb commands as learnt in Week 1 assignment to debug further.
2. Adding user programs in xv6 A simple example is given [here.](https://www.geeksforgeeks.org/xv6-operating-system-add-a-user-program/)
1) After executing make qemuyou will see a prompt. The prompt is the xv6 command line interface to execute user level programs. Begin with ls and nd which programs exist and try executing them.

The source code for all programs is included as part of the xv6 distribution. Look up the im- plementation of these programs. For example, cat.c has the source code for the cat program. Execute and lookup the following: ls, cat, wc, echo, grep etc. Understand how the syntax in some places is dierent than normal C syntax.

Check the makefile to see how the program wc is set up for compilation. (You can search for wc in the le to see what additions are made.)

2) Modify the existing shell program sh.c in xv6 to change the shell prompt.

E.g. : turtle$

Hint : Just search where the existing shell prompt $ is and modify it.

3) Complete the program cmd.c so that it creates a child process, child process executes a program, and parent waits till completion of the child process before terminating. This program should use the fork and exec system call of xv6. The program to be executed by the child process can be one of the simple xv6 programs and will be specied at the command line.

Example usage:

./cmd ls

./cmd echo hello

We have already dened the arguments to be passed to exec for you in cmd.c. You have to use them and implement the core logic in the provided block

- . .

nn Implement your code here

nn

- . .
4) Modify the makefile and test your implementations.

Part B: New system calls in xv6

We will add a couple of new system calls to the xv6 kernel.

Ready? Start by understanding the system call path followed when a system call is invoked. A simple tutorial is [linked here. ](https://medium.com/@flag_seeker/xv6-system-calls-how-it-works-c541408f21ff)You don't need to understand everything, just get an overview of the ow through kernel code on invocation of a system call and which les need to be modied to add a new system call.

Now look at an existing system call to understand how system calls are to be added. For example, look at how sysproc.c implements system calls like sys\_fork (which calls functions in other les).

You will implement the following new system calls in xv6.

1. Hello xv6 World!
1) Implement a system call, called hello(), which prints Hi! Welcome to the world of xv6! to the console. You can use cprintf for printing in kernel mode.
1) Next, we will implement a system call called helloYou(name) that takes an argument char\* name. It prints name to the console. You can use cprintf for printing in kernel mode.

Check out the open system call in sysfile.c that takes in multiple arguments like strings and integers, and return a simple integer value.

Also check argint, argptr, argstr functions and their descriptions in syscall.c.

Hints: You will need to modify a number of dierent les for this exercise, though the total number of lines of code you will be adding is quite small.

At a minimum, you will need to alter sysproc.c, syscall.h, syscall.c user.h, and usys.S to im- plement your new system calls.

You can test your implementation with provided testcases: hello.c and helloyou.c

2. Exploring OS State

We will be using the struct ptable in the remaining exercises. Whenever you access the ptable you must hold a lock - a synchronization primitive, before you start using it. Don't worry if you don't understand locks, we will learn about them in the upcoming weeks.

For now just make sure that if you need to use the ptable you follow the pattern :

- . .

acquire(&ptable . lock );

// Make use of the ptable structure release(&ptable . lock ); // DO NOT FORGET THIS ! !

- . .
1) got siblings?

We will implement a system call get\_siblings\_info() which prints the details of siblings (pro- cesses forked from the same parent process) of the calling process to the console.

get\_siblings\_info() should print process ID and process state of it's sibings in the follow- ing format.

<pid> <procstate>

<pid> <procstate>

...

Main Idea:

1. Find process ID of the calling process.
1. Find process ID of the parent process of the calling process.
1. Traverse the list of PCBs and compare their parent PID with parent of calling process.

Since this requires you to access the ptable, you will have to implement the main logic of your system call in proc.c le and then invoke this function from sysproc.h.

To implement this system call, you will need to understand struct ptable from proc.c and struct proc, enum procstate from proc.h.

Note: Details of calling process shouldn't be printed. Only sibling details should be printed.

You are given a sample my\_siblings.c program that takes an integer n, followed by a combination of 0, 1 and 2 of length n, as command line arguments. This program creates n+1 child processes, the rst n child processes perform some task based on the input argument (0/1/2 specied for each of the n child processes). The last process executes your system call get\_siblings\_info()

and displays the output.

Add my\_siblings.c as a user level program to test your implementation.

Sample run:

$ my siblings 6 1 2 1 0 2 0 4 RUNNABLE

5 ZOMBIE

6 RUNNABLE

7 SLEEPING

8 ZOMBIE

9 SLEEPING

2) parameterizing system calls (Optional - for those who want more challenge!) Implement a system call get\_ancestors(), which takes a positive number n and a pointer

to an integer array as arguments.

get\_ancestors(n, array)

This system call writes the process IDs of n parents of the calling process to the given array. Parent of calling process is at level 1. You can assume that the size of array is su cient enough

to hold the required details. If the number of ancestors is less than n, then the system call should collect PIDs till init process and return 0, otherwise, the system call should return 1.

To pass parameters to system call, understand how it is done for other system calls. You will have to use argint and argptr in syscall.c that we learnt in 1(b) of Part B.

Note: Make sure you handle the case when n is less than number of ancestors and you reach the init process.

You are also given a sample user-level program my\_ancestors.c which takes two numbers as command line arguments and uses the system call. The rst argument is depth of forking and

the second is the parameter n passed to the system call. Add this as a user level program to xv6 and test your implementation.

Sample runs:

$ my\_ancestors 6 10

Process: 97

Ancestors: 95 89 83 77 71 65 2 1 Return value: 0

the my\_ancestors program creates 6 child process in a recursive manner and the get\_ancestors(n, buf) system call is invoked from the 6th child process. Here, pid of the parent process is 65 and parent

pid of 6th child process is 95.

$ my\_ancestors 5 3 Process: 59 Ancestors: 58 52 46 Return value: 1

Submission Guidelines

1. Name your submission as: <id>\_week2.tar.gz

5

2. The tar should contain the following les <id>\_week2>/

k\_\_\_\_debug.c

k\_\_\_\_sh.c

k\_\_\_\_head.c

k\_\_\_\_cmd.c

k\_\_\_\_<all modified files in xv6> k\_\_\_\_Makefile

in the following directory structure:



3. We will evaluate your submission by reading through your code, executing it with dierent test cases. Make sure all les updated and required for compilation are part of the submission.
3. Deadline:

