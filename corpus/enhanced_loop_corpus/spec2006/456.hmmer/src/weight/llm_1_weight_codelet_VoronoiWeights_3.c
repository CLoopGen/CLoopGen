#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = nseq / 2;
    int remainder = nseq % 2;
    int idx;

    for (idx = 0; idx < outer; idx++) {
        wgt[2*idx] = wgt[2*idx] / (float)itscale;
        wgt[2*idx + 1] = wgt[2*idx + 1] / (float)itscale;
    }

    if (remainder) {
        wgt[nseq - 1] = wgt[nseq - 1] / (float)itscale;
    }
}
