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
    asm volatile ("movdqu  2(%1), %%xmm2        \n\tmovdqu 18(%1), %%xmm6        \n\tpaddw    (%1), %%xmm2        \n\tpaddw  16(%1), %%xmm6        \n\tmovdqu   (%0), %%xmm0        \n\tmovdqu 16(%0), %%xmm4        \n\tpaddw  %%xmm2, %%xmm0        \n\tpaddw  %%xmm6, %%xmm4        \n\tpsraw      $1, %%xmm2        \n\tpsraw      $1, %%xmm6        \n\tpaddw  %%xmm0, %%xmm2        \n\tpaddw  %%xmm4, %%xmm6        \n\tmovdqa %%xmm2, (%2)          \n\tmovdqa %%xmm6, 16(%2)        \n\t" :  : "r" (&src[i]), "r" (&b[i]), "r" (&temp[i]) : "memory");
}

}
