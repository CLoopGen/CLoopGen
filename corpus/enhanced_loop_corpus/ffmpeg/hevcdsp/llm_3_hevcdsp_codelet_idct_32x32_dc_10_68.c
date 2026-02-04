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
    // Variant 2: Strided memory access with a fixed stride pattern skipping elements
    int stride = 65; // Stride greater than row size to create non-trivial access pattern
    int index = 0;
    for (j = 0; j < 32; j++) {
        for (i = 0; i < 32; i++) {
            index = (i * stride + j) % (32 * 32); // Ensure within bounds using modulo
            coeffs[index] = coeff;
        }
    }
}
