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
for (; i < w_r - 3; i += 4) {
    asm volatile (
        "movq     (%1), %%mm2        \n\t"
        "paddw   2(%1), %%mm2        \n\t"
        "movq     (%0), %%mm0        \n\t"
        "psubw   %%mm2, %%mm0        \n\t"
        "movq    %%mm0, (%0)         \n\t"
        : 
        : "r" (&dst[i]), "r" (&b[i]) 
        : "memory", "mm0", "mm2"
    );
}
}
