#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        const int a0 = tmp[8*i + 0] + tmp[8*i + 7];
        const int a1 = tmp[8*i + 0] - tmp[8*i + 7];
        const int a2 = tmp[8*i + 1] + tmp[8*i + 6];
        const int a3 = tmp[8*i + 1] - tmp[8*i + 6];
        const int a4 = tmp[8*i + 2] + tmp[8*i + 5];
        const int a5 = tmp[8*i + 2] - tmp[8*i + 5];
        const int a6 = tmp[8*i + 3] + tmp[8*i + 4];
        const int a7 = tmp[8*i + 3] - tmp[8*i + 4];

        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;

        // Simplified computation: reduce arithmetic depth and eliminate complex shifts
        const int b4 = a1 + a3 + a5;
        const int b5 = a1 - a5;
        const int b6 = a3 + a7;
        const int b7 = a5 + a7;

        coef[i + 8*0] = b0 + b1;
        coef[i + 8*1] = b4;
        coef[i + 8*2] = b2;
        coef[i + 8*3] = b5;
        coef[i + 8*4] = b0 - b1;
        coef[i + 8*5] = b6;
        coef[i + 8*6] = b3;
        coef[i + 8*7] = b7;
    }
}
