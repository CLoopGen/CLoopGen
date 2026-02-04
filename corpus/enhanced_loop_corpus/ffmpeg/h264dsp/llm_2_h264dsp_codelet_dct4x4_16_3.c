#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int idx = i * 4;
    const int z0 = tmp[idx + 0] + tmp[idx + 3];
    const int z1 = tmp[idx + 1] + tmp[idx + 2];
    const int z2 = tmp[idx + 0] - tmp[idx + 3];
    const int z3 = tmp[idx + 1] - tmp[idx + 2];
    coef[idx + 0] = z0 + z1;
    coef[idx + 1] = 2 * z2 + z3;
    coef[idx + 2] = z0 - z1;
    coef[idx + 3] = z2 - 2 * z3;
}
}
