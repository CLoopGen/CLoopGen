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
    for (i = 0; i < 32; i++) {
        flcoeffs1[i] = 0;
    }
    for (i = 0; i < 32; i++) {
        if (levlCoeffBuf[i] < 16) {
            float exp_val = imc_exp_tab2[levlCoeffBuf[i]];
            float product = exp_val * old_floor[i];
            flcoeffs1[i] = product;
            flcoeffs2[i] = (levlCoeffBuf[i] - 7) * 0.83048 + flcoeffs2[i];
        } else {
            flcoeffs1[i] = old_floor[i];
        }
    }
}
