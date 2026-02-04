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
    // Instead of row-major (j then i), we simulate a more cache-friendly access
    // by iterating over a linear index that accesses elements consecutively.
    int idx = 0;
    for (idx = 0; idx < 64; idx++) {
        coeffs[idx] = coeff;
    }
}
