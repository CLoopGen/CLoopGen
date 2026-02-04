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
    int base = j * 4;
    for (i = 0; i < 2; i++) {
        coeffs[base + i] = coeff;
        coeffs[base + i + 2] = coeff;
    }
}
}
