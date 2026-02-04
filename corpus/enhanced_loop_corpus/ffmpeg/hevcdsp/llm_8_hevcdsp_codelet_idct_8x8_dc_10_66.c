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
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled inner loop
    for (j = 0; j < 8; j++) {
        int base = j * 8;
        coeffs[base + 0] = coeff + 1;
        coeffs[base + 1] = coeff + 2;
        coeffs[base + 2] = coeff + 3;
        coeffs[base + 3] = coeff + 4;
        coeffs[base + 4] = coeff + 5;
        coeffs[base + 5] = coeff + 6;
        coeffs[base + 6] = coeff + 7;
        coeffs[base + 7] = coeff + 8;
    }
}
