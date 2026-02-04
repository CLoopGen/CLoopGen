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
    const int idx_base = i * 4;
    const int* c = &coef[idx_base];
    const int z0 = c[0] + c[3];
    const int z1 = c[1] + c[2];
    const int z2 = c[0] - c[3];
    const int z3 = c[1] - c[2];
    tmp[i + 0] = z0 + z1;
    tmp[i + 4] = 2 * z2 + z3;
    tmp[i + 8] = z0 - z1;
    tmp[i + 12] = z2 - 2 * z3;
}
}
