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
    for (j = 0; j < 4; j++) {
        coeffs[j * 4 + 0] = coeff;
        coeffs[j * 4 + 1] = coeff;
        coeffs[j * 4 + 2] = coeff;
        coeffs[j * 4 + 3] = coeff;
    }
}
