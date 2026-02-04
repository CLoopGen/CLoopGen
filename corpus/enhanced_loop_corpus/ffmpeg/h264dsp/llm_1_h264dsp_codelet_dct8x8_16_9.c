#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (int inner = 0; inner < 4; inner++) {
        const int idx = outer * 4 + inner;
        const int base = 8 * idx;
        const int a0 = tmp[base + 0] + tmp[base + 7];
        const int a1 = tmp[base + 0] - tmp[base + 7];
        const int a2 = tmp[base + 1] + tmp[base + 6];
        const int a3 = tmp[base + 1] - tmp[base + 6];
        const int a4 = tmp[base + 2] + tmp[base + 5];
        const int a5 = tmp[base + 2] - tmp[base + 5];
        const int a6 = tmp[base + 3] + tmp[base + 4];
        const int a7 = tmp[base + 3] - tmp[base + 4];
        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));
        coef[idx + 0] = b0 + b1;
        coef[idx + 8] = b4 + (b7 >> 2);
        coef[idx + 16] = b2 + (b3 >> 1);
        coef[idx + 24] = b5 + (b6 >> 2);
        coef[idx + 32] = b0 - b1;
        coef[idx + 40] = b6 - (b5 >> 2);
        coef[idx + 48] = (b2 >> 1) - b3;
        coef[idx + 56] = (b4 >> 2) - b7;
    }
}
}
