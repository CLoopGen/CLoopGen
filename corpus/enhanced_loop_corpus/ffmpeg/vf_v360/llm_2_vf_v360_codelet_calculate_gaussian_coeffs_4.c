#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to maintain 4 effective iterations
    for (int i = 0; i < 8; i += 2) {
        if (i / 2 < 4) {
            coeffs[i / 2] /= sum;
        }
    }
}
