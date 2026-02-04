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
    // Variant 2: Consecutive (Linearized) Memory Access Pattern
    // Flatten the 2D iteration into a single loop with sequential access
    for (int idx = 0; idx < 32 * 32; idx++) {
        coeffs[idx] = coeff;
    }
}
