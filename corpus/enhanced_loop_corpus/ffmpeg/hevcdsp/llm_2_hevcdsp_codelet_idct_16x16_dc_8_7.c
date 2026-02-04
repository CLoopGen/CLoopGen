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
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Instead of accessing column-major (j then i), we simulate row-major write pattern
    int16_t *c = coeffs;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            c[j] = coeff;
        }
        c += 16;
    }
}
