#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern  int w_r;
extern int i;
extern IDWTELEM * src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < w_r - 15; i += 16) {
    asm volatile (
        "movdqu   2(%1), %%xmm2      \n\t"
        "movdqu  18(%1), %%xmm6      \n\t"
        "movdqu  34(%1), %%xmm10     \n\t"
        "movdqu  50(%1), %%xmm14     \n\t"
        "paddw     (%1), %%xmm2      \n\t"
        "paddw  16(%1), %%xmm6       \n\t"
        "paddw  32(%1), %%xmm10      \n\t"
        "paddw  48(%1), %%xmm14      \n\t"
        "movdqu    (%0), %%xmm0      \n\t"
        "movdqu  16(%0), %%xmm4      \n\t"
        "movdqu  32(%0), %%xmm8      \n\t"
        "movdqu  48(%0), %%xmm12     \n\t"
        "paddw   %%xmm2, %%xmm0      \n\t"
        "paddw   %%xmm6, %%xmm4      \n\t"
        "paddw  %%xmm10, %%xmm8      \n\t"
        "paddw  %%xmm14, %%xmm12     \n\t"
        "psraw      $1, %%xmm2       \n\t"
        "psraw      $1, %%xmm6       \n\t"
        "psraw      $1, %%xmm10      \n\t"
        "psraw      $1, %%xmm14      \n\t"
        "paddw   %%xmm0, %%xmm2      \n\t"
        "paddw   %%xmm4, %%xmm6      \n\t"
        "paddw   %%xmm8, %%xmm10     \n\t"
        "paddw  %%xmm12, %%xmm14     \n\t"
        "movdqa  %%xmm2,   (%2)      \n\t"
        "movdqa  %%xmm6, 16(%2)      \n\t"
        "movdqa %%xmm10, 32(%2)      \n\t"
        "movdqa %%xmm14, 48(%2)      \n\t"
        : 
        : "r" (&src[i]), "r" (&b[i]), "r" (&temp[i])
        : "memory"
    );
}
}
