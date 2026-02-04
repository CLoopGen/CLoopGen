#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int a1 = coef[i * 4 + 0];
    int b1 = coef[i * 4 + 1];
    int c1 = coef[i * 4 + 2];
    int d1 = coef[i * 4 + 3];
    int e1;

    a1 += b1;
    d1 -= c1;

    if (i % 2 == 0) {
        e1 = (a1 - d1) >> 1;
    } else {
        e1 = (a1 + d1 + 1) >> 1;
    }

    b1 = e1 - b1;
    c1 = e1 - c1;
    a1 -= c1;
    d1 += b1;

    if (i != 2) {
        coef[i * 4 + 0] = a1 * 2;
        coef[i * 4 + 1] = c1 * 2;
        coef[i * 4 + 2] = d1 * 2;
        coef[i * 4 + 3] = b1 * 2;
    }
}
}
