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
for (; i < w_l - 15; i += 16) {
    asm volatile ("movdqu   (%1), %%xmm0        \n\t"
                  "movdqu 16(%1), %%xmm2        \n\t"
                  "movdqu  1(%1), %%xmm1        \n\t"
                  "movdqu 17(%1), %%xmm3        \n\t"
                  "paddw  %%xmm6, %%xmm0        \n\t"
                  "paddw  %%xmm6, %%xmm2        \n\t"
                  "paddw  %%xmm7, %%xmm1        \n\t"
                  "paddw  %%xmm7, %%xmm3        \n\t"
                  "pavgw  %%xmm1, %%xmm0        \n\t"
                  "pavgw  %%xmm3, %%xmm2        \n\t"
                  "psubw  %%xmm7, %%xmm0        \n\t"
                  "psubw  %%xmm7, %%xmm2        \n\t"
                  "psraw      $1, %%xmm0        \n\t"
                  "psraw      $1, %%xmm2        \n\t"
                  "movdqa   (%0), %%xmm1        \n\t"
                  "movdqa 16(%0), %%xmm5        \n\t"
                  "paddw  %%xmm1, %%xmm0        \n\t"
                  "paddw  %%xmm5, %%xmm2        \n\t"
                  "psraw      $2, %%xmm0        \n\t"
                  "psraw      $2, %%xmm2        \n\t"
                  "paddw  %%xmm1, %%xmm0        \n\t"
                  "paddw  %%xmm5, %%xmm2        \n\t"
                  "movdqa %%xmm0, (%0)          \n\t"
                  "movdqa %%xmm2, 16(%0)        \n\t"
                  : 
                  : "r" (&b[i]), "r" (&ref[i])
                  : "memory", "xmm0", "xmm1", "xmm2", "xmm3", "xmm5");
}
}
