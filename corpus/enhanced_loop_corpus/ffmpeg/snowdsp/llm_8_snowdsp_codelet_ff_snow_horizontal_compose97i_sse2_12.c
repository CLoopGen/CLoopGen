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
for (; i < w_r - 31; i += 32) {
    asm volatile ("movdqu   (%1), %%xmm1        \n\t"
                  "movdqu 16(%1), %%xmm5        \n\t"
                  "movdqu  2(%1), %%xmm2        \n\t"
                  "movdqu 18(%1), %%xmm6        \n\t"
                  "paddw  %%xmm1, %%xmm2        \n\t"
                  "paddw  %%xmm5, %%xmm6        \n\t"
                  "movdqa   (%0), %%xmm0        \n\t"
                  "movdqa 16(%0), %%xmm4        \n\t"
                  "psubw  %%xmm2, %%xmm0        \n\t"
                  "psubw  %%xmm6, %%xmm4        \n\t"
                  "movdqa %%xmm0, (%0)          \n\t"
                  "movdqa %%xmm4, 16(%0)       \n\t"
                  "movdqu 32(%1), %%xmm3        \n\t"
                  "movdqu 34(%1), %%xmm7        \n\t"
                  "movdqu 48(%1), %%xmm9        \n\t"
                  "movdqu 50(%1), %%xmm10       \n\t"
                  "paddw  %%xmm3, %%xmm7        \n\t"
                  "paddw  %%xmm9, %%xmm10       \n\t"
                  "movdqa 32(%0), %%xmm8        \n\t"
                  "movdqa 48(%0), %%xmm11       \n\t"
                  "psubw  %%xmm7, %%xmm8        \n\t"
                  "psubw  %%xmm10, %%xmm11      \n\t"
                  "movdqa %%xmm8, 32(%0)        \n\t"
                  "movdqa %%xmm11, 48(%0)       \n\t"
                  : : "r" (&dst[i]), "r" (&b[i]) : "memory");
}
}
