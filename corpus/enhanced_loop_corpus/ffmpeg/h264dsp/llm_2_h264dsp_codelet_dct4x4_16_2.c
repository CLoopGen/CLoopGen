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
    const int idx0 = i * 4 + 0, idx1 = i * 4 + 1, idx2 = i * 4 + 2, idx3 = i * 4 + 3;
    const int z0 = coef[idx0] + coef[idx3];
    const int z1 = coef[idx1] + coef[idx2];
    const int z2 = coef[idx0] - coef[idx3];
    const int z3 = coef[idx1] - coef[idx2];
    tmp[i] = z0 + z1;
    tmp[i + 4] = 2 * z2 + z3;
    tmp[i + 8] = z0 - z1;
    tmp[i + 12] = z2 - 2 * z3;
}
}
