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
    asm volatile ("movdqu   (%1), %%xmm0        \n\t"
                  "movdqu 16(%1), %%xmm4        \n\t"
                  "movdqu  2(%1), %%xmm1        \n\t"
                  "movdqu 18(%1), %%xmm5        \n\t"
                  "paddw %%xmm0, %%xmm1         \n\t"
                  "paddw %%xmm4, %%xmm5         \n\t"
                  "psraw     $1, %%xmm1         \n\t"
                  "psraw     $1, %%xmm5         \n\t"
                  "movdqu   (%0), %%xmm2        \n\t"
                  "movdqu 16(%0), %%xmm6        \n\t"
                  "paddw %%xmm2, %%xmm1         \n\t"
                  "paddw %%xmm6, %%xmm5         \n\t"
                  "movdqa %%xmm1, (%2)          \n\t"
                  "movdqa %%xmm5, 16(%2)        \n\t"
                  : 
                  : "r" (&src[i]), "r" (&b[i]), "r" (&temp[i]) 
                  : "memory", "xmm0", "xmm1", "xmm2", "xmm4", "xmm5", "xmm6");
}
}
