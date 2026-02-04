#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating irregular access pattern)
    int indices[4] = {3, 1, 0, 2}; // Reordered access: process elements in non-linear order
    for (int i = 0; i < 4; i++) {
        coeffs[indices[i]] /= sum;
    }
}
