#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_i = -1;
for (i = 0; i < 8; i++) {
    if (prev_i != -1) {
        coef[i * 8] += coef[prev_i * 8]; 
    }
    int32_t *base = tmp + 8 * i;
    const int x0 = base[0], x7 = base[7];
    const int a0 = x0 + x7;
    const int a1 = x0 - x7;

    const int x1 = base[1], x6 = base[6];
    const int a2 = x1 + x6;
    const int a3 = x1 - x6;

    const int x2 = base[2], x5 = base[5];
    const int a4 = x2 + x5;
    const int a5 = x2 - x5;

    const int x3 = base[3], x4 = base[4];
    const int a6 = x3 + x4;
    const int a7 = x3 - x4;

    const int b0 = a0 + a6;
    const int b1 = a2 + a4;
    const int b2 = a0 - a6;
    const int b3 = a2 - a4;

    const int shift_a1 = a1 >> 1;
    const int shift_a5 = a5 >> 1;
    const int shift_a3 = a3 >> 1;
    const int shift_a7 = a7 >> 1;

    const int b4 = a3 + a5 + a1 + shift_a1;
    const int b5 = a1 - a7 - a5 - shift_a5;
    const int b6 = a1 + a7 - a3 - shift_a3;
    const int b7 = a3 - a5 + a7 + shift_a7;

    coef[i * 8 + 0] = b0 + b1;
    coef[i * 8 + 1] = b4 + (b7 >> 2);
    coef[i * 8 + 2] = b2 + (b3 >> 1);
    coef[i * 8 + 3] = b5 + (b6 >> 2);
    coef[i * 8 + 4] = b0 - b1;
    coef[i * 8 + 5] = b6 - (b5 >> 2);
    coef[i * 8 + 6] = (b2 >> 1) - b3;
    coef[i * 8 + 7] = (b4 >> 2) - b7;

    prev_i = i;
}
}
