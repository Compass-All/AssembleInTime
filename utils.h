#ifndef __UTILS_H_
#define __UTILS_H_

#include <stdio.h>
#include "main.h"

typedef unsigned long long u64;
typedef unsigned int u32;

u64 read_reg_x20();
int set_reg_x20(u64);

#endif // __UTILS_H_
