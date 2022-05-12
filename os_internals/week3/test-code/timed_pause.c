#include "types.h"
#include "stat.h"
#include "user.h"

#define MAX_SZ 1000

void do_some_job(int starts)
{
	int pid;
	int ends;

	pid = getpid();

	printf(1, "\nchild %d: starts executiion at %d \n", pid, starts );

	sleep(10);
	
	ends = uptime();
	printf(1, "child %d: ends at %d \n", pid, ends);
	printf(1, "child %d: time taken = %d ticks \n", pid, (ends - starts) );

}

int main(int argc, const char **argv) 
{
	int pid1, pid2;
	int starts;

	printf(1, "\nparent %d: Creating first child \n", getpid());
	starts = uptime();
	pid1 = fork();
	if(pid1 == 0) 
	{ 
		do_some_job(starts);
		exit();
	}

	wait();

	printf(1, "\nparent %d: Creating second child \n", getpid());
	starts = uptime();
	pid2 = fork();
	if(pid2 == 0) 
	{ 
		do_some_job(starts);
		exit();
	}

	pause(pid2, 500);
	wait();

	exit();

}
