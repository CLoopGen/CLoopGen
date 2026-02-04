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
    if (c[i] < 0) {
        wgt[i] = 0.0f;
        continue;
    }
    wgt[i] = 1.0f / (float)nmem[c[i]];
}
}
