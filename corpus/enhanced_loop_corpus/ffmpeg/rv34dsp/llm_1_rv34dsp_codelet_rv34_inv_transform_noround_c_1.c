#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int temp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 1; i++) {
    for (int j = 0; j < 4; j++) {
        const int z0 = 39 * (temp[4 * 0 + j] + temp[4 * 2 + j]);
        const int z1 = 39 * (temp[4 * 0 + j] - temp[4 * 2 + j]);
        const int z2 = 21 * temp[4 * 1 + j] - 51 * temp[4 * 3 + j];
        const int z3 = 51 * temp[4 * 1 + j] + 21 * temp[4 * 3 + j];
        block[j * 4 + 0] = (z0 + z3) >> 11;
        block[j * 4 + 1] = (z1 + z2) >> 11;
        block[j * 4 + 2] = (z1 - z2) >> 11;
        block[j * 4 + 3] = (z0 - z3) >> 11;
    }
}
}
