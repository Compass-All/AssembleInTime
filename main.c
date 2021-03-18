#include "main.h"

extern u64 hello();
extern u32 _execution_start;
extern u32 _execution_end;

int main()
{
    static int _runOnce = 0;

    if (!_runOnce)
    {
        _runOnce = 1;
    }
    else
    {
        exit(0); // temporary fix of endless execution
    }

    u32 *ptr = &_execution_start;
    printf(".text.execution: (%x, %x)\n", &_execution_start, &_execution_end);

    int mprotect_ret = mprotect((void *)((u64)ptr), &_execution_end - &_execution_start, PROT_EXEC | PROT_READ | PROT_WRITE);
    printf("mprotect success: (0 for yes, -1 for no)");
    printf("%d, %d", mprotect_ret, errno);
    printf("\n");
    u32 instruct;
  
    set_reg_x20(0xdeedbeef);
    printf("x20 = 0x%x\n", read_reg_x20());

    /*
        First, store the sp (x29) register and the ra (x30) register.
        Currently, we open a stack of 48B.
    */
    ptr[0] = 0xa9bd7bfd; // stp	x29, x30, [sp, #-48]!
    ptr[1] = 0x910003fd; // mov	x29, sp

    /*
        Then, we put our instruction here.
        Next, we will consider put more instructions at one time.
    */
    ptr[2] = 0xd2800c94; // mov x20, #100

    /*
        Finally, restore the register, and return.
    */
    ptr[3] = 0xa8c37bfd; // ldp	x29, x30, [sp], #48
    ptr[4] = 0xd65f03c0; // ret

    /*
        One more thing!
        Add some nop to prevent illegal instruction.
        because of the pipeline prefetch.
    */
    ptr[5] = 0xd503201f; // nop
    ptr[6] = 0xd503201f;
    ptr[7] = 0xd503201f;
    ptr[8] = 0xd503201f;

    void (*foo)(void) = (void (*)())ptr;
    foo();

    printf("x20 = 0x%x\n", read_reg_x20());

    return 0;
}