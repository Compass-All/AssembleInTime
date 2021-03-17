#include "main.h"
#include <sys/mman.h>

extern u64 hello();

void print_x20()
{
    u64 x20_reg;

    asm("mov %0, x20"
        : "=r"(x20_reg));
    printf("x20_reg = %lld \n", x20_reg);
}
int main() __attribute__((section(".text.init")));
int main()
{
    u32 *ptr = malloc(0x1000);
    mprotect((void *)((u64)ptr & 0xfffffffffffff000), 0x1000, PROT_EXEC | PROT_READ | PROT_WRITE);
    u32 instruct;

    while (~scanf("%x", &instruct))
    {
        // ptr[0] = 0xd2800c94; // mov x20, #100;
        ptr[0] = instruct;   // mov x20, #100;
        ptr[1] = 0xd65f03c0; // ret
        ptr[2] = 0xd503201f; // add more nop because of the pipeline / branch prediction / other reasons.
        ptr[3] = 0xd503201f; // nop
        ptr[4] = 0xd503201f; // nop
        void (*foo)(void) = (void (*)())ptr;
        foo();
        print_x20();
    }
    free(ptr);
}