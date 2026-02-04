#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    const int z0_0 = coef[i * 4 + 0] + coef[i * 4 + 3];
    const int z1_0 = coef[i * 4 + 1] + coef[i * 4 + 2];
    const int z2_0 = coef[i * 4 + 0] - coef[i * 4 + 3];
    const int z3_0 = coef[i * 4 + 1] - coef[i * 4 + 2];
    tmp[i + 4 * 0] = z0_0 + z1_0;
    tmp[i + 4 * 1] = 2 * z2_0 + z3_0;
    tmp[i + 4 * 2] = z0_0 - z1_0;
    tmp[i + 4 * 3] = z2_0 - 2 * z3_0;

    if (i + 1 < 4) {
        const int z0_1 = coef[(i+1) * 4 + 0] + coef[(i+1) * 4 + 3];
        const int z1_1 = coef[(i+1) * 4 + 1] + coef[(i+1) * 4 + 2];
        const int z2_1 = coef[(i+1) * 4 + 0] - coef[(i+1) * 4 + 3];
        const int z3_1 = coef[(i+1) * 4 + 1] - coef[(i+1) * 4 + 2];
        tmp[(i+1) + 4 * 0] = z0_1 + z1_1;
        tmp[(i+1) + 4 * 1] = 2 * z2_1 + z3_1;
        tmp[(i+1) + 4 * 2] = z0_1 - z1_1;
        tmp[(i+1) + 4 * 3] = z2_1 - 2 * z3_1;
    }
}
}
