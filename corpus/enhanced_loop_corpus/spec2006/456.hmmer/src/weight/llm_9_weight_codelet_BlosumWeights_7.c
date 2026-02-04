#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < nseq; i += stride) {
        if (i + 1 < nseq) {
            wgt[i]     = 1.0f / (float)nmem[c[i]];
            wgt[i + 1] = 1.0f / (float)nmem[c[i + 1]];
        } else {
            wgt[i] = 1.0f / (float)nmem[c[i]];
        }
    }
}
