#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < nseq; i++)
        wgt[i] = fwt[i-1];
    if (nseq > 0)
        wgt[0] = fwt[0];
}
