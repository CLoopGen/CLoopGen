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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled inner loop
    for (j = 0; j < 8; j++) {
        int base_index = j * 8;
        coeffs[base_index]     = coeff + 1;
        coeffs[base_index + 1] = coeff + 2;
        coeffs[base_index + 2] = coeff + 3;
        coeffs[base_index + 3] = coeff + 4;
        coeffs[base_index + 4] = coeff + 5;
        coeffs[base_index + 5] = coeff + 6;
        coeffs[base_index + 6] = coeff + 7;
        coeffs[base_index + 7] = coeff + 8;
    }
}
