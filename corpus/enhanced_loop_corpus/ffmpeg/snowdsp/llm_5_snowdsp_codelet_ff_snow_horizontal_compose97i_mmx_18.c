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
        asm volatile ("movq     (%1), %%mm2        \n\tmovq    8(%1), %%mm6        \n\tpaddw   2(%1), %%mm2        \n\tpaddw  10(%1), %%mm6        \n\tpaddw   %%mm7, %%mm2        \n\tpaddw   %%mm7, %%mm6        \n\tpmulhw  %%mm3, %%mm2        \n\tpmulhw  %%mm3, %%mm6        \n\tpaddw    (%0), %%mm2        \n\tpaddw   8(%0), %%mm6        \n\tmovq    %%mm2, (%0)         \n\tmovq    %%mm6, 8(%0)        \n\t" :  : "r" (&b[i]), "r" (&ref[i]) : "memory");
    } else {
        asm volatile ("movq     (%1), %%mm2        \n\tmovq    8(%1), %%mm6        \n\tpaddw   2(%1), %%mm2        \n\tpaddw  10(%1), %%mm6        \n\tpaddw   %%mm7, %%mm2        \n\tpaddw   %%mm7, %%mm6        \n\tpmulhw  %%mm3, %%mm2        \n\tpmulhw  %%mm3, %%mm6        \n\tmovq    %%mm2, (%0)         \n\tmovq    %%mm6, 8(%0)        \n\t" :  : "r" (&b[i]), "r" (&ref[i]) : "memory");
    }
}
}
