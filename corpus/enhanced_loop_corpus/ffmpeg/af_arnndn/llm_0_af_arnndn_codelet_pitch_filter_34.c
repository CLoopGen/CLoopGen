#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern float normf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops
    // Outer loop processes chunks of 4 elements, inner loop handles individual elements within the chunk
    int total_elements = (120 << 2) + 1;
    int chunk_size = 4;
    for (int i = 0; i < (total_elements + chunk_size - 1) / chunk_size; i++) {
        for (int j = 0; j < chunk_size; j++) {
            int idx = i * chunk_size + j;
            if (idx < total_elements) {
                X[idx].re *= normf[idx];
                X[idx].im *= normf[idx];
            }
        }
    }
}
