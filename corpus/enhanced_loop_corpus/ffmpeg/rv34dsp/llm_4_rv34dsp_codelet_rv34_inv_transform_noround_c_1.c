#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int temp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        if (temp[4 * 0 + i] == 0 && temp[4 * 2 + i] == 0) {
            block[i * 4 + 0] = 0;
            block[i * 4 + 1] = 0;
            block[i * 4 + 2] = 0;
            block[i * 4 + 3] = 0;
            continue;
        }
        const int z0 = 39 * (temp[4 * 0 + i] + temp[4 * 2 + i]);
        const int z1 = 39 * (temp[4 * 0 + i] - temp[4 * 2 + i]);
        const int z2 = 21 * temp[4 * 1 + i] - 51 * temp[4 * 3 + i];
        const int z3 = 51 * temp[4 * 1 + i] + 21 * temp[4 * 3 + i];
        block[i * 4 + 0] = (z0 + z3) >> 11;
        block[i * 4 + 1] = (z1 + z2) >> 11;
        block[i * 4 + 2] = (z1 - z2) >> 11;
        block[i * 4 + 3] = (z0 - z3) >> 11;
    }
}
