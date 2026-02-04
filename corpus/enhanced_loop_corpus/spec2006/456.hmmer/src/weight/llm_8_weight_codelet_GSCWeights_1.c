#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nseq; i += 2) {
        if (i + 1 < nseq) {
            wgt[i] = fwt[i] * 1.5f;
            wgt[i + 1] = fwt[i + 1] * 1.5f;
        } else {
            wgt[i] = fwt[i] * 1.5f;
        }
    }
}
