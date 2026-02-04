#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nseq; i++) {
    wgt[i] = 1.0f / (float)nmem[c[i]];
    if (wgt[i] > 1.0f) {
        wgt[i] = 1.0f;
    }
}
}
