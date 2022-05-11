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
    for(int i=0; i<10000; i++){
        set_cnt(display_count()+1);
    }

    if(ret == 0)
        exit();
    else{
        wait();
        printf(1, "%d\n", display_count());
        exit();
    }

} 