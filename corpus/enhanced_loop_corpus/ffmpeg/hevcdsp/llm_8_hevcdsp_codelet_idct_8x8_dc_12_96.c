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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count via stride
    for (j = 0; j < 8; j += 2) {
        for (i = 0; i < 8; i += 2) {
            coeffs[i + j * 8] = coeff * 2 + 1;
            coeffs[i + j * 8 + 1] = coeff * 2 - 1;
            coeffs[i + (j + 1) * 8] = coeff * 2 + 3;
            coeffs[i + (j + 1) * 8 + 1] = coeff * 2 - 3;
        }
    }
}
