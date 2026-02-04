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
for (; i < w_r - 15; i += 16) {
    asm volatile (
        "movq     (%1), %%mm2        \n\t"
        "movq    8(%1), %%mm6        \n\t"
        "paddw   2(%1), %%mm2        \n\t"
        "paddw  10(%1), %%mm6        \n\t"
        "movq     (%0), %%mm0        \n\t"
        "movq    8(%0), %%mm4        \n\t"
        "psubw   %%mm2, %%mm0        \n\t"
        "psubw   %%mm6, %%mm4        \n\t"
        "movq    %%mm0, (%0)         \n\t"
        "movq    %%mm4, 8(%0)        \n\t"
        
        "movq    16(%1), %%mm2       \n\t"
        "movq    24(%1), %%mm6       \n\t"
        "paddw   18(%1), %%mm2       \n\t"
        "paddw   26(%1), %%mm6       \n\t"
        "movq    16(%0), %%mm0       \n\t"
        "movq    24(%0), %%mm4       \n\t"
        "psubw   %%mm2, %%mm0        \n\t"
        "psubw   %%mm6, %%mm4        \n\t"
        "movq    %%mm0, 16(%0)       \n\t"
        "movq    %%mm4, 24(%0)       \n\t"
        : 
        : "r" (&dst[i]), "r" (&b[i]) 
        : "memory", "mm0", "mm2", "mm4", "mm6"
    );
}
}
