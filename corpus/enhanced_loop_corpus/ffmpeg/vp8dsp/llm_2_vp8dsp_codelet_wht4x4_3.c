#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int a1 = coef[i];
    int b1 = coef[4 + i];
    int c1 = coef[8 + i];
    int d1 = coef[12 + i];
    int e1;
    a1 += b1;
    d1 -= c1;
    e1 = (a1 - d1) >> 1;
    b1 = e1 - b1;
    c1 = e1 - c1;
    a1 -= c1;
    d1 += b1;
    coef[i] = a1;
    coef[4 + i] = c1;
    coef[8 + i] = d1;
    coef[12 + i] = b1;
}
}
