This is the skeleton code of the 3rd question of this week's task. You can copy this into your text editor and start working on it. Ignore the commands `acquire(&ptable.lock)` and `release(&ptable.lock)` for now. You will learn about these in the later weeks.

```
int signalProcess(int proc_pid, char* sig)
{

    Take arguments from user function 
    struct proc *p;
    
    acquire(&ptable.lock);

    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
    
      if(p->pid == proc_pid){
      //Now we will have made sure that p->pid is the pid of our process only.

        if(//signal = pause)
        {
          //Change state of p to something which will cause it to not run by scheduler
        }

        else if(//signal = continue)
        {
          //Change state of p to running again.

        }

        else if(//signal = kill)
        {      
          //Refer to kill system call
        }

      }
  }
  release(&ptable.lock);
  return 0;

}
```
