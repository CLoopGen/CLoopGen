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
    asm volatile ("movdqu   (%1), %%xmm1        \n\t"
                  "movdqu  2(%1), %%xmm2        \n\t"
                  "paddw  %%xmm1, %%xmm2        \n\t"
                  "paddw  %%xmm7, %%xmm2        \n\t"
                  "pmulhw %%xmm3, %%xmm2        \n\t"
                  "paddw    (%0), %%xmm2        \n\t"
                  "movdqa %%xmm2, (%0)          \n\t"
                  : : "r" (&b[i]), "r" (&ref[i]) : "memory");
}
}
