### _**PART-A: Understanding the memory information**_

You will first implement the following new system calls in xv6.

- `numvp()` should return the number of virtual pages in the user part of the
address space of the process, up to the program stored in `struct proc`.

- `numpp()` should return the number of physical pages in the user part of the
address space of the process. You must count this number by walking the
process page table, and counting the number of page table entries that have
a valid physical address assigned.

**HINT:**

➔ For `numpp()`, you can walk the page table of the process by using the `walkpgdir` function
which is present in `vm.c`. You can find several examples of how to invoke this
function within `vm.c` itself. To compute the number of physical pages in a
process, you can write a function that walks the page table of a process in
`vm.c`, and invoke this function from the system call handling code. You can
count a page if its present bit is set.

➔ For `numvp()`, you can find the program size in the PCB of the process and
divide it by `PGSIZE`.
