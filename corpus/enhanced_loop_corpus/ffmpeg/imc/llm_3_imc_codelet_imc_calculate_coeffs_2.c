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
for (i = 0; i < 32; i += 2) {
    int idx1 = i;
    int idx2 = i + 1;
    flcoeffs5[idx1] = workT2[idx1] = 0.;
    workT3[idx1] = 0.;
    if (bandWidthT[idx1]) {
        workT1[idx1] = flcoeffs1[idx1] * flcoeffs1[idx1];
        flcoeffs3[idx1] = 2. * flcoeffs2[idx1];
    } else {
        workT1[idx1] = 0.;
        flcoeffs3[idx1] = -3.0E+4;
    }
    workT3[idx1] = bandWidthT[idx1] * workT1[idx1] * 0.01;
    if (workT3[idx1] <= snr_limit)
        workT3[idx1] = 0.;

    if (idx2 < 32) {
        flcoeffs5[idx2] = workT2[idx2] = 0.;
        if (bandWidthT[idx2]) {
            workT1[idx2] = flcoeffs1[idx2] * flcoeffs1[idx2];
            flcoeffs3[idx2] = 2. * flcoeffs2[idx2];
        } else {
            workT1[idx2] = 0.;
            flcoeffs3[idx2] = -3.0E+4;
        }
        workT3[idx2] = bandWidthT[idx2] * workT1[idx2] * 0.01;
        if (workT3[idx2] <= snr_limit)
            workT3[idx2] = 0.;
    }
}
}
