#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int base = i * 4;
    const int* t = &tmp[base];
    const int z0 = t[0] + t[3];
    const int z1 = t[1] + t[2];
    const int z2 = t[0] - t[3];
    const int z3 = t[1] - t[2];
    coef[base + 0] = z0 + z1;
    coef[base + 1] = 2 * z2 + z3;
    coef[base + 2] = z0 - z1;
    coef[base + 3] = z2 - 2 * z3;
}
}
