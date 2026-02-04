#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq; i++) {
        if (i % 2 == 0) {
            wgt[i] = fwt[i];
        } else {
            continue;
        }
    }
}
