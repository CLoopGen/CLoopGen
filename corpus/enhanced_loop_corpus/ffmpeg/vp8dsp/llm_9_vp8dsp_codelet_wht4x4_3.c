#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int a1 = coef[0 * 4 + i];
    int b1 = coef[1 * 4 + i];
    int c1 = coef[2 * 4 + i];
    int d1 = coef[3 * 4 + i];
    int e1;
    a1 += b1;
    d1 -= c1;
    e1 = (a1 - d1) >> 1;
    b1 = e1 - b1;
    c1 = e1 - c1;
    a1 -= c1;
    d1 += b1;
    // Additional computational steps to increase arithmetic intensity
    a1 = (a1 + 1) * 3;
    b1 = (b1 - 2) * 2;
    c1 = (c1 + 3) / 2;
    d1 = (d1 - 1) * 4;
    coef[0 * 4 + i] = a1;
    coef[1 * 4 + i] = c1;
    coef[2 * 4 + i] = d1;
    coef[3 * 4 + i] = b1;
}
}
