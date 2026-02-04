#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int idx;
extern int itscale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale = (float)itscale;
    for (idx = 0; idx < nseq; idx++) {
        float temp = wgt[idx] / scale;
        wgt[idx] = temp;
    }
}
