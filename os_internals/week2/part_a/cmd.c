#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"


int main(int argc, char **argv)
{
	if(argc<=1){
        exit();
    }
    char **args = argv;
    for(int i=1;i<argc;i++){
        args[i-1] = argv[i];
    }
    args[argc-1] = NULL;

    // Implement your code here
    

    // 
    
    exit();
}