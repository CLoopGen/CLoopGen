#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern  float *bdw;
extern double mean[4];
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    double cmean1 = 0., cmean2 = 0., cmean3 = 0., cmean4 = 0.;
    for (k = 0; k < 16; k++) {
        int idx1 = offt[j * 64 + k];
        int idx2 = offt[j * 64 + k + 16];
        int idx3 = offt[j * 64 + k + 32];
        int idx4 = offt[j * 64 + k + 48];
        cmean1 += bdw[idx1];
        cmean2 += bdw[idx2];
        cmean3 += bdw[idx3];
        cmean4 += bdw[idx4];
    }
    mean[j] = (cmean1 + cmean2 + cmean3 + cmean4) / 64.;
}
}
