#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i += 2) {
    const int z0_0 = 13 * (block[0 + 4 * i] + block[2 + 4 * i]);
    const int z1_0 = 13 * (block[0 + 4 * i] - block[2 + 4 * i]);
    const int z2_0 = 7 * block[1 + 4 * i] - 17 * block[3 + 4 * i];
    const int z3_0 = 17 * block[1 + 4 * i] + 7 * block[3 + 4 * i];
    block[0 + 4 * i] = z0_0 + z3_0;
    block[1 + 4 * i] = z1_0 + z2_0;
    block[2 + 4 * i] = z1_0 - z2_0;
    block[3 + 4 * i] = z0_0 - z3_0;

    if (i + 1 < 4) {
        const int z0_1 = 13 * (block[0 + 4 * (i + 1)] + block[2 + 4 * (i + 1)]);
        const int z1_1 = 13 * (block[0 + 4 * (i + 1)] - block[2 + 4 * (i + 1)]);
        const int z2_1 = 7 * block[1 + 4 * (i + 1)] - 17 * block[3 + 4 * (i + 1)];
        const int z3_1 = 17 * block[1 + 4 * (i + 1)] + 7 * block[3 + 4 * (i + 1)];
        block[0 + 4 * (i + 1)] = z0_1 + z3_1;
        block[1 + 4 * (i + 1)] = z1_1 + z2_1;
        block[2 + 4 * (i + 1)] = z1_1 - z2_1;
        block[3 + 4 * (i + 1)] = z0_1 - z3_1;
    }
}
}
