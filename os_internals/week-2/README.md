## OS Internals Track Week-2

### Material for the lab:

- You must cover these - Lectures 1, 2, 22, 3, 23, 4 from [Lectures on Operating Systems](https://www.cse.iitb.ac.in/~mythili/os/), in the order specied here.
- (Optional) Chapters 0, 1 from [this book](https://pdos.csail.mit.edu/6.828/2017/xv6/book-rev10.pdf)
- Link to the [PDF formatted xv6 source code](https://pdos.csail.mit.edu/6.828/2017/xv6/xv6-rev10.pdf) if you want the whole xv6 kernel code in one place. This doesn't include the user programs like **ls, echo** etc.

### Before you begin the assignment

1. Download, install, and run the original xv6 OS code. You can use your regular desktop/laptop to run xv6; it runs on an x86 emulator called QEMU that emulates x86 hardware on your local machine. In the xv6 folder, run **make**, followed by **make qemu** or **make-qemu-nox**, to boot xv6 and open a shell. Detailed instructions are available [here](https://www.cse.iitb.ac.in/~parthsangani/cs347m_s21/).
2. We have modied some xv6 files for this lab, and these patched files are provided as part of this lab's code. Before you begin the lab, copy the patched files into the main xv6 code directory.
3. For this lab, you will need to understand and modify following files: **proc.c, proc.h, syscall.c, syscall.h, sysproc.c, defs.h, user.h** and **usys.S**. Below are some details on these files. **You may want to revisit this for Part B**.
- **user.h** contains the system call denitions in xv6.
- **usys.S** contains a list of system calls exported by the kernel, and the corresponding invocation of the trap instruction.
- **syscall.h** contains a mapping from system call name to system call number. Every system call must have a number assigned here.
- **syscall.c** contains helper functions to parse system call arguments, and pointers to the actual system call implementations.
- **sysproc.c** contains the implementations of process related system calls. All the new system calls that you add will be implemented here.
- **defs.h** is a header le with function denitions in the kernel.
- **proc.h** contains the struct proc structure.
- **proc.c** contains implementations of various process related system calls, and the scheduler func- tion. This le also contains the denition of ptable, so any code that must traverse the process list in xv6 must be written here.

Work through the material provided and then attempt the assignment:
1. Assignment contains two parts(A and B).
2. Part-B.c is **Optional - for those who want more challenge!**.

### Submission Guidelines:

