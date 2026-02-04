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
    for (; i < w_r - 15 && (w_r - i) >= 16; i += 16) {
        const int offset_b = i;
        const int offset_dst = i;
        
        if (offset_b + 18 < w_r * 2) {
            asm volatile ("movdqu   (%1), %%xmm1        \n\t"
                          "movdqu 16(%1), %%xmm5        \n\t"
                          "movdqu  2(%1), %%xmm2        \n\t"
                          "movdqu 18(%1), %%xmm6        \n\t"
                          "paddw  %%xmm1, %%xmm2        \n\t"
                          "paddw  %%xmm5, %%xmm6        \n\t"
                          "movdqa   (%0), %%xmm0        \n\t"
                          "movdqa 16(%0), %%xmm4        \n\t"
                          "psubw  %%xmm2, %%xmm0        \n\t"
                          "psubw  %%xmm6, %%xmm4        \n\t"
                          "movdqa %%xmm0, (%0)          \n\t"
                          "movdqa %%xmm4, 16(%0)        \n\t"
                          : 
                          : "r" (&dst[offset_dst]), "r" (&b[offset_b]) 
                          : "memory");
        } else {
            i = w_r - 15; // Force exit by setting i to boundary
        }
    }
}
