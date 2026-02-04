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
    // Variant 1: Consecutive memory access with row-major to column-major order swap
    // This changes the access pattern from row-wise (i changing fastest) to column-wise (j changing fastest)
    // effectively writing in a transposed manner but still covering all elements
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            coeffs[j + i * 32] = coeff;
        }
    }
}
