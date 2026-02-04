#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *flcoeffs1;
extern float *flcoeffs2;
extern int *bandWidthT;
extern float *flcoeffs3;
extern float *flcoeffs5;
extern float workT1[32];
extern float workT2[32];
extern float workT3[32];
extern float snr_limit;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    int idx = i;
    flcoeffs5[idx] = workT2[idx] = 0.;
    if (bandWidthT[idx]) {
        workT1[idx] = flcoeffs1[idx] * flcoeffs1[idx];
        flcoeffs3[idx] = 2. * flcoeffs2[idx];
    } else {
        workT1[idx] = 0.;
        flcoeffs3[idx] = -3.0E+4;
    }
    workT3[idx] = bandWidthT[idx] * workT1[idx] * 0.01;
    if (workT3[idx] <= snr_limit)
        workT3[idx] = 0.;
}
}
