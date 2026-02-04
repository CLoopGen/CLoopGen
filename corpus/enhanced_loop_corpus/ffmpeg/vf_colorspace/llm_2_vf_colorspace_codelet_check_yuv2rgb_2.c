#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset);
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 8; n++) {
    int idx = n;
    offset[idx] = 16;
    coeff[0][0][idx] = coeff[1][0][idx] = coeff[2][0][idx] = (1 << 14) | 1;
    coeff[0][1][idx] = coeff[2][2][idx] = 0;
    coeff[0][2][idx] = 1 << 13;
    coeff[1][1][idx] = -(1 << 12);
    coeff[1][2][idx] = 1 << 12;
    coeff[2][1][idx] = 1 << 11;
}
}
