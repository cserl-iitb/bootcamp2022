# Shell Scripting

Shell is an open-source computer program designed to be run by Unix/Linux. Shell scripting is a program to write a series of commands for the shell to execute. It can combine lengthy and repetitive sequences of commands into a single and simple script that can be stored and executed anytime, which reduces programming efforts. This part of the assignment will help you to gain a basic understanding of the Linux/Unix shell scripting program.


## Useful References

If you are a complete beginner (no experience in shell scripts), please go through at least the **first** reference below, else you can skip it. The **second reference is optional**. Also, while doing the exercises, feel free to ask the TAs or google things.

- [Intro to Shell Scripting](https://www.guru99.com/introduction-to-shell-scripting.html)
- [Shell Scripts - TutorialsPoint](https://www.tutorialspoint.com/unix/shell_scripting.htm) (Optional)

## Examples of Shell Scripts

- A shell script that prints “Summer Bootcamp 2022!” on the screen.

    ```console
    #!/bin/bash
    echo "Summer Bootcamp 2022!"
    ```
- A shell script that prints numbers 1 to 10 in descending order.

    ```console
    #!/bin/bash
    for (( counter=10; counter>0; counter-- ))
    do
    echo -n "$counter "
    done
    printf "\n"
    ```

## Exercises

    
1. Write a shell script ``array.sh`` that displays "man","bear", "pig", "dog", "cat", and "sheep" on the screen with each appearing on a separate line. Try to do this in as few lines as possible. (Hint: Use an array/list and for loop)
    
    Usage: ``./array.sh``

2. Write a shell script ``digitsum.sh`` that find the sum of digit of a number provided as argument.
       
    Usage: ``./digitsum.sh <num>``
    
3. Write ``dirs.sh`` that makes a directory ``root`` and then makes five subdirectories: ``root/dir1`` through ``root/dir5``. Then, in each subdirectory, the script should make four files, ``file1`` through ``file4``, such that ``file1`` has one line containing the digit ``1``, ``file2`` has two lines, each containing the digit ``2``, ..., and ``file4``
has four lines, each containing the digit ``4``.
    
    Usage: ``./dirs.sh``
