#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_z0 = 0;
for (i = 0; i < 4; i++) {
    const int offset = i * 4;
    const int z0 = coef[offset + 0] + coef[offset + 3] + prev_z0;
    const int z1 = coef[offset + 1] + coef[offset + 2];
    const int z2 = coef[offset + 0] - coef[offset + 3];
    const int z3 = coef[offset + 1] - coef[offset + 2];
    tmp[i + 4 * 0] = z0 + z1;
    tmp[i + 4 * 1] = 2 * z2 + z3;
    tmp[i + 4 * 2] = z0 - z1;
    tmp[i + 4 * 3] = z2 - 2 * z3;
    prev_z0 = z0 & 0xFFFF;
}
}
