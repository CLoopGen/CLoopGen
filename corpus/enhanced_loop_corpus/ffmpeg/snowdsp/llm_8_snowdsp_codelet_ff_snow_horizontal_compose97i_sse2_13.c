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
    asm volatile ("movdqu   (%1), %%xmm0        \n\t"
                  "movdqu 16(%1), %%xmm4        \n\t"
                  "movdqu 32(%1), %%xmm2        \n\t"
                  "movdqu 48(%1), %%xmm6        \n\t"
                  "movdqu  2(%1), %%xmm1        \n\t"
                  "movdqu 18(%1), %%xmm5        \n\t"
                  "movdqu 34(%1), %%xmm3        \n\t"
                  "movdqu 50(%1), %%xmm7        \n\t"
                  "paddw  %%xmm6, %%xmm0        \n\t"
                  "paddw  %%xmm7, %%xmm4        \n\t"
                  "paddw  %%xmm6, %%xmm2        \n\t"
                  "paddw  %%xmm7, %%xmm6        \n\t"
                  "paddw  %%xmm7, %%xmm1        \n\t"
                  "paddw  %%xmm6, %%xmm5        \n\t"
                  "paddw  %%xmm7, %%xmm3        \n\t"
                  "paddw  %%xmm6, %%xmm7        \n\t"
                  "pavgw  %%xmm1, %%xmm0        \n\t"
                  "pavgw  %%xmm5, %%xmm4        \n\t"
                  "pavgw  %%xmm3, %%xmm2        \n\t"
                  "pavgw  %%xmm7, %%xmm6        \n\t"
                  "psubw  %%xmm7, %%xmm0        \n\t"
                  "psubw  %%xmm6, %%xmm4        \n\t"
                  "psubw  %%xmm7, %%xmm2        \n\t"
                  "psubw  %%xmm6, %%xmm6        \n\t"
                  "psraw      $1, %%xmm0        \n\t"
                  "psraw      $1, %%xmm4        \n\t"
                  "psraw      $1, %%xmm2        \n\t"
                  "psraw      $1, %%xmm6        \n\t"
                  "movdqa   (%0), %%xmm1        \n\t"
                  "movdqa 16(%0), %%xmm5        \n\t"
                  "movdqa 32(%0), %%xmm3        \n\t"
                  "movdqa 48(%0), %%xmm7        \n\t"
                  "paddw  %%xmm1, %%xmm0        \n\t"
                  "paddw  %%xmm5, %%xmm4        \n\t"
                  "paddw  %%xmm3, %%xmm2        \n\t"
                  "paddw  %%xmm7, %%xmm6        \n\t"
                  "psraw      $2, %%xmm0        \n\t"
                  "psraw      $2, %%xmm4        \n\t"
                  "psraw      $2, %%xmm2        \n\t"
                  "psraw      $2, %%xmm6        \n\t"
                  "paddw  %%xmm1, %%xmm0        \n\t"
                  "paddw  %%xmm5, %%xmm4        \n\t"
                  "paddw  %%xmm3, %%xmm2        \n\t"
                  "paddw  %%xmm7, %%xmm6        \n\t"
                  "movdqa %%xmm0, (%0)          \n\t"
                  "movdqa %%xmm4, 16(%0)        \n\t"
                  "movdqa %%xmm2, 32(%0)        \n\t"
                  "movdqa %%xmm6, 48(%0)        \n\t"
                  : : "r" (&b[i]), "r" (&ref[i]) : "memory");
}
}
