#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bandE;
extern float sum[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access
    int indices[22];
    for (int i = 0; i < 22; i++) {
        indices[i] = i; // Direct mapping for correctness, but enables indirect pattern
    }
    for (int i = 0; i < 22; i++) {
        int idx = indices[i];
        bandE[idx] = sum[idx];
    }
}
