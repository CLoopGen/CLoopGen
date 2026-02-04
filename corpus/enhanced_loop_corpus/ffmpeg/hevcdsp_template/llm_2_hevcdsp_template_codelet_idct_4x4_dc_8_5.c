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
    // by flipping the loop nesting to promote spatial locality.
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            coeffs[i + j * 4] = coeff;
        }
    }
}
