#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern int *c;
extern int *nmem;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the arrays in reverse order (from end to start)
    // This changes the spatial locality and access direction
    for (i = nseq - 1; i >= 0; i--) {
        wgt[i] = 1.0f / (float)nmem[c[i]];
    }
}
