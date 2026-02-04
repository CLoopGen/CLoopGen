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
    for (; i < w_r - 7; i += 8) {
        if ((i & 0x10) == 0) {
            asm volatile ("movq     (%1), %%mm2        \n\t"
                          "movq    8(%1), %%mm6        \n\t"
                          "paddw   2(%1), %%mm2        \n\t"
                          "paddw  10(%1), %%mm6        \n\t"
                          "movq     (%0), %%mm0        \n\t"
                          "movq    8(%0), %%mm4        \n\t"
                          "psubw   %%mm2, %%mm0        \n\t"
                          "psubw   %%mm6, %%mm4        \n\t"
                          "movq    %%mm0, (%0)         \n\t"
                          "movq    %%mm4, 8(%0)        \n\t"
                          : 
                          : "r" (&dst[i]), "r" (&b[i]) 
                          : "memory");
        } else {
            asm volatile ("movq   4(%1), %%mm3        \n\t"
                          "movq  12(%1), %%mm7        \n\t"
                          "paddw  6(%1), %%mm3        \n\t"
                          "paddw 14(%1), %%mm7        \n\t"
                          "movq   4(%0), %%mm1        \n\t"
                          "movq  12(%0), %%mm5        \n\t"
                          "psubw  %%mm3, %%mm1        \n\t"
                          "psubw  %%mm7, %%mm5        \n\t"
                          "movq   %%mm1, 4(%0)        \n\t"
                          "movq   %%mm5, 12(%0)       \n\t"
                          : 
                          : "r" (&dst[i]), "r" (&b[i]) 
                          : "memory");
        }
    }
}
