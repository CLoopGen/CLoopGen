#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < nseq; i++) {
        wgt[i] = 1.0f / (float)nmem[c[i-1]]; // Introduces loop-carried dependency: wgt[i] depends on c[i-1]
    }
    if (nseq > 0) {
        wgt[0] = 1.0f / (float)nmem[c[0]]; // Handle first iteration separately to maintain correctness
    }
}
