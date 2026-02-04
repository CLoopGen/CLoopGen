#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order
    // Instead of accessing column-major (j then i), we simulate row-major write pattern
    // by iterating over linear index with consecutive strides
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            coeffs[i * 4 + j] = coeff;
        }
    }
}
