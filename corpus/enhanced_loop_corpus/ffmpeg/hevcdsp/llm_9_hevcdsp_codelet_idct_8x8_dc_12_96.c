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
    // Variant 2: Reduced computational intensity with flattened loop and increased trip count, minimal arithmetic
    int idx = 0;
    for (i = 0; i < 64; i++) {
        idx = i;
        coeffs[idx] = coeff;
    }
}
