#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int i;
extern int temp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    for (int j = 0; j < 2; j++) {
        const int idx = i + j;
        if (idx >= 4) break;
        const int z0 = 13 * (input[4 * idx + 0] + input[4 * idx + 2]);
        const int z1 = 13 * (input[4 * idx + 0] - input[4 * idx + 2]);
        const int z2 = 7 * input[4 * idx + 1] - 17 * input[4 * idx + 3];
        const int z3 = 17 * input[4 * idx + 1] + 7 * input[4 * idx + 3];
        temp[4 * idx + 0] = z0 + z3;
        temp[4 * idx + 1] = z1 + z2;
        temp[4 * idx + 2] = z1 - z2;
        temp[4 * idx + 3] = z0 - z3;
    }
}
}
