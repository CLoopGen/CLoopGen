#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern  int w_r;
extern int i;
extern IDWTELEM * dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < w_r - 15; i += 16) {
    asm volatile ("movdqu   (%1), %%xmm1        \n\tmovdqu 16(%1), %%xmm5        \n\tmovdqu  4(%1), %%xmm2        \n\tmovdqu 20(%1), %%xmm6        \n\tpaddw  %%xmm1, %%xmm2        \n\tpaddw  %%xmm5, %%xmm6        \n\tmovdqa   (%0), %%xmm0        \n\tmovdqa 16(%0), %%xmm4        \n\tpsubw  %%xmm2, %%xmm0        \n\tpsubw  %%xmm6, %%xmm4        \n\tmovdqa %%xmm0, (%0)          \n\tmovdqa %%xmm4, 16(%0)        \n\t" :  : "r" (&dst[i]), "r" (&b[i]) : "memory");
}
}
