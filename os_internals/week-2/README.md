## OS Internals Track,  Week2

### Overview ###
Topics of this week's exercise,
- Process abstraction and processes in xv6
- System calls for process management and using xv6 system calls
- Adding new user programs and new system calls in xv6 
- Debugging xv6 user code and kernel code with gdb


### Background Material for the week:

- You must cover these - Lectures 1, 2, 22, 3, 23, 4 from [Lectures on Operating Systems](https://www.cse.iitb.ac.in/~mythili/os/), in the order specified here.
- (Optional) Chapters 0, 1 from [this book](https://pdos.csail.mit.edu/6.828/2017/xv6/book-rev10.pdf)
- For this lab, you will need to understand and modify following files: _**proc.c, proc.h, syscall.c, syscall.h, sysproc.c, defs.h, user.h**_ and _**usys.S**_. Below are some details on these files.
  - _**user.h**_ contains the system call denitions in xv6.
  - _**usys.S**_ contains a list of system calls exported by the kernel, and the corresponding invocation of the trap instruction.
  - _**syscall.h**_ contains a mapping from system call name to system call number. Every system call must have a number assigned here.
  - _**syscall.c**_ contains helper functions to parse system call arguments, and pointers to the actual system call implementations.
  - _**sysproc.c**_ contains the implementations of process related system calls. All the new system calls that you add will be implemented here.
  - _**defs.h**_ is a header file with function denitions in the kernel.
  - _**proc.h**_ contains the struct proc structure.
  - _**proc.c**_ contains implementations of various process related system calls, and the scheduler function. This file also contains the denition of <code>ptable</code>, so any code that must traverse the process list in xv6 must be written here.

<!--
### Before you begin the assignment:

1. Download, install, and run the original xv6 OS code. You can use your regular desktop/laptop to run xv6; it runs on an x86 emulator called QEMU that emulates x86 hardware on your local machine. In the xv6 folder, run **make**, followed by **make qemu** or **make-qemu-nox**, to boot xv6 and open a shell. Detailed instructions are available [here](https://www.cse.iitb.ac.in/~parthsangani/cs347m_s21/).
2. We have modied some xv6 files for this lab, and these patched files are provided as part of this lab's code. Before you begin the lab, copy the patched files into the main xv6 code directory. -->

### Work through the material provided and then attempt the assignment: ###
1. Assignment contains two parts---
- [Part A](https://github.com/cserl-iitb/bootcamp2022/tree/main/os_internals/week-2/part_a) and 
- [Part B](https://github.com/cserl-iitb/bootcamp2022/tree/main/os_internals/week-2/part_b)
2. Part-B.2.b  **Optional - but interesting and slightly challenging.**.


