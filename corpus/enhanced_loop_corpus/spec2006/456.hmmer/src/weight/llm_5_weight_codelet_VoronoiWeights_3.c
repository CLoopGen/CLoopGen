#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 0; idx < nseq; idx++) {
        wgt[idx] = wgt[idx] / (float)itscale;
        if (idx % 2 == 0) {
            wgt[idx] *= 1.0f; // No-op to create control divergence without altering result
        }
    }
}
