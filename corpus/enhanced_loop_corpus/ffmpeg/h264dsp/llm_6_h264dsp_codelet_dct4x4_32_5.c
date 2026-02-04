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
    const int t0 = coef[i * 4 + 0];
    const int t1 = coef[i * 4 + 1];
    const int t2 = coef[i * 4 + 2];
    const int t3 = coef[i * 4 + 3];
    const int z0 = t0 + t3;
    const int z1 = t1 + t2;
    const int z2 = t0 - t3;
    const int z3 = t1 - t2;
    tmp[i + 4 * 0] = z0 + z1;
    tmp[i + 4 * 1] = 2 * z2 + z3;
    tmp[i + 4 * 2] = z0 - z1;
    tmp[i + 4 * 3] = z2 - 2 * z3;
}
}
