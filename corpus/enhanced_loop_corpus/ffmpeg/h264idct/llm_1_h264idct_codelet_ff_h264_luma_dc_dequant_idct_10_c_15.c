#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    const int z0_0 = input[4 * i + 0] + input[4 * i + 1];
    const int z1_0 = input[4 * i + 0] - input[4 * i + 1];
    const int z2_0 = input[4 * i + 2] - input[4 * i + 3];
    const int z3_0 = input[4 * i + 2] + input[4 * i + 3];
    temp[4 * i + 0] = z0_0 + z3_0;
    temp[4 * i + 1] = z0_0 - z3_0;
    temp[4 * i + 2] = z1_0 - z2_0;
    temp[4 * i + 3] = z1_0 + z2_0;

    const int z0_1 = input[4 * (i + 2) + 0] + input[4 * (i + 2) + 1];
    const int z1_1 = input[4 * (i + 2) + 0] - input[4 * (i + 2) + 1];
    const int z2_1 = input[4 * (i + 2) + 2] - input[4 * (i + 2) + 3];
    const int z3_1 = input[4 * (i + 2) + 2] + input[4 * (i + 2) + 3];
    temp[4 * (i + 2) + 0] = z0_1 + z3_1;
    temp[4 * (i + 2) + 1] = z0_1 - z3_1;
    temp[4 * (i + 2) + 2] = z1_1 - z2_1;
    temp[4 * (i + 2) + 3] = z1_1 + z2_1;
}
}
