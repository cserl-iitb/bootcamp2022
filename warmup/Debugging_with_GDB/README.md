## Debugging with GDB

In this part of the assignment, we will give you a high-level introduction to GDB. GDB, short for GNU Debugger, is a simple and intuitive debugger used on Unix systems to debug C and C++ programs. Rather than inserting <code>cout</code> statements at different points in the program, GDB will allow you to `step' through the program as it executes line by line to understand exactly where errors are occurring.

### Learning GDB

To install gdb on your Unix system, understand some of the major commands used, and look at examples of debugging done using gdb, work through [this](https://www.tutorialspoint.com/gnu_debugger/gdb_quick_guide.htm) short guide from start to finish.

For a more advanced understanding of how gdb works, you can refer to [this](http://web.mit.edu/gnu/doc/html/gdb_toc.html) link (this reading is not mandatory).

### Exercises

For both the below exercises, log all the gdb commands you use to debug the programs by issuing the following commands just after you start gdb and before you start debugging:

- (gdb) set logging overwrite on
- (gdb) set trace-commands on
- (gdb) set logging on

1. Compile and run <code>pointers.cpp</code>. A segmentation fault will be observed. Use gdb to step through the program as it runs, and locate line of the program that causes this error and fix the bug.

2. Compile and run <code>fibbonaci.cpp</code>. The program will run successfully. This program is meant to print the first <code>n+2</code> terms of the Fibonacci sequence, where <code>n</code> is specified in line 6 of the program. However, the output of the code as given clearly does not match this requirement. A single logical bug in the code is causing this error. Use gdb to step through the program as it runs, locate and fix the bug.

