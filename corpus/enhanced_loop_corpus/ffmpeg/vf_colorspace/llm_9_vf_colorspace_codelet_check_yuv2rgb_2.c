#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset);
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 16; n += 2) {
        int idx = n >> 1;
        int16_t val1 = (1 << 14) | 1;
        int16_t val2 = 1 << 13;
        int16_t val3 = -(1 << 12);
        int16_t val4 = 1 << 12;
        int16_t val5 = 1 << 11;

        offset[idx] = 16;

        coeff[0][0][idx] = val1;
        coeff[1][0][idx] = val1;
        coeff[2][0][idx] = val1;

        coeff[0][1][idx] = 0;
        coeff[2][2][idx] = 0;

        coeff[0][2][idx] = val2;
        coeff[1][1][idx] = val3;
        coeff[1][2][idx] = val4;
        coeff[2][1][idx] = val5;
    }
}
