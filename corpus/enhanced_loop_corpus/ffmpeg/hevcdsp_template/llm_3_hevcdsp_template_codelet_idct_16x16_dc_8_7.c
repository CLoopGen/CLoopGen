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
    // Variant 2: Consecutive memory access using linear index (flattened loop)
    int idx;
    for (idx = 0; idx < 256; idx++) {
        coeffs[idx] = coeff;
    }
}
