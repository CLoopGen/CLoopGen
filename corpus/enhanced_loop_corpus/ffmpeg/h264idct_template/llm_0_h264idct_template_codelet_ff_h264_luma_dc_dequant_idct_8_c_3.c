#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int16_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        const int idx = 2 * i + j;
        const int z0 = input[4 * idx + 0] + input[4 * idx + 1];
        const int z1 = input[4 * idx + 0] - input[4 * idx + 1];
        const int z2 = input[4 * idx + 2] - input[4 * idx + 3];
        const int z3 = input[4 * idx + 2] + input[4 * idx + 3];
        temp[4 * idx + 0] = z0 + z3;
        temp[4 * idx + 1] = z0 - z3;
        temp[4 * idx + 2] = z1 - z2;
        temp[4 * idx + 3] = z1 + z2;
    }
}
}
