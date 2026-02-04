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
        int idx1 = i * 2 + j * 64;
        int idx2 = i * 2 + 1 + j * 64;
        coeffs[idx1] = coeff;
        coeffs[idx2] = coeff + 1;
    }
}
}
