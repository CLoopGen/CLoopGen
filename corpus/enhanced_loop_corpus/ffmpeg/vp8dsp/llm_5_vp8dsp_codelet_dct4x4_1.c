#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int skip_update = (coef[i * 4 + 1] == coef[i * 4 + 2]);
    const int a1 = (coef[i * 4 + 0] + coef[i * 4 + 3]) * 8;
    const int b1 = (coef[i * 4 + 1] + coef[i * 4 + 2]) * 8;
    const int c1 = (coef[i * 4 + 1] - coef[i * 4 + 2]) * 8;
    const int d1 = (coef[i * 4 + 0] - coef[i * 4 + 3]) * 8;

    coef[i * 4 + 0] = a1 + b1;
    coef[i * 4 + 2] = a1 - b1;

    if (!skip_update) {
        coef[i * 4 + 1] = (c1 * 2217 + d1 * 5352 + 14500) >> 12;
        coef[i * 4 + 3] = (d1 * 2217 - c1 * 5352 + 7500) >> 12;
    } else {
        coef[i * 4 + 1] = (c1 + d1 + 8192) >> 13;
        coef[i * 4 + 3] = (d1 - c1 + 8192) >> 13;
    }
}
}
