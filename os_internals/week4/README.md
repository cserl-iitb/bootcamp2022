# Memory Management in OS

In this week, you will learn how the memory is managed by the OS.

> ## Materials and background of this week

Please watch the lecture videos in the series as given:

1. **Introduction to virtual memory**: 
   - [Video](https://www.youtube.com/watch?v=2Xj2V8kYNWM)
   - [Slide](https://drive.google.com/file/d/1hJjGopKu3vZzukcyo4v_NfyZ2bYThCCU/view?usp=sharing)
   - Reference from the OSTEP book: Chapter 13, Chapter 14
2. **Mechanism of address translation**: 
   - [Video](https://www.youtube.com/watch?v=mYxkp5vpyqc&t=1s)
   - [Slide](https://drive.google.com/file/d/1OC5O6GbhZiPnOuyzCkwzsLtqXBcAsE5W/view?usp=sharing)
   - Reference from the OSTEP book: Chapter 15
3. **Paging**: 
   - [Video](https://www.youtube.com/watch?v=PTh2kL8ENzU)
   - [Slide](https://drive.google.com/file/d/1MthC20Ky2gOeOaII6EL0nm5_dozrg64H/view?usp=sharing)
   - Reference from the OSTEP book: Chapter 18, Chapter 20
4. **Demand Paging**: 
   - [Video](https://www.youtube.com/watch?v=r9NwqtqS2Ac)
   - [Slide](https://drive.google.com/file/d/1sRHQdA1c3QnPZoypeqs4xMMWsRQHCTIp/view?usp=sharing)
   - Reference from the OSTEP book: Chapter 21, Chapter 22
5. **Virtual memory and paging in xv6**: 
   - [Video](https://www.youtube.com/watch?v=67Q7tfUk6pI)
   - [Slide](https://drive.google.com/file/d/1TQW1GADdIO1kPHnvIbgVD4j9vtsx5OiK/view?usp=sharing)
6. **Memory management for user processes in xv6**: 
   - [Video](https://www.youtube.com/watch?v=8V2YkO7lfvs&t=1s)
   - [Slide](https://drive.google.com/file/d/1fbBC2YfuC_qJ0YpIobAWLsGggY5nDtnf/view?usp=sharing)

**(Optional)** Here are some practice problems if you want to work out
some problems on memory management:

- [Link1](https://drive.google.com/file/d/17-Sl23RbpO8vqEa6xRzm2yV391V5qh5e/view?usp=sharing)     
- [Link2](https://drive.google.com/file/d/1sKMQo0PVn-ZU4djUCQi4HKiilwts-oyY/view?usp=sharing)

------------------------------------------------------------

> ## Exercise

**Before you begin**

1. For this lab, you will need to understand the following files: `syscall.c`, `syscall.h`,
`sysproc.c`, `user.h`, `usys.S`, `vm.c`, `proc.c`, `trap.c`, `defs.h`, `mmu.h`.
   - `user.h` contains the system call definitions in xv6, which are exported to userspace programs.
   - `usys.S` contains code to invoke the trap instruction for each system call.
   - `syscall.h` contains a mapping from system call name to system call number. Every system call must have a number assigned here.
   - `syscall.c` contains helper functions to parse system call arguments and pointers to the actual system call implementations.
   - `sysproc.c` contains the implementations of process-related system calls.
   - `proc.c` contains the `struct proc` structure. It contains implementations of various process-related system calls, and the scheduler function. This file also contains the definition of `ptable`, so any code that must traverse the process list in xv6 must be written here.
   - `defs.h` is a header file with function definitions in the kernel. All the functions defined in a file must also be defined here in the section of that file name. For example, if you make a new function in `vm.c`, then you also have to define the function in `vm.c` section of `defs.h`.
   - `mmu.h` is also a header file with various useful definitions pertaining to memory management. You do not have to change anything in this file but read it carefully.
   - The file `vm.c` contains most of the logic for memory management in the xv6 kernel, and `proc.c` contains process-related system call implementations. The functions written here are used in `proc.c` indirectly with the help of `defs.h`.
   - The file `trap.c` contains trap handling code for all traps including page faults.
   - Understand the implementation of the `sbrk` system call that spans all of these files.
   - Understand the `growproc` system call in `proc.c`.

2. We have provided testcases for this exercise. You must recall from previous weeks how to add these testcases in makefile, so that these can run on xv6.


**IMPORTANT**: Refer to the system calls which are already there to edit these files
accordingly. For example, you can refer to, say, `kill` system call. See how it is
defined in all the above-mentioned files, how it is made related to `proc.c` (where
you will actually define the functionality of the system calls), and how it is also
defined in `defs.h`.

**_Remember_, always read completely a particular file, and make the changes
wherever required, to make the new system call work perfectly fine.**

-----------------------------------------------------------

> ## **Assignment**

- [PART-A](Assignment/partA/README.md)
- [PART-B](Assignment/partB/README.md)

For this assignment, you have been provided with testcases and respective expected outputs. Run the test cases and verify your outputs with the given outputs.

---------------------------------------------------------

> ## Submission

Put all the changed or created file inside a folder and push it to your git repository.
