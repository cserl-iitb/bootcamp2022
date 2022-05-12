# Week-3

Welcome to the task of week-3. Till now you have installed xv6 and have written some basic system calls, which may have given you an idea of how processes in an operating system works in general. Even if you don’t feel confident working with xv6 yet, don’t worry, just keep learning and practising and you will slowly start getting a hang of it. 
There is no extra reading material for this week, just follow the previous week's content. In addition to it, you can refer the OSTEP textbook chapters mentioned alongside the respective lectures on [Lectures on Operating Systems](https://www.cse.iitb.ac.in/~mythili/os/)(This is really a very good reading material, and it is strongly suggested to follow it). 

Moving on to the task for this week. This week you will improve upon the system calls and will implement a mechanism to communicate with or signal between two system calls. There is an optional problem at the end which you can attempt for extra challenge. The tasks here start from easy level and the difficulty or complexity would keep on increasing as you go further. Have a good time learning and exploring!

<hr>

## 1. Find out the PID of the parent process

Currently, in xv6, if you wish to find out the PID of the current process, you can but there is no mechanism/system call to find out the PID of the parent. 
In the first task of this week, you will write a new system call named `getppid()` which will find out the PID of the parent of the current process. 
This system call will be used in the next question, so don't skip this one. Remember, whenever you try to write a new system call, 
you have to repeat all the steps of writing a new system call which you learnt last week, i.e. making changes to usys.h, syscall.h etc.

_(Hint : To write the system call getppid(), inside the syscall definition, you will have to define a new struct for parent of the 
current process and then get its pid.)_

## 2. Who will adopt the orphaned?

In this exercise, you will change one of the default functionality of xv6. An orphan (child) process is one whose parent process has finished or terminated, but the process(child) itself continues to execute. In xv6 (and other Unix-like operating systems), an orphaned process will be immediately adopted by a special process (usually the init process, with pid 1). You will change this feature such that an orphaned process will be adopted by its closest ancestor instead of the init process. As a special case, the closest ancestor can be the init process as well.

Now let’s say we have designed such an algorithm, but how will we know whether our mechanism has worked or not! For this we should somehow get the pid of the parent of the process which has been terminated and then verify whether that’s actually the one which has adopted the child. Here's where the system call `getppid()` will come into use.

Below are some hints for you to solve the problem. It is suggested to try the problem first before scrolling below, and if you aren’t able to do it, refer below.

1. Assuming we have the system call `getppid()` with us, you have to assign the abandoned children to the parent of the terminated process. Think and identify which system call would you make changes to. It should be the one, which is called by the process before it is terminated. 
2. Now that you have identified the system call, read through it and identify which section of the code takes care of the abandoned children. Make appropriate changes to it.


## 3. Signalling between processes

In this part of the task, you will try to communicate between two processes through the use of signals. Signals, as their name implies, used to signal something. Signals are user-level mechanisms for processes to communicate via events (signals). In this exercise we will add a feature to xv6 that enables inter-process communication through signals.

You are supposed to add a new `signal_process(pid, type)` system call, where _pid_ is the process id to which signal is to be sent and _type_ is the type of the signal being sent which can be either of `{PAUSE, KILL, CONTINUE}`. If an user-level program calls `signal_process(pid, type)`, then a signal is delivered to the process pid immediately and the corresponding process handles it as soon as it gets sched- uled next time. The type of the signal determines the action to be taken, i.e., the signal _PAUSE_ makes the process non-executable/non-schedulable, _CONTINUE_ releases a paused processes to continue execution, and _KILL_ terminates the process. Note that a paused process makes no progress (is never scheduled to execute) and, a process continues from where it left off after a pause.

You have been given a boilerplate script(which means some part of the code already written for you) of the system call function which you have to implement. Read through the script and you will get an idea of what has to be done. The file is named as `Week3_signal_skeleton_code.md`

You are also given a test program `signal-test.c` to check your final code. Run this at the end to check whether the solution that you have made is correct or not.

_Remember:_

1. Whenever you try to write a new system call, you have to repeat all the steps of writing a new system call which you learnt last week.
2. Do not pass arguments directly, you have to use helper functions argint, argstr.

_Steps to solve:_
1. To execute the _pause_ type, you have to define a new variable in the struct `proc`, whose value will be changed when the argument _PAUSE_ is passed. This variable will be checked everytime by the scheduler, if it is found that the variable is changed, the scheduler will not run that process.
2. Remember, you have to change the value to some default when the arguments _CONTINUE_ and _KILL_ are passed.

## 4. How much time should the process be paused?(optional)

So for those of you who have finished all the previous tasks, this is for you. This is a continuation of the previous part(signalling). The aim here is to define a new system call `pause(pid, duration)`, which would pause the process with the given PID as argument for the given duration of time. The unit of duration here will be 'ticks'. Tick is the unit of time that after which a timer interrupts the CPU, periodically. Don't worry about this much. You will need to use the system call `uptime`. Refer to it and see what does it do. There is no skeleton code provided for this part. The test code for this task is named `timed_pause.c`.

_Hint:_
Note what does `uptime` do. You may need to take the difference of the _ticks_ values and compare it with the duration passed in the `pause` system call.

