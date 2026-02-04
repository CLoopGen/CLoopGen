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
    for (int outer = i; outer < w_l - 15; outer += 16) {
        for (int inner = 0; inner < 1; ++inner) { // Artificially nested with fixed depth
            int idx = outer;
            asm volatile ("movdqu   (%1), %%xmm1        \n\t"
                          "movdqu 16(%1), %%xmm5        \n\t"
                          "movdqu  2(%1), %%xmm2        \n\t"
                          "movdqu 18(%1), %%xmm6        \n\t"
                          "paddw  %%xmm1, %%xmm2        \n\t"
                          "paddw  %%xmm5, %%xmm6        \n\t"
                          "paddw  %%xmm7, %%xmm2        \n\t"
                          "paddw  %%xmm7, %%xmm6        \n\t"
                          "pmulhw %%xmm3, %%xmm2        \n\t"
                          "pmulhw %%xmm3, %%xmm6        \n\t"
                          "paddw    (%0), %%xmm2        \n\t"
                          "paddw  16(%0), %%xmm6        \n\t"
                          "movdqa %%xmm2, (%0)          \n\t"
                          "movdqa %%xmm6, 16(%0)        \n\t"
                          : 
                          : "r" (&b[idx]), "r" (&ref[idx])
                          : "memory");
        }
    }
}
