#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idx = 0; idx < nseq; idx++) {
        if (wgt[idx] == 0.0f) {
            continue;
        }
        wgt[idx] = wgt[idx] / (float)itscale;
    }
}
