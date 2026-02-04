#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < 2; k++) {
    for (i = 0; i < 4; i++) {
        const int a1 = coef[i + 0 * 4] + coef[i + 3 * 4];
        const int b1 = coef[i + 1 * 4] + coef[i + 2 * 4];
        const int c1 = coef[i + 1 * 4] - coef[i + 2 * 4];
        const int d1 = coef[i + 0 * 4] - coef[i + 3 * 4];
        coef[i + 0 * 4] = (a1 + b1 + 7) >> 4;
        coef[i + 1 * 4] = ((c1 * 2217 + d1 * 5352 + 12000) >> 16) + !!d1;
        coef[i + 2 * 4] = (a1 - b1 + 7) >> 4;
        coef[i + 3 * 4] = (d1 * 2217 - c1 * 5352 + 51000) >> 16;
    }
}
}
