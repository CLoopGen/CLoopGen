#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < nseq; i++) {
        temp = 1.0f / (float)nmem[c[i]];
        wgt[i] = temp;
    }
}
