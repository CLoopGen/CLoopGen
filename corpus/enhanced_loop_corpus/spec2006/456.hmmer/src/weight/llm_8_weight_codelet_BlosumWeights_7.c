#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nseq; i++) {
        float inv_nmem = 1.0f / (float)nmem[c[i]];
        wgt[i] = inv_nmem * inv_nmem; // Square the reciprocal to increase arithmetic intensity
    }
}
