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
    // Variant 2: Reduced trip count with increased outer complexity and stride modification
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 16; i += 2) {
            int index = i + (j * 16);
            coeffs[index] = coeff;
            coeffs[index + 1] = coeff; // Write two elements per iteration
        }
    }
}
