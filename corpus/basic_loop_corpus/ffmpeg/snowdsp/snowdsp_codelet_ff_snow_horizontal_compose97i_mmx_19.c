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
    asm volatile ("movq     (%1), %%mm2        \n\tmovq    8(%1), %%mm6        \n\tpaddw   2(%1), %%mm2        \n\tpaddw  10(%1), %%mm6        \n\tmovq     (%0), %%mm0        \n\tmovq    8(%0), %%mm4        \n\tpsubw   %%mm2, %%mm0        \n\tpsubw   %%mm6, %%mm4        \n\tmovq    %%mm0, (%0)         \n\tmovq    %%mm4, 8(%0)        \n\t" :  : "r" (&dst[i]), "r" (&b[i]) : "memory");
}

}
