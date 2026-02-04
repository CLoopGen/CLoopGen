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
    for (j = 0; j < 4; j++) {
        int base_index = j * 4;
        coeffs[base_index]     = coeff * 2 + 1;
        coeffs[base_index + 1] = coeff * 3 + 2;
        coeffs[base_index + 2] = coeff * 4 + 3;
        coeffs[base_index + 3] = coeff * 5 + 4;
    }
}
