#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset)[8];
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 0; n < 4; n++) {
    int m = n * 2;
    offset[0][m]       = offset[1][m]       = 16;
    offset[0][m + 1]   = offset[1][m + 1]   = 16;
    coeff[0][0][m]     = coeff[0][0][m + 1] = (1 << 14) + (1 << 7) + 1;
    coeff[0][1][m]     = coeff[0][1][m + 1] = (1 << 7) - 1;
    coeff[0][2][m]     = coeff[0][2][m + 1] = -(1 << 8);
    coeff[1][0][m]     = coeff[1][0][m + 1] = coeff[2][0][m] = coeff[2][0][m + 1] = 0;
    coeff[1][1][m]     = coeff[1][1][m + 1] = (1 << 14) + (1 << 7);
    coeff[1][2][m]     = coeff[1][2][m + 1] = -(1 << 7);
    coeff[2][2][m]     = coeff[2][2][m + 1] = (1 << 14) - (1 << 6);
    coeff[2][1][m]     = coeff[2][1][m + 1] = 1 << 6;
}
}
