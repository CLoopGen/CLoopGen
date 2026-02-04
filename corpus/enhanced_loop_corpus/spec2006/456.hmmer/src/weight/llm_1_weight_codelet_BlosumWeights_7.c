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
    for (int j = 0; j < 1; j++) {
        wgt[i] = 1. / (float)nmem[c[i]];
    }
}
}
