#include "types.h"
#include "stat.h"
#include "user.h"

int n;
int out[100];

void recurse(int depth) {
	if (depth == 0) {
		for(int i=0;i<100;i++){
			out[i] = 0;
		}
		int ret = get_ancestors(n, out);
		
		
		printf(1, "Process: %d \n", getpid());
		printf(1, "Ancestors: ");
		for(int i=0;i<100 && out[i]!=0;i++){
			printf(1, "%d ", out[i]);
		}
		printf(1,"\n");
		printf(1, "Return value: %d \n", ret);
		exit();
	}
	else {
		int ret;
		int i;
		for (i=0; i<5; i++) {
			ret = fork();
			if (ret == 0) {
				exit();
			}
			else {
				wait();
			}
		}
		ret = fork();
		if (ret == 0) {
			recurse(depth-1);
			exit();
		}
		else {
			wait();
		}
	}
}

int
main(int argc, char *argv[])
{
  int i;

  if(argc <= 1){
    exit();
  }

  i = atoi(argv[1]);
  n = atoi(argv[2]);

  recurse(i);



  exit();
}
