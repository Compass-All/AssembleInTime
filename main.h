#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#include "include/typedef.h"
#include "utils.h"

int main();

int __placeholder() __attribute__((section(".text.execution")));

int __placeholder()
{
    // DONT DELETE IT !!!!
    // prevent linker optimizing the memory layout
    return 0;
}
#endif // __MAIN_H_