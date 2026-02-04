#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *d;
extern int k;
extern word wt[40];
extern word scal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, then fill in)
    int stride = 2;
    int offset;
    for (k = 0; k < stride; k++) {
        for (int j = k; j <= 39; j += stride) {
            wt[j] = (d[j] >> scal);
        }
    }
}
