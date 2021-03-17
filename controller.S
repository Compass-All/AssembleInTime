.globl   hello


.type hello, "function"
// u64 hello();
hello:
     stp	x29, x30, [sp, #-48]!
     mov	x29, sp
     ldp	x29, x30, [sp], #48
     ret