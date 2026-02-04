#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset)[8];
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (n = 0; n < 8; n++) {
    offset[0][n] = offset[1][n] = 16;
    coeff[0][0][n] = (1 << 14) + (1 << 7) + 1;
    coeff[0][1][n] = (1 << 7) - 1;
    coeff[0][2][n] = -(1 << 8);
    coeff[1][0][n] = coeff[2][0][n] = 0;
    coeff[1][1][n] = (1 << 14) + (1 << 7);
    coeff[1][2][n] = -(1 << 7);
    coeff[2][2][n] = (1 << 14) - (1 << 6);
    coeff[2][1][n] = 1 << 6;
}

}
