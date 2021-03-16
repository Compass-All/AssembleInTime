#include "main.h"

extern u64 hello();

int main()
{
    printf("0x%llx\n", hello());
    return 0;
}