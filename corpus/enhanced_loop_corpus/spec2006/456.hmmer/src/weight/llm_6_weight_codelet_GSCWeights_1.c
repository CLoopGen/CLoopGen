#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < nseq; i++) {
        temp = fwt[i];
        wgt[i] = temp;
    }
}
