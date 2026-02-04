#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to maintain same logical operations
    // Access pattern: 0, 2 (since array size is 4, we simulate strided access within bounds)
    for (int i = 0; i < 4; i += 2) {
        coeffs[i] /= sum;
        if (i + 1 < 4) {
            coeffs[i + 1] /= sum;
        }
    }
}
