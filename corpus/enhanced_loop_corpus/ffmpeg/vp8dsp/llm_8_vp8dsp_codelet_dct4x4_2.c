#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int a1 = coef[i + 0 * 8] + coef[i + 7 * 8];
    const int b1 = coef[i + 1 * 8] + coef[i + 6 * 8];
    const int c1 = coef[i + 1 * 8] - coef[i + 6 * 8];
    const int d1 = coef[i + 0 * 8] - coef[i + 7 * 8];
    const int a2 = coef[i + 2 * 8] + coef[i + 5 * 8];
    const int b2 = coef[i + 3 * 8] + coef[i + 4 * 8];
    const int c2 = coef[i + 3 * 8] - coef[i + 4 * 8];
    const int d2 = coef[i + 2 * 8] - coef[i + 5 * 8];
    coef[i + 0 * 8] = (a1 + b1 + 15) >> 5;
    coef[i + 1 * 8] = ((c1 * 2217 + d1 * 5352 + 24000) >> 16) + !!d1;
    coef[i + 2 * 8] = (a2 + b2 + 15) >> 5;
    coef[i + 3 * 8] = ((c2 * 2217 + d2 * 5352 + 24000) >> 16) + !!d2;
    coef[i + 4 * 8] = (a2 - b2 + 15) >> 5;
    coef[i + 5 * 8] = (d2 * 2217 - c2 * 5352 + 102000) >> 16;
    coef[i + 6 * 8] = (a1 - b1 + 15) >> 5;
    coef[i + 7 * 8] = (d1 * 2217 - c1 * 5352 + 102000) >> 16;
}
}
