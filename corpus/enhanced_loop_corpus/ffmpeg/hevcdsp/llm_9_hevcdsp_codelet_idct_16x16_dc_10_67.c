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
for (j = 0; j < 8; j++) {
    for (i = 0; i < 8; i++) {
        int index = (i << 3) + (j << 4); // Equivalent to i*8 + j*16, reduced total iterations but increased arithmetic per iteration
        coeffs[index] = coeff;
        coeffs[index + 8] = coeff;
        coeffs[index + 128] = coeff;
        coeffs[index + 136] = coeff;
    }
}
}
