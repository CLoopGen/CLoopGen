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
    float temp = imc_exp_tab2[levlCoeffBuf[i]] * old_floor[i];
    float coeff2_adj = (levlCoeffBuf[i] - 7) * 0.83048;
    flcoeffs1[i] = (levlCoeffBuf[i] < 16) ? temp : old_floor[i];
    flcoeffs2[i] = (levlCoeffBuf[i] < 16) ? coeff2_adj + flcoeffs2[i] : flcoeffs2[i];
}
}
