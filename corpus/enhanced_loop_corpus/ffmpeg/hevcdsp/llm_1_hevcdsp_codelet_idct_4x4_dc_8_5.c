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
int idx = 0;
for (idx = 0; idx < 16; idx++) {
    coeffs[idx] = coeff;
}
}
