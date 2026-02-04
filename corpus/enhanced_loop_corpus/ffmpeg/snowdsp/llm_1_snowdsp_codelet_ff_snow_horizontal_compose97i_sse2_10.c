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
    for (int stride = 32; i < w_l - 15; i += stride) {
        // Deep unroll mimic via larger step and dual block processing
        if (i + 16 < w_l - 15) {
            asm volatile (
                // First 16-byte block
                "movdqu   (%1), %%xmm1        \n\t"
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
                
                // Second 16-byte block offset by 16
                "movdqu  16(%1), %%xmm1      \n\t"
                "movdqu  32(%1), %%xmm5      \n\t"
                "movdqu  18(%1), %%xmm2      \n\t"
                "movdqu  34(%1), %%xmm6      \n\t"
                "paddw   %%xmm1, %%xmm2      \n\t"
                "paddw   %%xmm5, %%xmm6      \n\t"
                "paddw   %%xmm7, %%xmm2      \n\t"
                "paddw   %%xmm7, %%xmm6      \n\t"
                "pmulhw  %%xmm3, %%xmm2      \n\t"
                "pmulhw  %%xmm3, %%xmm6      \n\t"
                "paddw   16(%0), %%xmm2      \n\t"
                "paddw   32(%0), %%xmm6      \n\t"
                "movdqa  %%xmm2, 16(%0)      \n\t"
                "movdqa  %%xmm6, 32(%0)      \n\t"
                :
                : "r"(&b[i]), "r"(&ref[i])
                : "memory", "xmm1", "xmm2", "xmm5", "xmm6"
            );
        } else {
            // Fallback to original logic for remaining data
            asm volatile (
                "movdqu   (%1), %%xmm1        \n\t"
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
                : "r"(&b[i]), "r"(&ref[i])
                : "memory"
            );
        }
    }
}
