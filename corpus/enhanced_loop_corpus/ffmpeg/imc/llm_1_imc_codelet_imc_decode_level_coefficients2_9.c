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
    for (i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            flcoeffs1[idx] = 0;
            if (levlCoeffBuf[idx] < 16) {
                flcoeffs1[idx] = imc_exp_tab2[levlCoeffBuf[idx]] * old_floor[idx];
                flcoeffs2[idx] = (levlCoeffBuf[idx] - 7) * 0.83048 + flcoeffs2[idx];
            } else {
                flcoeffs1[idx] = old_floor[idx];
            }
        }
    }
}
