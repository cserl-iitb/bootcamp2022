#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) 
{
    init_counter();
    int ret = fork();

    /* This is where we increment the global counter
       Modify this to ensure race conditions do not mess up final value
       Without locking, the output would be a random value less than 20000
    */

    /*  
        Tescases:
            1. Print lock id if the lock has been initialized.
            2. define and call the function 'int holding_mylock(int id)' to check the status of
               the lock in two scenarios - i) when the lock is held and ii) when the lock is not held. 
    */

    for(int i=0; i<10000; i++){
        update_cnt();
    }

    if(ret == 0)
        exit();
    else{
        wait();
        printf(1, "%d\n", display_count());
        exit();
    }

} 