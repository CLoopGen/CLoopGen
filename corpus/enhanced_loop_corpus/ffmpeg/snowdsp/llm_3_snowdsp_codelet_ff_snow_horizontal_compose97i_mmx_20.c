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
for (; i < w_l - 15; i += 16) {
    asm volatile ("movq     (%1), %%mm0        \n\tmovq    8(%1), %%mm4        \n\tmovq    2(%1), %%mm1        \n\tmovq   10(%1), %%mm5        \n\tpaddw   %%mm6, %%mm0        \n\tpaddw   %%mm6, %%mm4        \n\tpaddw   %%mm7, %%mm1        \n\tpaddw   %%mm7, %%mm5        \n\tpavgw   %%mm1, %%mm0        \n\tpavgw   %%mm5, %%mm4        \n\tpsubw   %%mm7, %%mm0        \n\tpsubw   %%mm7, %%mm4        \n\tpsraw      $1, %%mm0        \n\tpsraw      $1, %%mm4        \n\tmovq     (%0), %%mm1        \n\tmovq    8(%0), %%mm5        \n\tpaddw   %%mm1, %%mm0        \n\tpaddw   %%mm5, %%mm4        \n\tpsraw      $2, %%mm0        \n\tpsraw      $2, %%mm4        \n\tpaddw   %%mm1, %%mm0        \n\tpaddw   %%mm5, %%mm4        \n\tmovq    %%mm0, (%0)         \n\tmovq    %%mm4, 8(%0)        \n\t" :  : "r" (&b[i]), "r" (&ref[i]) : "memory");
    asm volatile ("movq    16(%1), %%mm0        \n\tmovq   24(%1), %%mm4        \n\tmovq    18(%1), %%mm1        \n\tmovq   26(%1), %%mm5        \n\tpaddw   %%mm6, %%mm0        \n\tpaddw   %%mm6, %%mm4        \n\tpaddw   %%mm7, %%mm1        \n\tpaddw   %%mm7, %%mm5        \n\tpavgw   %%mm1, %%mm0        \n\tpavgw   %%mm5, %%mm4        \n\tpsubw   %%mm7, %%mm0        \n\tpsubw   %%mm7, %%mm4        \n\tpsraw      $1, %%mm0        \n\tpsraw      $1, %%mm4        \n\tmovq    16(%0), %%mm1        \n\tmovq    24(%0), %%mm5        \n\tpaddw   %%mm1, %%mm0        \n\tpaddw   %%mm5, %%mm4        \n\tpsraw      $2, %%mm0        \n\tpsraw      $2, %%mm4        \n\tpaddw   %%mm1, %%mm0        \n\tpaddw   %%mm5, %%mm4        \n\tmovq    %%mm0, 16(%0)       \n\tmovq    %%mm4, 24(%0)       \n\t" :  : "r" (&b[i]), "r" (&ref[i]) : "memory");
}
}
