Part A: User Programs in xv6

Debugging user programs on xv6 with gdb
Look at `Remote Debugging xv6 under QEMU' section of this page for details on how to start de- bugging xv6 using gdb.

Execute the user program debug and observe that the bubble sort implemented does not give the correct results. You have to nd the bug and make the program give the correct result.

In xv6 folder, run make followed by make qemu-gdb to run the QEMU emulator in debug-mode.
In other terminal, in the xv6 folder, run gdb kernel. This will automatically connect this gdb session to the xv6 session. If you see the error message as in gure 1, follow the on screen instruction and alter .gdbinit as suggested on screen and redo the steps.
If the gdb sesssion does not connect to the xv6 session automatically, from the gdb interface run (gdb) target remote localhost:26000 where 26000 is the TCP port that step 1 reported at the end (this might change).
Load the user executable with (gdb) file debug.o.
Place a breakpoint (gdb) break main and continue with (gdb) continue
Now you can use the gdb commands as learnt in Week 1 assignment to debug further.
Adding user programs in xv6 A simple example is given here.
After executing make qemuyou will see a prompt. The prompt is the xv6 command line interface to execute user level programs. Begin with ls and nd which programs exist and try executing them.
The source code for all programs is included as part of the xv6 distribution. Look up the im- plementation of these programs. For example, cat.c has the source code for the cat program. Execute and lookup the following: ls, cat, wc, echo, grep etc. Understand how the syntax in some places is dierent than normal C syntax.

Check the makefile to see how the program wc is set up for compilation. (You can search for wc in the le to see what additions are made.)

Modify the existing shell program sh.c in xv6 to change the shell prompt.
E.g. : turtle$

Hint : Just search where the existing shell prompt $ is and modify it.

Complete the program cmd.c so that it creates a child process, child process executes a program, and parent waits till completion of the child process before terminating. This program should use the fork and exec system call of xv6. The program to be executed by the child process can be one of the simple xv6 programs and will be specied at the command line.
Example usage:

./cmd ls

./cmd echo hello

We have already dened the arguments to be passed to exec for you in cmd.c. You have to use them and implement the core logic in the provided block

. .
nn Implement your code here

nn

. .
Modify the makefile and test your implementations.
