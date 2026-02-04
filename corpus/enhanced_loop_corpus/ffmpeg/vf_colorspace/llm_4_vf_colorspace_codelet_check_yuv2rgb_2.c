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
        offset[n] = 16;
        coeff[0][0][n] = coeff[1][0][n] = coeff[2][0][n] = (1 << 14) | 1;
        if (n % 2 == 0) {
            coeff[0][1][n] = coeff[2][2][n] = 0;
            coeff[0][2][n] = 1 << 13;
        } else {
            coeff[0][1][n] = coeff[2][2][n] = -1;
            coeff[0][2][n] = 0;
        }
        coeff[1][1][n] = -(1 << 12);
        coeff[1][2][n] = 1 << 12;
        coeff[2][1][n] = 1 << 11;
    }
}
