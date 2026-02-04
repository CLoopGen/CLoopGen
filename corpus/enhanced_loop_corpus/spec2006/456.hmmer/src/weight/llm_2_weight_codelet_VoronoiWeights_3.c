#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then odd indices)
    int i;
    for (i = 0; i < nseq; i += 2) {
        idx = i;
        wgt[idx] = wgt[idx] / (float)itscale;
    }
    for (i = 1; i < nseq; i += 2) {
        idx = i;
        wgt[idx] = wgt[idx] / (float)itscale;
    }
}
