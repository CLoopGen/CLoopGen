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
for (i = 0; i < 16; i += stride * 4) {
    const int base = i;
    const int z0 = tmp[base + 0*stride] + tmp[base + 3*stride];
    const int z1 = tmp[base + 1*stride] + tmp[base + 2*stride];
    const int z2 = tmp[base + 0*stride] - tmp[base + 3*stride];
    const int z3 = tmp[base + 1*stride] - tmp[base + 2*stride];
    coef[base + 0*stride] = z0 + z1;
    coef[base + 1*stride] = 2 * z2 + z3;
    coef[base + 2*stride] = z0 - z1;
    coef[base + 3*stride] = z2 - 2 * z3;
}
}
