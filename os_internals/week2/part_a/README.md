# Part A: User Programs in xv6

In this part we will learn how to 

- Debug user programs and xv6 kernel under QEMU using GDB's remote debugging feature and QEMU's remote GDB debugging stub
- Add new user programs to xv6

## 1. Debugging user programs on xv6 with gdb
**Note**: For this question, in the Makefile, replace the line where `CFLAGS` is first defined with:
```
CFLAGS = -fno-pic -static -fno-builtin -fno-strict-aliasing -Wall -MD -ggdb -m32 -Werror -fno-omit-frame-pointer -gdwarf-2 -fno-inline-small-functions -O0
```
and change number of CPUs to 1 (replacing `CPUS := 2` with `CPUS := 1`).

Look at `Remote Debugging xv6 under QEMU' section of [this page](https://web.archive.org/web/20190308091152/http://zoo.cs.yale.edu:80/classes/cs422/2011/lec/l2-hw) for details on how to start de-bugging xv6 using gdb.

[This video](https://drive.google.com/file/d/1gkn6y4VSBh_py3wMYMrM2QFrE2vbYMpl/view?usp=sharing) traces the open system call using the ls program using gdb.
- In xv6 folder, run **make** followed by **make qemu-nox-gdb** to run the QEMU emulator in debug-mode.
- In other terminal, in the xv6 folder, run **gdb kernel**. This will automatically connect this gdb session to the xv6 session. If you see the error message as in figure 1, follow the on screen instruction and alter .gdbinit as suggested on screen and redo the steps OR from the gdb interface, run **(gdb) target remote localhost:26000** where 26000 is the TCP port that step 1 reported at the end (this might change).
<p align="center">
  <img width="460" height="300" src="https://user-images.githubusercontent.com/81876291/167428724-d25223ec-4685-47a4-8935-b676d4815167.png">
</p>
<p align="center">
  Figure 1: GDB auto loading declined
</p>
 
- Add the provided _**debug.c**_ in the _**Makefile**_ like other testcases.
- Run **(gdb) symbol-file _debug**.
- Place a breakpoint **(gdb) break main** and continue with **(gdb) continue.**
- In XV-6 terminal run **$ debug**.

Now, give answers to the following questions while tracing the execution of the fork system call in it:<br />
1. List the different functions which are encountered after `int ret = fork()` is run until `fork` function in _**proc.c**_ is called.
2. While in the function `trap` in _**trap.c**_, print the trap number for `T_SYSCALL`.
3. While in the function `syscall` in _**syscall.c**_, print the system call number.
4. While in the `fork` function (in _**proc.c**_), after the new process is created, print the name, pid, state of the new program and that of its parent.

## 2. Adding user programs in xv6
<!--A simple example is given [here](https://www.geeksforgeeks.org/xv6-operating-system-add-a-user-program/).-->
After executing <code>make qemu</code> or <code>make qemu-nox</code> you will see a prompt. The prompt is the xv6 command line interface to execute user level programs. <br /> <br /> 
We have provided a very simple user program _**testcase.c**_ which prints <code>Hello, world!</code> to the terminal and the modified _**makefile**_. <br />
Check the _**makefile**_ to see how the program <code>testcase</code> is set up for compilation. (You can search for testcase in the file to see what additions are made.)<br />
Try executing this user program as follows: 
```console
$ ./testcase
Hello, world!
```
The xv6 distribution also has source code for many user programs. Look up the implementation of these programs. For example, **cat.c** has the source code for the <code>cat</code> program. Execute and lookup the following: <code>ls, cat, wc, echo, grep</code>. Understand how the syntax in some places is different than normal C syntax.<br /><br />

**Now let's write some code! <br />**
1. Modify the existing shell program _**sh.c**_ in xv6 to change the shell prompt. E.g.
```console
turtle$
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**Hint** : In the file search where the existing shell prompt <code>$</code> is and modify it.
<br /> <br />

2. Complete the program _**cmd.c**_ so that it creates a child process, child process executes a program, and parent waits till completion of the child process before terminating. This program should use the <code>fork</code> and <code>exec</code> system call of xv6. The program to be executed by the child process can be one of the simple xv6 programs and will be specied at the command line.<br />
Example usage:<br />
```console
./cmd ls
```
```console
./cmd echo hello
```
We have already defined the arguments to be passed to <code>exec</code> for you in _**cmd.c**_. You have to use them and implement the core logic in the provided block<br />
```
\\ Implement your code here
... your code ...
\\
```

3. Modify the _**makefile**_ and test your implementations.
