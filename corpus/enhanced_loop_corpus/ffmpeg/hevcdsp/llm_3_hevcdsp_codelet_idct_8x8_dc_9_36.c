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
    // Variant 2: Strided memory access with a fixed stride of 8 (column-major traversal)
    for (i = 0; i < 64; i += 8) {
        for (j = 0; j < 8; j++) {
            coeffs[i + j] = coeff;
        }
    }
}
