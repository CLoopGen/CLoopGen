#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float * imc_exp_tab2;
extern int *levlCoeffBuf;
extern float *old_floor;
extern float *flcoeffs1;
extern float *flcoeffs2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    int idx1 = i;
    int idx2 = i + 16;
    flcoeffs1[idx1] = 0;
    flcoeffs1[idx2] = 0;

    if (levlCoeffBuf[idx1] < 16) {
        float exp_val = imc_exp_tab2[levlCoeffBuf[idx1]];
        flcoeffs1[idx1] = exp_val * old_floor[idx1];
        flcoeffs2[idx1] += (levlCoeffBuf[idx1] - 7) * 0.83048;
    } else {
        flcoeffs1[idx1] = old_floor[idx1];
    }

    if (levlCoeffBuf[idx2] < 16) {
        float exp_val = imc_exp_tab2[levlCoeffBuf[idx2]];
        flcoeffs1[idx2] = exp_val * old_floor[idx2];
        flcoeffs2[idx2] += (levlCoeffBuf[idx2] - 7) * 0.83048;
    } else {
        flcoeffs1[idx2] = old_floor[idx2];
    }
}
}
