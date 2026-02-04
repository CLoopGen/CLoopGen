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
        int local_coef[4];

        const int z0 = tmp[base + 0] + tmp[base + 3];
        const int z1 = tmp[base + 1] + tmp[base + 2];
        const int z2 = tmp[base + 0] - tmp[base + 3];
        const int z3 = tmp[base + 1] - tmp[base + 2];

        local_coef[0] = z0 + z1;
        local_coef[1] = 2 * z2 + z3;
        local_coef[2] = z0 - z1;
        local_coef[3] = z2 - 2 * z3;

        // Introduce WAW and WAR-like dependencies by sequential write with artificial ordering
        coef[base + 0] = local_coef[0];
        coef[base + 1] = local_coef[1];
        coef[base + 2] = local_coef[2];
        coef[base + 3] = local_coef[3];
    }
}
