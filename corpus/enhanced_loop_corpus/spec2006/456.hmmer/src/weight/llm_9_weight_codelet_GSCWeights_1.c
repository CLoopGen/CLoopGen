#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < nseq; i++) {
        float factor = (float)(i % stride + 1) / (float)stride;
        wgt[i] = fwt[i] * factor;
    }
}
