# Part B: New system calls in xv6 #

In this part we learn to add new system calls to the xv6 kernel.<br /> <br />
Ready? Start by understanding the system call path followed when a system call is invoked. A simple tutorial is [xv6-system-calls-how-it-works](https://medium.com/@flag_seeker/xv6-system-calls-how-it-works-c541408f21ff). You don't need to understand everything, just get an overview of the flow through kernel code on invocation of a system call and which files need to be modied to add a new system call.<br /><br />
Now look at an existing system call to understand how system calls are to be added. For example, look at how _**sysproc.c**_ implements system calls like <code>sys_fork</code> (which calls functions in other files).<br /><br />
You will implement the following new system calls in xv6.<br />
## Hello xv6 World! ##
1. Implement a system call, called <code>hello()</code>, which prints <code>Hi! Welcome to the world of xv6!</code> to the console. You can use <code>cprintf</code> for printing in kernel mode.
2. Next, we will implement a system call called <code>helloYou(name)</code> that takes an argument <code>char* name</code>. It prints name to the console. You can use <code>cprintf</code> for printing in kernel mode.<br /><br />
Check out the <code>open</code> system call in _**sysfile.c**_ that takes in multiple arguments like strings and integers, and returns a simple integer value.<br />
Also check <code>argint, argptr, argstr</code> functions and their descriptions in _**syscall.c**_.

**Hints:** You will need to modify a number of different files for this exercise, though the total number of lines of code you will be adding is quite small.<br />
At a minimum, you will need to alter _**sysproc.c, syscall.h, syscall.c user.h** and **usys.S**_ to implement your new system calls.<br /><br />
You can test your implementation with provided testcases: _**hello.c**_ and _**helloyou.c**_

## Exploring OS State ##
We will be using the <code>struct ptable</code> in the remaining exercises. Whenever you access <code>ptable</code> you must hold a _lock_ - a synchronization primitive, before you start using it. Don't worry if you don't understand locks, we will learn about them in the upcoming weeks.<br />
For now just make sure that if you need to use the <code>ptable</code> you follow the pattern :<br />
```
...
acquire(&ptable . lock );
// Make use of the ptable structure<br />
...
...
release(&ptable . lock ); // DO NOT FORGET THIS !!
...
```
### 1. **got siblings?**  
We will implement a system call <code>get_siblings_info()</code> which prints the details of siblings (processes forked from the same parent process) of the calling process to the console.<br /><br />
<code>get_siblings_info()</code> should print process ID and process state of it's siblings in the following format.<br />
```console
**pid procstate**
**pid procstate**
...
```
**Main Idea:**<br />
- Find process ID of the calling process.
- Find process ID of the parent process of the calling process.
- Traverse the list of PCBs and compare their parent PID with parent of calling process.<br /><br />
Since this requires you to access the <code>ptable</code>, you will have to implement the main logic of your system call in _**proc.c**_ file and then invoke this function from _**sysproc.h**_.<br /><br />
To implement this system call, you will need to understand <code>struct ptable</code> from _**proc.c**_ and <code>struct proc</code>, <code>enum procstate</code> from _**proc.h**_.<br /><br />
_**Note**_: Details of calling process shouldn't be printed. Only sibling details should be printed.<br /><br />
You are given a sample _**my_siblings.c**_ program that takes an integer n, followed by a combination of 0, 1 and 2 of length n, as command line arguments. This program creates n+1 child processes, the first n child processes perform some task based on the input argument (0/1/2 specied for each of the n child processes). The last process executes your system call <code>get_siblings_info()</code> and displays the output.<br /><br />
Add _**my_siblings.c**_ as a user level program to test your implementation.<br /><br />
**Sample run:**<br />
```console
$ ./my_siblings 6 1 2 1 0 2 0 
4 RUNNABLE
5 ZOMBIE
6 RUNNABLE
7 SLEEPING
8 ZOMBIE
9 SLEEPING
```

### 2. **parameterizing system calls** (Optional)
Implement a system call <code>get_ancestors()</code>, which takes a positive number n and a pointer to an integer array as arguments.<br />
<code>get_ancestors(n, array)</code><br /><br />
This system call writes the process IDs of n parents of the calling process to the given array. Parent of calling process is at level 1. You can assume that the size of array is su cient enough to hold the required details. If the number of ancestors is less than n, then the system call should collect PIDs till init process and return 0, otherwise, the system call should return 1.<br /><br />
To pass parameters to system call, understand how it is done for other system calls. You will have to use <code>argint</code> and <code>argptr</code> in _**syscall.c**_ that we learnt in 1(b) of Part B.<br /><br />
_**Note:**_ Make sure you handle the case when n is less than number of ancestors and you reach the init process.<br /><br />
You are also given a sample user-level program **my_ancestors.c** which takes two numbers as command line arguments and uses the system call. The rst argument is depth of forking and the second is the parameter n passed to the system call. Add this as a user level program to xv6 and test your implementation.<br /><br />
**Sample runs:**
```console
$ ./my_ancestors 6 10
Process: 97
Ancestors: 95 89 83 77 71 65 2 1
Return value: 0
```
the _**my_ancestors.c**_ program creates 6 child process in a recursive manner and the <code>get_ancestors(n, buf)</code> system call is invoked from the 6th child process. Here, pid of the parent process is 65 and parent pid of 6th child process is 95.<br /><br />
```console
$ ./my_ancestors 5 3
Process: 59
Ancestors: 58 52 46
Return value: 1
```
