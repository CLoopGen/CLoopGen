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
for (; i < w_r - 7; i += 8) {
    asm volatile ("movq    2(%1), %%mm2        \n\tmovq   10(%1), %%mm6        \n\tpaddw    (%1), %%mm2        \n\tpaddw   8(%1), %%mm6        \n\tmovq     (%0), %%mm0        \n\tmovq    8(%0), %%mm4        \n\tpaddw   %%mm2, %%mm0        \n\tpaddw   %%mm6, %%mm4        \n\tpsraw      $1, %%mm2        \n\tpsraw      $1, %%mm6        \n\tpaddw   %%mm0, %%mm2        \n\tpaddw   %%mm4, %%mm6        \n\tmovq    %%mm2, (%2)         \n\tmovq    %%mm6, 8(%2)        \n\t" :  : "r" (&src[i]), "r" (&b[i]), "r" (&temp[i]) : "memory");
}

}
