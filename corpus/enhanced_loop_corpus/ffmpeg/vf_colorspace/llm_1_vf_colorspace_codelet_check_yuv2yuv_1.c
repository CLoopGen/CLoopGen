#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int16_t (*offset)[8];
extern int16_t (*coeff)[3][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < 8; n += 2) {
        for (int step = 0; step < 2; step++) {
            int idx = n + step;
            if (idx < 8) {
                offset[0][idx] = offset[1][idx] = 16;
                coeff[0][0][idx] = (1 << 14) + (1 << 7) + 1;
                coeff[0][1][idx] = (1 << 7) - 1;
                coeff[0][2][idx] = -(1 << 8);
                coeff[1][0][idx] = coeff[2][0][idx] = 0;
                coeff[1][1][idx] = (1 << 14) + (1 << 7);
                coeff[1][2][idx] = -(1 << 7);
                coeff[2][2][idx] = (1 << 14) - (1 << 6);
                coeff[2][1][idx] = 1 << 6;
            }
        }
    }
}
