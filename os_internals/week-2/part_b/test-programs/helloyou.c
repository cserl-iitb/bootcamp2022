#include "types.h"
#include "stat.h"
#include "user.h"

int main(void)
{
    for (int i = 0; i < 10; i++){
        helloYou("Calling from XV6");
        helloYou("Welcome to XV6");
    }
    exit();
}