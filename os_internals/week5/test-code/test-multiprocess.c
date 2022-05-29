#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) 
{
    init_counter();
    int ret1 = fork(); // creates child process 1

    /* This is where we spawn multiple processes to increment the global counter
       Modify this to ensure race conditions do not mess up final value
       Without locking, the output would be a random value less than 30000
    */

    /*  
        Tescases:
            1. Print lock id if the lock has been initialized.
            2. define and call the function 'int holding_mylock(int id)' to check the status of
               the lock in two scenarios - i) when the lock is held and ii) when the lock is not held. 
            3. You have to implement locking in all the processes so that the final value of counter comes
               to be 30000.
    */

    // Hint: Implement one locking system here
    
    for(int i=0; i<10000; i++){
        set_cnt(display_count()+1);
    }

    if(ret1 == 0){
        // Hint: Implement one locking system here

        int ret2 = fork(); //creates child process 2

        for(int i=0; i<10000; i++){
            set_cnt(display_count()+1);
        }

        if(ret2==0)
            exit();
        else{
            wait();
            exit();
        }
    }
    else{
        wait();
        printf(1, "%d\n", display_count());
        exit();
    }

} 