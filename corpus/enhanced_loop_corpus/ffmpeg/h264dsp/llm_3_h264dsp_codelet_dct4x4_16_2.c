#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 1;
for (i = 0; i < 4; i++) {
    const int base = i * stride;
    const int c0 = coef[base], c1 = coef[base + 4*stride], c2 = coef[base + 8*stride], c3 = coef[base + 12*stride];
    const int z0 = c0 + c3;
    const int z1 = c1 + c2;
    const int z2 = c0 - c3;
    const int z3 = c1 - c2;
    tmp[i + 0] = z0 + z1;
    tmp[i + 4] = 2 * z2 + z3;
    tmp[i + 8] = z0 - z1;
    tmp[i + 12] = z2 - 2 * z3;
}
}
