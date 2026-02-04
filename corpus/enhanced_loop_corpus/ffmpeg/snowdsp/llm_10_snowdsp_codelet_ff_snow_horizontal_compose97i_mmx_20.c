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
for (; i < w_l - 3; i += 4) {
    asm volatile (
        "movq     (%1), %%mm0        \n\t"
        "movq    2(%1), %%mm1        \n\t"
        "paddw   %%mm6, %%mm0        \n\t"
        "paddw   %%mm7, %%mm1        \n\t"
        "pavgw   %%mm1, %%mm0        \n\t"
        "psubw   %%mm7, %%mm0        \n\t"
        "psraw      $1, %%mm0        \n\t"
        "movq     (%0), %%mm1        \n\t"
        "paddw   %%mm1, %%mm0        \n\t"
        "psraw      $2, %%mm0        \n\t"
        "paddw   %%mm1, %%mm0        \n\t"
        "movq    %%mm0, (%0)         \n\t"

        "movq    4(%1), %%mm2        \n\t"
        "movq    6(%1), %%mm3        \n\t"
        "paddw   %%mm6, %%mm2        \n\t"
        "paddw   %%mm7, %%mm3        \n\t"
        "pavgw   %%mm3, %%mm2        \n\t"
        "psubw   %%mm7, %%mm2        \n\t"
        "psraw      $1, %%mm2        \n\t"
        "movq    4(%0), %%mm3        \n\t"
        "paddw   %%mm3, %%mm2        \n\t"
        "psraw      $2, %%mm2        \n\t"
        "paddw   %%mm3, %%mm2        \n\t"
        "movq    %%mm2, 4(%0)        \n\t"
        : 
        : "r" (&b[i]), "r" (&ref[i]) 
        : "memory", "mm0", "mm1", "mm2", "mm3"
    );
}
}
