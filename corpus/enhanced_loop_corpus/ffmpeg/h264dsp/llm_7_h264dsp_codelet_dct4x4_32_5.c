#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_offset = 0;
for (i = 0; i < 4; i++) {
    const int idx0 = i * 4 + 0;
    const int idx1 = i * 4 + 1;
    const int idx2 = i * 4 + 2;
    const int idx3 = i * 4 + 3;
    const int z0 = coef[idx0] + coef[idx3];
    const int z1 = coef[idx1] + coef[idx2];
    const int z2 = coef[idx0] - coef[idx3];
    const int z3 = coef[idx1] - coef[idx2];
    const int base = i;
    tmp[base + 4 * 0] = z0 + z1;
    tmp[base + 4 * 1] = 2 * z2 + z3;
    tmp[base + 4 * 2] = z0 - z1;
    tmp[base + 4 * 3] = z2 - 2 * z3;
    prev_offset = base;
}
}
