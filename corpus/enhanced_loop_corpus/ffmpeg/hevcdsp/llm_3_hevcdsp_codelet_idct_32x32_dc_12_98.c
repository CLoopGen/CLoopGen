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
    // Variant 2: Strided memory access with stride of 32
    // Instead of iterating through each row, traverse one column at a time with fixed stride
    // Here we flatten the loop and access every 32nd element consecutively
    for (i = 0; i < 32; i++) {
        int base = i * 32;
        for (j = 0; j < 32; j++) {
            coeffs[base + j] = coeff;
        }
    }
}
