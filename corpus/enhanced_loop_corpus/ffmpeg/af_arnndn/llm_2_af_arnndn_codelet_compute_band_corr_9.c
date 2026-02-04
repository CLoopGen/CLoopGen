#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bandE;
extern float sum[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    for (int i = 0; i < 22; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        if (idx1 < 22)
            bandE[idx1] = sum[idx1];
        if (idx2 < 22)
            bandE[idx2] = sum[idx2];
    }
}
