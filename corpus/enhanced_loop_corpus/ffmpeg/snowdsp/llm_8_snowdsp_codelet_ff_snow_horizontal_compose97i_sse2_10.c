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
    asm volatile ("movdqu   (%1), %%xmm1        \n\t"
                  "movdqu 16(%1), %%xmm5        \n\t"
                  "movdqu 32(%1), %%xmm9        \n\t"
                  "movdqu 48(%1), %%xmm13       \n\t"
                  "movdqu  2(%1), %%xmm2        \n\t"
                  "movdqu 18(%1), %%xmm6        \n\t"
                  "movdqu 34(%1), %%xmm10       \n\t"
                  "movdqu 50(%1), %%xmm14       \n\t"
                  "paddw  %%xmm1, %%xmm2        \n\t"
                  "paddw  %%xmm5, %%xmm6        \n\t"
                  "paddw  %%xmm9, %%xmm10       \n\t"
                  "paddw  %%xmm13, %%xmm14      \n\t"
                  "paddw  %%xmm7, %%xmm2        \n\t"
                  "paddw  %%xmm7, %%xmm6        \n\t"
                  "paddw  %%xmm7, %%xmm10       \n\t"
                  "paddw  %%xmm7, %%xmm14       \n\t"
                  "pmulhw %%xmm3, %%xmm2        \n\t"
                  "pmulhw %%xmm3, %%xmm6        \n\t"
                  "pmulhw %%xmm3, %%xmm10       \n\t"
                  "pmulhw %%xmm3, %%xmm14       \n\t"
                  "paddw    (%0), %%xmm2        \n\t"
                  "paddw  16(%0), %%xmm6        \n\t"
                  "paddw  32(%0), %%xmm10       \n\t"
                  "paddw  48(%0), %%xmm14       \n\t"
                  "movdqa %%xmm2, (%0)          \n\t"
                  "movdqa %%xmm6, 16(%0)        \n\t"
                  "movdqa %%xmm10, 32(%0)       \n\t"
                  "movdqa %%xmm14, 48(%0)       \n\t"
                  : : "r" (&b[i]), "r" (&ref[i]) : "memory");
}
}
