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
    const int idx0 = 4 * 0 + i, idx1 = 4 * 1 + i, idx2 = 4 * 2 + i, idx3 = 4 * 3 + i;
    const int z0 = 39 * (temp[idx0] + temp[idx2]);
    const int z1 = 39 * (temp[idx0] - temp[idx2]);
    const int z2 = 21 * temp[idx1] - 51 * temp[idx3];
    const int z3 = 51 * temp[idx1] + 21 * temp[idx3];
    const int base = i * 4;
    block[base + 0] = (z0 + z3) >> 11;
    block[base + 1] = (z1 + z2) >> 11;
    block[base + 2] = (z1 - z2) >> 11;
    block[base + 3] = (z0 - z3) >> 11;
}
}
