#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[4] = {3, 2, 1, 0}; // Reverse access pattern
for (i = 0; i < 4; i++) {
    int idx = indices[i]; // Indirect indexing
    int a1 = coef[0 * 4 + idx];
    int b1 = coef[1 * 4 + idx];
    int c1 = coef[2 * 4 + idx];
    int d1 = coef[3 * 4 + idx];
    int e1;
    a1 += b1;
    d1 -= c1;
    e1 = (a1 - d1) >> 1;
    b1 = e1 - b1;
    c1 = e1 - c1;
    a1 -= c1;
    d1 += b1;
    coef[0 * 4 + idx] = a1;
    coef[1 * 4 + idx] = c1;
    coef[2 * 4 + idx] = d1;
    coef[3 * 4 + idx] = b1;
}
}
