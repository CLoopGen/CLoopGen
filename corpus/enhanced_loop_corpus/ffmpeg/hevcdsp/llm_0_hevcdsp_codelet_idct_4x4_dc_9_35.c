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
    // Variant 1: Consecutive memory access by flipping loop order for row-major layout
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            coeffs[j + i * 4] = coeff;
        }
    }
}
