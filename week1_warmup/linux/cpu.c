#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) 

{
  unsigned int i,j;
  while(1)
    {
      j = 1;
      for(i = 1; i <= 10; i++)
	{
	  j = j*i;
	}
    }
}


