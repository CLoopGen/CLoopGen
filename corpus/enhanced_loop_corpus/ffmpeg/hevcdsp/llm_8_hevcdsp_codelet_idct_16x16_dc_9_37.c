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
    int16_t *row_start = &coeffs[j * 16];
    for (i = 0; i < 16; i++) {
        row_start[i] = coeff;
        row_start[i] *= 2;
        row_start[i] += 1;
    }
}
}
