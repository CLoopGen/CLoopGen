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
    for (; i < w_l - 7; i += 8) {
        if ((i & 15) == 0) {
            asm volatile ("movq     (%1), %%mm0        \n\t"
                          "movq    8(%1), %%mm4        \n\t"
                          "movq    2(%1), %%mm1        \n\t"
                          "movq   10(%1), %%mm5        \n\t"
                          "paddw   %%mm6, %%mm0        \n\t"
                          "paddw   %%mm6, %%mm4        \n\t"
                          "paddw   %%mm7, %%mm1        \n\t"
                          "paddw   %%mm7, %%mm5        \n\t"
                          "pavgw   %%mm1, %%mm0        \n\t"
                          "pavgw   %%mm5, %%mm4        \n\t"
                          "psubw   %%mm7, %%mm0        \n\t"
                          "psubw   %%mm7, %%mm4        \n\t"
                          "psraw      $1, %%mm0        \n\t"
                          "psraw      $1, %%mm4        \n\t"
                          "movq     (%0), %%mm1        \n\t"
                          "movq    8(%0), %%mm5        \n\t"
                          "paddw   %%mm1, %%mm0        \n\t"
                          "paddw   %%mm5, %%mm4        \n\t"
                          "psraw      $2, %%mm0        \n\t"
                          "psraw      $2, %%mm4        \n\t"
                          "paddw   %%mm1, %%mm0        \n\t"
                          "paddw   %%mm5, %%mm4        \n\t"
                          "movq    %%mm0, (%0)         \n\t"
                          "movq    %%mm4, 8(%0)        \n\t"
                          : 
                          : "r" (&b[i]), "r" (&ref[i])
                          : "memory", "mm0", "mm1", "mm4", "mm5");
        } else {
            asm volatile ("movq     (%1), %%mm0        \n\t"
                          "movq    8(%1), %%mm4        \n\t"
                          "movq    2(%1), %%mm1        \n\t"
                          "movq   10(%1), %%mm5        \n\t"
                          "paddw   %%mm6, %%mm0        \n\t"
                          "paddw   %%mm6, %%mm4        \n\t"
                          "paddw   %%mm7, %%mm1        \n\t"
                          "paddw   %%mm7, %%mm5        \n\t"
                          "pavgw   %%mm1, %%mm0        \n\t"
                          "pavgw   %%mm5, %%mm4        \n\t"
                          "movq    %%mm0, (%0)         \n\t"
                          "movq    %%mm4, 8(%0)        \n\t"
                          : 
                          : "r" (&b[i]), "r" (&ref[i])
                          : "memory", "mm0", "mm1", "mm4", "mm5");
        }
    }
}
