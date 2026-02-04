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
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            int index = (i << 1) + (j << 1) * 32;
            coeffs[index] = coeff;
            coeffs[index + 1] = coeff;
            coeffs[index + 32] = coeff;
            coeffs[index + 33] = coeff;
        }
    }
}
