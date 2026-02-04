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
for (i = 0; i < 16; i++) {
    int j = 2 * i;
    flcoeffs5[j] = workT2[j] = 0.;
    flcoeffs5[j+1] = workT2[j+1] = 0.;
    if (bandWidthT[j]) {
        workT1[j] = flcoeffs1[j] * flcoeffs1[j];
        flcoeffs3[j] = 2. * flcoeffs2[j];
    } else {
        workT1[j] = 0.;
        flcoeffs3[j] = -3.0E+4;
    }
    if (bandWidthT[j+1]) {
        workT1[j+1] = flcoeffs1[j+1] * flcoeffs1[j+1];
        flcoeffs3[j+1] = 2. * flcoeffs2[j+1];
    } else {
        workT1[j+1] = 0.;
        flcoeffs3[j+1] = -3.0E+4;
    }
    workT3[j] = bandWidthT[j] * workT1[j] * 0.01;
    workT3[j+1] = bandWidthT[j+1] * workT1[j+1] * 0.01;
    if (workT3[j] <= snr_limit)
        workT3[j] = 0.;
    if (workT3[j+1] <= snr_limit)
        workT3[j+1] = 0.;
}
}
