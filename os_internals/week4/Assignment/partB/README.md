### _**PART-B: Allocating memory on demand (memory map)**_

**IMPORTANT:** Memory-mapped page means the pages that have been allocated by
the `mmap` system call.

- You will implement a simple version of the `mmap` system call (just like `sbrk`
system call) in xv6. Your `mmap` system call should take one argument: the
number of bytes to add to the address space of the process. The number of
bytes must be a positive number and a multiple of page size (the page size in
xv6 should be known to you).

- The system call should **return** a value of **0** if any invalid inputs are provided. If
a valid number of bytes is provided, the system call should expand the virtual
address space of the process by the specified number of bytes, and **return**
the **starting virtual address** of the newly added memory region.

- The new virtual pages should be added at the _end of the current program
break_ (the current program break is the location just after the heap section of
the process) and should increase the program size correspondingly. However,
the system call should NOT allocate any physical memory corresponding to
the new virtual pages, as we will allocate memory on demand. You can use
the system calls of the previous part to print these page counts to verify your
implementation.

- After the `mmap` system call, and before any access to the mapped-memory
pages, you should only see the number of virtual pages of a process increase,
but not the number of physical pages. Physical memory for a
memory-mapped virtual page should be allocated on demand, only when the
page is accessed by the user. When the user accesses a memory-mapped
page, a page fault will occur, and physical memory should only be allocated
as part of the page fault handling. Further, if you have added more than one
page in the virtual address using `mmap` system call, then physical memory
should only be allocated for those pages that are accessed, and not for all
newly added pages. Once again, use the virtual/physical page counts to verify
that physical pages are allocated only on demand.

- We have provided a simple test program to test your implementation. This
program invokes `mmap` multiple times and accesses the memory-mapped
pages. It prints out virtual and physical page counts periodically, to let you
check whether the page counts are being updated correctly. You can write
more such test cases to thoroughly test your implementation.


_**Hints to solve this part**_

- Understand the implementation of the `sbrk` system call. Your `mmap` system
call will follow a similar logic. In `sbrk`, the virtual address space is increased
and physical memory is allocated within the same system call. The
implementation of `sbrk` invokes the `growproc` function, which in turn
invokes the `allocuvm` function to allocate physical memory. For your `mmap`
implementation, you must only grow the virtual address space within the
system call implementation, and physical memory must be allocated during
the page fault. You may invoke `allocuvm` (or write another similar function)
in order to allocate physical memory _during a page fault_.

- The original version of xv6 does not handle the page fault trap. For this
assignment, you must write extra code to handle the page fault trap in
`trap.c`, which will allocate memory on demand for the page that has caused
the page fault. You can check whether a trap is a page fault by checking if
`tf->trapno` is equal to `T_PGFLT`. Look at the arguments to the `cprintf`
statements in `trap.c` to figure out how one can find the virtual address that
caused the page fault. Use `PGROUNDDOWN(va)` to round the faulting virtual
address down to the start of a page boundary. Once you write code to handle
the page fault, do return in order to avoid the processing of other traps.

- _**Remember**_: it is important to call `switchuvm` to update the CR3 register and
TLB every time you change the page table of the process. This update to the
page table will enable the process to resume execution when you handle the
page fault correctly.
