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
    int16_t *base = &coeffs[j * 16];
    for (i = 0; i < 16; i += 4) {
        base[i]     = coeff;
        base[i + 1] = coeff;
        base[i + 2] = coeff;
        base[i + 3] = coeff;
    }
}
}
