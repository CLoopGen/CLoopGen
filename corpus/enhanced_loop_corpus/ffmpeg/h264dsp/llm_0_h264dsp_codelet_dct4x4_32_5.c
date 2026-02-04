#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        const int idx = i * 2 + j;
        const int z0 = coef[idx * 4 + 0] + coef[idx * 4 + 3];
        const int z1 = coef[idx * 4 + 1] + coef[idx * 4 + 2];
        const int z2 = coef[idx * 4 + 0] - coef[idx * 4 + 3];
        const int z3 = coef[idx * 4 + 1] - coef[idx * 4 + 2];
        tmp[idx + 4 * 0] = z0 + z1;
        tmp[idx + 4 * 1] = 2 * z2 + z3;
        tmp[idx + 4 * 2] = z0 - z1;
        tmp[idx + 4 * 3] = z2 - 2 * z3;
    }
}
}
