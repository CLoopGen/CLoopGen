#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float imc_exp_tab[32];
extern int *levlCoeffBuf;
extern float *flcoeffs1;
extern float *flcoeffs2;
extern int i;
extern int level;
extern float tmp;
extern float tmp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing elements sequentially (i), we use a stride of 2, traversing even indices first, then odd.
    int stride = 2;
    for (i = 1; i < 32; i += stride) {
        level = levlCoeffBuf[i];
        if (level == 16) {
            flcoeffs1[i] = 1.;
            flcoeffs2[i] = 0.;
        } else {
            if (level < 17)
                level -= 7;
            else if (level <= 24)
                level -= 32;
            else
                level -= 16;
            tmp *= imc_exp_tab[15 + level];
            tmp2 += 0.83048 * level;
            flcoeffs1[i] = tmp;
            flcoeffs2[i] = tmp2;
        }
    }
    // Handle remaining index if stride skips any
    for (i = 2; i < 32; i += stride) {
        level = levlCoeffBuf[i];
        if (level == 16) {
            flcoeffs1[i] = 1.;
            flcoeffs2[i] = 0.;
        } else {
            if (level < 17)
                level -= 7;
            else if (level <= 24)
                level -= 32;
            else
                level -= 16;
            tmp *= imc_exp_tab[15 + level];
            tmp2 += 0.83048 * level;
            flcoeffs1[i] = tmp;
            flcoeffs2[i] = tmp2;
        }
    }
}
