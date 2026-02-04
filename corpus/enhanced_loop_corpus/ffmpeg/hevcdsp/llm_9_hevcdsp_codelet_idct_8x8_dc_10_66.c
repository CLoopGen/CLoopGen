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
    // Variant 2: Reduced computational intensity with increased trip count via flattened indexing and stride modification
    for (i = 0; i < 64; i += 2) {
        coeffs[i] = coeff;
        if (i + 1 < 64) {
            coeffs[i + 1] = coeff;
        }
    }
}
