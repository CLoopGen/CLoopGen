#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in a strided pattern)
    // This modifies the access pattern to be non-consecutive, with stride of 2
    for (i = 0; i < nseq; i += 2) {
        wgt[i] = 1.0f / (float)nmem[c[i]];
        if (i + 1 < nseq) {
            wgt[i + 1] = 1.0f / (float)nmem[c[i + 1]];
        }
    }
    // Handle any remaining element if nseq is odd
    if (nseq % 2 == 1) {
        wgt[nseq - 1] = 1.0f / (float)nmem[c[nseq - 1]];
    }
}
