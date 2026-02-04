#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int temp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        const int idx = 2 * i + j;
        const int z0 = 39 * (temp[4 * 0 + idx] + temp[4 * 2 + idx]);
        const int z1 = 39 * (temp[4 * 0 + idx] - temp[4 * 2 + idx]);
        const int z2 = 21 * temp[4 * 1 + idx] - 51 * temp[4 * 3 + idx];
        const int z3 = 51 * temp[4 * 1 + idx] + 21 * temp[4 * 3 + idx];
        block[idx * 4 + 0] = (z0 + z3) >> 11;
        block[idx * 4 + 1] = (z1 + z2) >> 11;
        block[idx * 4 + 2] = (z1 - z2) >> 11;
        block[idx * 4 + 3] = (z0 - z3) >> 11;
    }
}
}
