## Part A: User Programs in xv6

In this part we will learn how to 

- Debug user programs and xv6 kernel under QEMU using GDB's remote debugging feature and QEMU's remote GDB debugging stub
- Add new user programs to xv6

### Debugging user programs on xv6 with gdb
Look at `Remote Debugging xv6 under QEMU' section of [this page](https://web.archive.org/web/20190308091152/http://zoo.cs.yale.edu:80/classes/cs422/2011/lec/l2-hw) for details on how to start de-bugging xv6 using gdb.
1. In xv6 folder, run **make** followed by **make qemu-nox-gdb** to run the QEMU emulator in debug-mode.
2. In other terminal, in the xv6 folder, run **gdb kernel**. This will automatically connect this gdb session to the xv6 session. If you see the error message as in figure 1, follow the on screen instruction and alter .gdbinit as suggested on screen and redo the steps.
3. If the gdb sesssion does not connect to the xv6 session automatically, from the gdb interface run **(gdb) target remote localhost:26000** where 26000 is the TCP port that step 1 reported at the end (this might change).
4. Load the user executable with **(gdb) file debug.o.**
5. Place a breakpoint **(gdb) break main** and continue with **(gdb) continue.**
6. Now you can use the gdb commands as learnt in Week 1 assignment to debug further.
<p align="center">
  <img width="460" height="300" src="https://user-images.githubusercontent.com/81876291/167428724-d25223ec-4685-47a4-8935-b676d4815167.png">
</p>
<p align="center">
  Figure 1: GDB auto loading declined
</p>
 
Execute the user program **debug** and observe that the bubble sort implemented does not give the correct results. You have to find the bug and make the program give the correct result.
 
### Adding user programs in xv6
A simple example is given [here](https://www.geeksforgeeks.org/xv6-operating-system-add-a-user-program/).

1. After executing <code>make qemu</code> you will see a prompt. The prompt is the xv6 command line interface to execute user level programs. Begin with <code>ls</code> and <code>find</code> programs and try executing them.<br /><br />
The source code for all programs is included as part of the xv6 distribution. Look up the implementation of these programs. For example, **cat.c** has the source code for the <code>cat</code> program. Execute and lookup the following: <code>ls, cat, wc, echo, grep</code>. Understand how the syntax in some places is different than normal C syntax.<br /><br />
Check the _**makefile**_ to see how the program <code>wc</code> is set up for compilation. (You can search for wc in the file to see what additions are made.)

2. Modify the existing shell program _**sh.c**_ in xv6 to change the shell prompt. E.g.
```console
<code>turtle$</code><br />
```
**Hint** : In the file search where the existing shell prompt <code>$</code> is and modify it.

3. Complete the program _**cmd.c**_ so that it creates a child process, child process executes a program, and parent waits till completion of the child process before terminating. This program should use the <code>fork</code> and <code>exec</code> system call of xv6. The program to be executed by the child process can be one of the simple xv6 programs and will be specied at the command line.<br />
Example usage:<br />
```console
./cmd ls
```
```console
./cmd echo hello
```
We have already defined the arguments to be passed to <code>exec</code> for you in _**cmd.c**_. You have to use them and implement the core logic in the provided block<br />
```
...
\\ Implement your code here

\\
...
```
4. Modify the _**makefile**_ and test your implementations.
