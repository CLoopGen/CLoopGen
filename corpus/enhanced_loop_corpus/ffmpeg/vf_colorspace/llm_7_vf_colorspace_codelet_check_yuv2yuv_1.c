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
        int16_t base_val = 16;
        int16_t c00 = (1 << 14) + (1 << 7) + 1;
        int16_t c01 = (1 << 7) - 1;
        int16_t c02 = -(1 << 8);
        int16_t c11 = (1 << 14) + (1 << 7);
        int16_t c12 = -(1 << 7);
        int16_t c22 = (1 << 14) - (1 << 6);
        int16_t c21 = 1 << 6;

        offset[0][n] = base_val;
        offset[1][n] = offset[0][n]; // Introduce RAW dependency on previous store

        coeff[0][0][n] = c00;
        coeff[0][1][n] = c01;
        coeff[0][2][n] = c02;
        coeff[1][0][n] = 0;
        coeff[2][0][n] = coeff[1][0][n]; // WAW and WAR introduced via shared index
        coeff[1][1][n] = c11;
        coeff[1][2][n] = c12;
        coeff[2][1][n] = c21;
        coeff[2][2][n] = c22;

        // Introduce loop-carried dependence: each iteration depends on prior's coeff[2][2]
        if (n > 0) {
            coeff[0][0][n] += coeff[2][2][n-1] >> 12; // Use previous value (RAW loop-carried)
        }
    }
}
