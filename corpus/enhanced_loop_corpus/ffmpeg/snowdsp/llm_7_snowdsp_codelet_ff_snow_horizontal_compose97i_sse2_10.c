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
    asm volatile ("movdqu   (%1), %%xmm1        \n\t"
                  "movdqu 16(%1), %%xmm5        \n\t"
                  "movdqu  4(%1), %%xmm2        \n\t"  // Changed offset: breaks original RAW on ref[i+2], introduces new dependency on ref[i+4]
                  "movdqu 20(%1), %%xmm6        \n\t"  // Likewise for second vector
                  "paddw  %%xmm1, %%xmm2        \n\t"
                  "paddw  %%xmm5, %%xmm6        \n\t"
                  "paddw  %%xmm7, %%xmm2        \n\t"
                  "paddw  %%xmm7, %%xmm6        \n\t"
                  "pmulhw %%xmm4, %%xmm2        \n\t"  // Use xmm4 instead of xmm3: removes dependency on xmm3, creates independence
                  "pmulhw %%xmm4, %%xmm6        \n\t"
                  "paddw    (%0), %%xmm2        \n\t"
                  "paddw  16(%0), %%xmm6        \n\t"
                  "movdqa %%xmm2, (%0)          \n\t"
                  "movdqa %%xmm6, 16(%0)        \n\t"
                  // Introduced WAW hazard on xmm2/xmm6 by reusing same registers but with different source data
                  // Also removed loop-carried dependency via xmm3 by using xmm4 (assumed initialized outside)
                  : 
                  : "r" (&b[i]), "r" (&ref[i]) 
                  : "memory");
}
}
