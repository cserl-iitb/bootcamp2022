# Running C/CPP Programs and Makefiles

For this part of the assignment, we will go over creating a cpp program and compiling with ``gcc/g++`` compiler and executing it. The future assignments of the bootcamp will require you to use cpp for implementing multiple functionalities, so being familiar with the basics will be useful. 

This part of the assignment also includes the creation of simple makefiles. Make is a program building tool which runs on Unix, Linux, and their flavors. It aids in simplifying building program executables that may need various modules. To determine how the modules need to be compiled or recompiled together, ``make`` takes the help of user-defined makefiles.

## Requirements

Please make sure that you have the following tools installed on your system. It is preferable to use a Linux/Unix based operating system for the bootcamp.


- ``g++/gcc``: These are the compilers of C/C++ programs respectively. They are **present in a Linux system by default**. In case someone wants to install them on a Windows system, it can be done by installing ``MinGW`` ([Installation Video](https://www.youtube.com/watch?v=fsmVbLMzBoo)).
    
- ``Make``: It is highly recommended to use ``Linux`` system for this part (as it present in the system by default). Although, if you want to try ``make`` tool on windows, you can install it using a package manager ([Installation Steps](https://www.technewstoday.com/install-and-use-make-in-windows/)).

## Useful References

If you are familiar with compilation and execution of c/cpp programs via terminal, you can skip the first two references.

- [Executing a CPP Program](https://www.tutorialspoint.com/How-to-compile-and-run-the-Cplusplus-program) (Optional)
- [Executing a C Program](https://www.edureka.co/blog/how-to-compile-c-program-in-command-prompt/) (Optional)

- [MakeFile Tutorial1](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) (Don't Skip if you are a beginner)
- [MakeFile Tutorial2](https://riptutorial.com/makefile) (Optional)


## Exercises

1. Write and execute a C/C++ Program (``factors.cpp``/``factors.c``) to display the factors of an integer input by the user. Assume that you are given integer on terminal, print the factors space separated on the terminal.
    
    ```console
    Enter Number: 6
    Factors: 1 2 3 6
    ```

2. Write and execute a C/C++ Program (``complex.cpp``/``complex.c``) to add two complex numbers and return the result as a new complex number. This is to be done by creating a structure or class of Complex Number and creating a function ``add`` which takes two complex numbers as arguments and returns the result as a new complex number. Assume you are given two complex numbers (``a1 + i.a2``,  ``b1 + i.b2``) terminal in following order:
    
    ```console
    Enter first complex number: 2 10
    Enter second complex number: 4 9
    Result: 6 19
    ```
    
3. Consider the files in directory ``make_exercise`` in this assignment folder. 
- Using the files main.cpp, hello.cpp and factiorial.cpp create a single binary ``main``. Execute the program and check for correctness.
- Create a Makefile which will create a binary ``main`` (use ``gcc`` compiler) (using the files ``main.cpp``, ``hello.cpp``, ``factorial.cpp`` and ``functions.h``). Note that, you must use makefile variables like compiler (``CC``), flags (``CFLAGS``), dependencies (``DEPS``) in your makefile. 
