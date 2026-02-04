#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < nseq; i++) {
        for (j = 0; j < 1; j++) {
            wgt[i] = wgt[i] / (float)itscale;
        }
    }
}
