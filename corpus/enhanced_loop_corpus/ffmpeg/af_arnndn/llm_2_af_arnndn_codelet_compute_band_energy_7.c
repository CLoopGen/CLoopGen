#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bandE;
extern float sum[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle pairs
    for (int i = 0; i < 22; i += 2) {
        if (i < 22) bandE[i] = sum[i];
        if (i + 1 < 22) bandE[i + 1] = sum[i + 1];
    }
}
