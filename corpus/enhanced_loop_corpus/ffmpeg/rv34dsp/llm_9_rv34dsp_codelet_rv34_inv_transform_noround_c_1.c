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
        const int k = i * 2 + j;
        const int t0 = temp[4 * 0 + k];
        const int t1 = temp[4 * 1 + k];
        const int t2 = temp[4 * 2 + k];
        const int t3 = temp[4 * 3 + k];
        const int z0 = 39 * (t0 + t2);
        const int z1 = 39 * (t0 - t2);
        const int z2 = 21 * t1 - 51 * t3;
        const int z3 = 51 * t1 + 21 * t3;
        block[k * 4 + 0] = (z0 + z3) >> 11;
        block[k * 4 + 1] = (z1 + z2) >> 11;
        block[k * 4 + 2] = (z1 - z2) >> 11;
        block[k * 4 + 3] = (z0 - z3) >> 11;
    }
}
}
