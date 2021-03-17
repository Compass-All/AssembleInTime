#include "utils.h"

u64 read_reg_x20()
{
    u64 x20_reg;
    asm("mov %0, x20"
        : "=r"(x20_reg));
    return x20_reg;
}

int set_reg_x20(u64 val)
{
    asm("mov x20, %0"
        :
        : "r"(val));
    return read_reg_x20() == val;
}