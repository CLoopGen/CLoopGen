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
    // Variant 1: Consecutive memory access by transposing the loop order to iterate row-major
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            coeffs[j + i * 8] = coeff;
        }
    }
}
