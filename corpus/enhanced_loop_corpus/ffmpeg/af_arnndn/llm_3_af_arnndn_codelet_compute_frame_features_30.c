#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;
extern float *ceps_1;
extern float *ceps_2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration and fixed offsets
    int stride = 1;
    for (int i = 5; i >= 0; i--) {
        int idx = i * stride; // Stride applied (trivially 1, but structurally strided)
        features[i] = ceps_0[idx] + ceps_1[idx] + ceps_2[idx];
        features[22 + i] = ceps_0[idx] - ceps_2[idx];
        features[28 + i] = ceps_0[idx] - 2 * ceps_1[idx] + ceps_2[idx];
    }
}
