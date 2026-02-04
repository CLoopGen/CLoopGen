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
        int index1 = i * 2 + j * 32 * 2;
        int index2 = index1 + 1;
        coeffs[index1] = coeff;
        coeffs[index2] = coeff;
    }
}
}
