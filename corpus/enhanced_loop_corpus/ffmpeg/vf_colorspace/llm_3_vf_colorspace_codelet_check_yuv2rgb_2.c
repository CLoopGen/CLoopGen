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
    int stride_idx = n * 1;
    offset[stride_idx] = 16;
    coeff[0][0][stride_idx] = coeff[1][0][stride_idx] = coeff[2][0][stride_idx] = (1 << 14) | 1;
    coeff[0][1][stride_idx] = coeff[2][2][stride_idx] = 0;
    coeff[0][2][stride_idx] = 1 << 13;
    coeff[1][1][stride_idx] = -(1 << 12);
    coeff[1][2][stride_idx] = 1 << 12;
    coeff[2][1][stride_idx] = 1 << 11;
}
}
