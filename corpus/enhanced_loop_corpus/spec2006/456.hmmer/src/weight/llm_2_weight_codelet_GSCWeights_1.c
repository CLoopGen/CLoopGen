#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq; i += 2) {
        wgt[i] = fwt[i];
        if (i + 1 < nseq)
            wgt[i + 1] = fwt[i + 1];
    }
}
