#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int idx0 = i * 4 + 0;
    const int idx1 = i * 4 + 1;
    const int idx2 = i * 4 + 2;
    const int idx3 = i * 4 + 3;
    const int c0 = coef[idx0];
    const int c1 = coef[idx1];
    const int c2 = coef[idx2];
    const int c3 = coef[idx3];

    const int a1 = (c0 + c3) * 8;
    const int b1 = (c1 + c2) * 8;
    const int c1_val = (c1 - c2) * 8;
    const int d1 = (c0 - c3) * 8;

    coef[idx0] = a1 + b1;
    coef[idx2] = a1 - b1;
    coef[idx1] = (c1_val * 2217 + d1 * 5352 + 14500) >> 12;
    coef[idx3] = (d1 * 2217 - c1_val * 5352 + 7500) >> 12;
}
}
