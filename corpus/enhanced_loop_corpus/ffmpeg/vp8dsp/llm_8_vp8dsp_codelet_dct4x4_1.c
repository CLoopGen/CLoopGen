#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int a1 = (coef[i * 4 + 0] + coef[i * 4 + 3]) * 6;
    const int b1 = (coef[i * 4 + 1] + coef[i * 4 + 2]) * 6;
    const int c1 = (coef[i * 4 + 1] - coef[i * 4 + 2]) * 6;
    const int d1 = (coef[i * 4 + 0] - coef[i * 4 + 3]) * 6;
    coef[i * 4 + 0] = a1 + b1;
    coef[i * 4 + 1] = (c1 * 1800 + d1 * 4400 + 12000) >> 11;
    coef[i * 4 + 2] = a1 - b1;
    coef[i * 4 + 3] = (d1 * 1800 - c1 * 4400 + 6000) >> 11;
}
}
