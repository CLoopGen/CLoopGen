#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset)[8];
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp_offset[8];
    int16_t temp_coeff[3][3][8];
    for (n = 0; n < 8; n++) {
        temp_offset[n] = 16;
        temp_coeff[0][0][n] = (1 << 14) + (1 << 7) + 1;
        temp_coeff[0][1][n] = (1 << 7) - 1;
        temp_coeff[0][2][n] = -(1 << 8);
        temp_coeff[1][1][n] = (1 << 14) + (1 << 7);
        temp_coeff[1][2][n] = -(1 << 7);
        temp_coeff[2][2][n] = (1 << 14) - (1 << 6);
        temp_coeff[2][1][n] = 1 << 6;
    }
    for (n = 0; n < 8; n++) {
        offset[0][n] = temp_offset[n];
        offset[1][n] = temp_offset[n];
        coeff[0][0][n] = temp_coeff[0][0][n];
        coeff[0][1][n] = temp_coeff[0][1][n];
        coeff[0][2][n] = temp_coeff[0][2][n];
        coeff[1][0][n] = coeff[2][0][n] = 0;
        coeff[1][1][n] = temp_coeff[1][1][n];
        coeff[1][2][n] = temp_coeff[1][2][n];
        coeff[2][2][n] = temp_coeff[2][2][n];
        coeff[2][1][n] = temp_coeff[2][1][n];
    }
}
