#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
    for(int i=0; i<10; i++)
        hello();
    exit();
}
