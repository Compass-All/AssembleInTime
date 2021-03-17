#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#include "utils.h"

int main() __attribute__((section(".text.init")));

int __placeholder() __attribute__((section(".text.execution")));

#endif // __MAIN_H_