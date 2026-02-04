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
    // Variant 1: Consecutive memory access using a single loop with sequential index
    int idx = 0;
    for (int k = 0; k < 16; k++) {
        coeffs[idx] = coeff;
        idx += 1;
    }
}
