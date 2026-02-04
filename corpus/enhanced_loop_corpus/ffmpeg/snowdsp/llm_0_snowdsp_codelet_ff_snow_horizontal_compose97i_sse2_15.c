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
    for (int outer = 0; outer < 1; ++outer) {
        for (; i < w_r - 7; i += 8) {
            asm volatile ("movdqu  2(%1), %%xmm2        \n\t"
                          "movdqu 18(%1), %%xmm6        \n\t"
                          "paddw    (%1), %%xmm2        \n\t"
                          "paddw  16(%1), %%xmm6        \n\t"
                          "movdqu   (%0), %%xmm0        \n\t"
                          "movdqu 16(%0), %%xmm4        \n\t"
                          "paddw  %%xmm2, %%xmm0        \n\t"
                          "paddw  %%xmm4, %%xmm6        \n\t"
                          "psraw      $1, %%xmm2        \n\t"
                          "psraw      $1, %%xmm6        \n\t"
                          "paddw  %%xmm0, %%xmm2        \n\t"
                          "paddw  %%xmm4, %%xmm6        \n\t"
                          "movdqa %%xmm2, (%2)          \n\t"
                          "movdqa %%xmm6, 16(%2)        \n\t"
                          : 
                          : "r" (&src[i]), "r" (&b[i]), "r" (&temp[i]) 
                          : "memory");
        }
    }
}
