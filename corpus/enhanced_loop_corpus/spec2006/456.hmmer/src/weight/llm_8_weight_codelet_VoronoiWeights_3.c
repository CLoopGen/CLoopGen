#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 0; idx < nseq; idx += 2) {
        if (idx + 1 < nseq) {
            wgt[idx]     = wgt[idx]     / (float)itscale;
            wgt[idx + 1] = wgt[idx + 1] / (float)itscale;
        } else {
            wgt[idx] = wgt[idx] / (float)itscale;
        }
    }
}
