This is the skeleton code of the 3rd task of this week. You can copy this into your text editor and start working on it. Ignore the commands `acquire(&ptable.lock)` and `release(&ptable.lock)` for now. You will learn about these in the later weeks.

The approach to follow here is to define a new int variable in the struct proc which will store the value of a integer, which will be used to compare in the scheduler code, and decide whether to pause, or continue. So accordingly you have to add a line in the scheduler function that on some given value of the variable, break from the for loop, so that the scheduler doesn't run the process again till the value of that variable is changed again.

```c
int signalProcess(int proc_pid, char* sig)
{

    //Take arguments from user function using helper functions argint, argstr
    struct proc *p;
    
    acquire(&ptable.lock);

    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    
      if(p->pid == proc_pid){
      //Now we will have made sure that p->pid is the pid of our process only.

        if(/*signal = pause*/)
        {
          //Change the value of the varibale in the struct proc to some integer say 1 which will signify pausing
        }

        else if(/*signal = continue*/)
        {
          //Change the value of the varibale in the struct proc to some integer say 0 which will signify continue or not paused

        }

        else if(/*signal = kill*/)
        {      
          //Refer to kill system call
          //Also remember to change the value of the varibale in the struct proc to some integer say 0 which will signify continue or not paused
        }

      }
  }
  release(&ptable.lock);
  return 0;

}
```
