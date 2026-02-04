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
    flcoeffs5[i] = workT2[i] = 0.;
    if (bandWidthT[i]) {
        workT1[i] = flcoeffs1[i] * flcoeffs1[i];
        flcoeffs3[i] = 2. * flcoeffs2[i];
    } else {
        workT1[i] = 0.;
        flcoeffs3[i] = -3.0E+4;
    }
    workT3[i] = bandWidthT[i] * workT1[i] * 0.01;
    if (workT3[i] <= snr_limit)
        workT3[i] = 0.;
}

}
