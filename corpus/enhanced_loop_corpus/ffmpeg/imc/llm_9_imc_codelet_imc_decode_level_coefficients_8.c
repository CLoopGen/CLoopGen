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
for (i = 1; i < 16; i++) {
    int idx1 = i;
    int idx2 = 31 - i;
    level = levlCoeffBuf[idx1];
    int level2 = levlCoeffBuf[idx2];

    // Process first index
    if (level == 16) {
        flcoeffs1[idx1] = 1.0f;
        flcoeffs2[idx1] = 0.0f;
    } else {
        int adj_level = (level < 17) ? level - 7 : (level <= 24) ? level - 32 : level - 16;
        float exp_val = imc_exp_tab[15 + adj_level];
        float scaled = 0.83048f * adj_level;
        flcoeffs1[idx1] = tmp * exp_val;
        flcoeffs2[idx1] = tmp2 + scaled;
    }

    // Process symmetric second index with combined arithmetic
    if (level2 == 16) {
        flcoeffs1[idx2] = 1.0f;
        flcoeffs2[idx2] = 0.0f;
    } else {
        int adj_level2 = (level2 < 17) ? level2 - 7 : (level2 <= 24) ? level2 - 32 : level2 - 16;
        tmp *= imc_exp_tab[15 + adj_level2];
        tmp2 += 0.83048f * adj_level2;
        flcoeffs1[idx2] = tmp;
        flcoeffs2[idx2] = tmp2;
    }
}
}
