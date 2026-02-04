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
        for (int k = 0; k < 2; k++) {
            const int base = (i * 2 + k) * 4;
            const int z0 = tmp[base + 0] + tmp[base + 3];
            const int z1 = tmp[base + 1] + tmp[base + 2];
            const int z2 = tmp[base + 0] - tmp[base + 3];
            const int z3 = tmp[base + 1] - tmp[base + 2];
            coef[base + 0] = z0 + z1;
            coef[base + 1] = 2 * z2 + z3;
            coef[base + 2] = z0 - z1;
            coef[base + 3] = z2 - 2 * z3;
        }
    }
}
