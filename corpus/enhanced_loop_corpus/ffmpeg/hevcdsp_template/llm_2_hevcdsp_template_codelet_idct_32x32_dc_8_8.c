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
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (i + j * 32), traverse with a stride of 33 to create non-contiguous, diagonal-like access
    for (j = 0; j < 32; j++) {
        for (i = 0; i < 32; i++) {
            int index = (i * 33 + j) % (32 * 32); // Strided access with wrap-around to stay in bounds
            coeffs[index] = coeff;
        }
    }
}
