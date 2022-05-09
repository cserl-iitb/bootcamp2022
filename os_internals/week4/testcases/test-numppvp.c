#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
  int vpages = numvp();
  int ppages = numpp();
  printf(1, "Total user virtual pages: %d \n", vpages);
  printf(1, "Total user physical pages: %d \n", ppages);
  sbrk(8192);
  int nvpages = numvp();
  int nppages = numpp();
  printf(1, "Total user virtual pages now: %d \n", nvpages);
  printf(1, "Total user physical pages now: %d \n", nppages);
  exit();
}
