#include "types.h"
#include "stat.h"
#include "user.h"

#define MAX_SZ 1000000
#define SIGNAL_PAUSE "PAUSE"
#define SIGNAL_CONTINUE "CONTINUE"
#define SIGNAL_KILL "KILL"

int main(int argc, const char **argv) 
{
	int ret = fork();
	if(ret == 0) 
	{ 
		for (int i = 0; i < MAX_SZ; ++i)
		{
			sleep(5e1);
			printf(1, "child: Not_paused\n");
		}

		exit();
	}

	sleep(5e2);
	printf(1, "parent: sending pause signal to child \n");
	signalProcess(ret, SIGNAL_PAUSE);
	
	sleep(5e2);
	printf(1, "parent: sending continue signal to child \n");
	signalProcess(ret, SIGNAL_CONTINUE);
	
	sleep(5e2);
	printf(1, "parent: sending kill signal to child \n");
	signalProcess(ret, SIGNAL_KILL);
	
	wait();
	printf(1, "parent: child has terminated \n");
	exit();
}