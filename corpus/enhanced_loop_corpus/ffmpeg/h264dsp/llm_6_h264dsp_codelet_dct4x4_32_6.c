#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 4; j++) {
        const int idx = j * 4;
        const int t0 = tmp[idx + 0];
        const int t1 = tmp[idx + 1];
        const int t2 = tmp[idx + 2];
        const int t3 = tmp[idx + 3];

        const int z0 = t0 + t3;
        const int z1 = t1 + t2;
        const int z2 = t0 - t3;
        const int z3 = t1 - t2;

        coef[idx + 0] = z0 + z1;
        coef[idx + 1] = 2 * z2 + z3;
        coef[idx + 2] = z0 - z1;
        coef[idx + 3] = z2 - 2 * z3;
    }
}
