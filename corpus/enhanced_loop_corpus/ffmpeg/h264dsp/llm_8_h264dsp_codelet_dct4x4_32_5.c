#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int idx = i % 4;
    const int c0 = coef[idx * 4 + 0];
    const int c1 = coef[idx * 4 + 1];
    const int c2 = coef[idx * 4 + 2];
    const int c3 = coef[idx * 4 + 3];
    const int z0 = c0 + c3;
    const int z1 = c1 + c2;
    const int z2 = c0 - c3;
    const int z3 = c1 - c2;
    tmp[i] = z0 + z1;
    tmp[i + 8] = 2 * z2 + z3;
    tmp[i + 16] = z0 - z1;
    tmp[i + 24] = z2 - 2 * z3;
}
}
