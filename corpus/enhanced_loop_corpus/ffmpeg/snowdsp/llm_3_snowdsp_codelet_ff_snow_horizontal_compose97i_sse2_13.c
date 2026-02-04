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
    asm volatile ("movdqu   (%1), %%xmm0        \n\tmovdqu 16(%1), %%xmm4        \n\tmovdqu  2(%1), %%xmm1        \n\tmovdqu 18(%1), %%xmm5        \n\tpaddw  %%xmm6, %%xmm0        \n\tpaddw  %%xmm6, %%xmm4        \n\tpaddw  %%xmm7, %%xmm1        \n\tpaddw  %%xmm7, %%xmm5        \n\tpavgw  %%xmm1, %%xmm0        \n\tpavgw  %%xmm5, %%xmm4        \n\tpsubw  %%xmm7, %%xmm0        \n\tpsubw  %%xmm7, %%xmm4        \n\tpsraw      $1, %%xmm0        \n\tpsraw      $1, %%xmm4        \n\tmovdqa   (%0), %%xmm1        \n\tmovdqa 16(%0), %%xmm5        \n\tpaddw  %%xmm1, %%xmm0        \n\tpaddw  %%xmm5, %%xmm4        \n\tpsraw      $2, %%xmm0        \n\tpsraw      $2, %%xmm4        \n\tpaddw  %%xmm1, %%xmm0        \n\tpaddw  %%xmm5, %%xmm4        \n\tmovdqa %%xmm0, (%0)          \n\tmovdqa %%xmm4, 16(%0)        \n\t" :  : "r" (&b[i]), "r" (&ref[i]) : "memory");
    asm volatile ("movdqu   32(%1), %%xmm0        \n\tmovdqu 48(%1), %%xmm4        \n\tmovdqu  34(%1), %%xmm1        \n\tmovdqu 50(%1), %%xmm5        \n\tpaddw  %%xmm6, %%xmm0        \n\tpaddw  %%xmm6, %%xmm4        \n\tpaddw  %%xmm7, %%xmm1        \n\tpaddw  %%xmm7, %%xmm5        \n\tpavgw  %%xmm1, %%xmm0        \n\tpavgw  %%xmm5, %%xmm4        \n\tpsubw  %%xmm7, %%xmm0        \n\tpsubw  %%xmm7, %%xmm4        \n\tpsraw      $1, %%xmm0        \n\tpsraw      $1, %%xmm4        \n\tmovdqa   32(%0), %%xmm1        \n\tmovdqa 48(%0), %%xmm5        \n\tpaddw  %%xmm1, %%xmm0        \n\tpaddw  %%xmm5, %%xmm4        \n\tpsraw      $2, %%xmm0        \n\tpsraw      $2, %%xmm4        \n\tpaddw  %%xmm1, %%xmm0        \n\tpaddw  %%xmm5, %%xmm4        \n\tmovdqa %%xmm0, 32(%0)          \n\tmovdqa %%xmm4, 48(%0)        \n\t" :  : "r" (&b[i]), "r" (&ref[i]) : "memory");
}
}
