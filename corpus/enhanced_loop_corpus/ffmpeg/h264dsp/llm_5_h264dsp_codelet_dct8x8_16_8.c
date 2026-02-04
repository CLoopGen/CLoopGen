#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        const int idx_base = i;
        const int c0 = coef[idx_base + 8*0], c7 = coef[idx_base + 8*7];
        const int c1 = coef[idx_base + 8*1], c6 = coef[idx_base + 8*6];
        const int c2 = coef[idx_base + 8*2], c5 = coef[idx_base + 8*5];
        const int c3 = coef[idx_base + 8*3], c4 = coef[idx_base + 8*4];

        const int a0 = c0 + c7, a1 = c0 - c7;
        const int a2 = c1 + c6, a3 = c1 - c6;
        const int a4 = c2 + c5, a5 = c2 - c5;
        const int a6 = c3 + c4, a7 = c3 - c4;

        const int b0 = a0 + a6, b1 = a2 + a4;
        const int b2 = a0 - a6, b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));

        tmp[idx_base + 8*0] = b0 + b1;
        
        if (b0 >= 0) {
            tmp[idx_base + 8*1] = b4 + (b7 >> 2);
            tmp[idx_base + 8*5] = b6 - (b5 >> 2);
        } else {
            tmp[idx_base + 8*1] = (b4 >> 2) - b7;
            tmp[idx_base + 8*5] = b5 + (b6 >> 2);
        }

        tmp[idx_base + 8*2] = b2 + (b3 >> 1);

        if (b3 != 0) {
            tmp[idx_base + 8*3] = b5 + (b6 >> 2);
            tmp[idx_base + 8*6] = (b2 >> 1) - b3;
        } else {
            tmp[idx_base + 8*3] = (b6 >> 2) - b5;
            tmp[idx_base + 8*6] = b2 - (b3 >> 1);
        }

        tmp[idx_base + 8*4] = b0 - b1;

        if ((b7 & 1) == 0) {
            tmp[idx_base + 8*7] = (b4 >> 2) - b7;
        } else {
            tmp[idx_base + 8*7] = b4 + (b7 >> 2);
        }
    }
}
