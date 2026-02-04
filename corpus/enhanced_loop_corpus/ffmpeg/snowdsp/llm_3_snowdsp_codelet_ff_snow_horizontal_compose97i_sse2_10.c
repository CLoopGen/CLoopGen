#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern  int w_l;
extern int i;
extern IDWTELEM * ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < w_l - 31; i += 32) {
    asm volatile ("movdqu   (%1), %%xmm1        \n\tmovdqu 16(%1), %%xmm5        \n\tmovdqu  2(%1), %%xmm2        \n\tmovdqu 18(%1), %%xmm6        \n\tpaddw  %%xmm1, %%xmm2        \n\tpaddw  %%xmm5, %%xmm6        \n\tpaddw  %%xmm7, %%xmm2        \n\tpaddw  %%xmm7, %%xmm6        \n\tpmulhw %%xmm3, %%xmm2        \n\tpmulhw %%xmm3, %%xmm6        \n\tpaddw    (%0), %%xmm2        \n\tpaddw  16(%0), %%xmm6        \n\tmovdqa %%xmm2, (%0)          \n\tmovdqa %%xmm6, 16(%0)        \n\t"
                  "movdqu  32(%1), %%xmm1        \n\tmovdqu 48(%1), %%xmm5        \n\tmovdqu 34(%1), %%xmm2        \n\tmovdqu 50(%1), %%xmm6        \n\tpaddw  %%xmm1, %%xmm2        \n\tpaddw  %%xmm5, %%xmm6        \n\tpaddw  %%xmm7, %%xmm2        \n\tpaddw  %%xmm7, %%xmm6        \n\tpmulhw %%xmm3, %%xmm2        \n\tpmulhw %%xmm3, %%xmm6        \n\tpaddw  32(%0), %%xmm2        \n\tpaddw  48(%0), %%xmm6        \n\tmovdqa %%xmm2, 32(%0)        \n\tmovdqa %%xmm6, 48(%0)        \n\t"
                  : : "r" (&b[i]), "r" (&ref[i]) : "memory");
}
}
