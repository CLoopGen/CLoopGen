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
        const int t0 = temp[4 * 0 + i];
        const int t1 = temp[4 * 1 + i];
        const int t2 = temp[4 * 2 + i];
        const int t3 = temp[4 * 3 + i];

        if (t0 > t2) {
            const int z0 = 39 * (t0 + t2);
            const int z1 = 39 * (t0 - t2);
            const int z2 = 21 * t1 - 51 * t3;
            const int z3 = 51 * t1 + 21 * t3;
            block[i * 4 + 0] = (z0 + z3) >> 11;
            block[i * 4 + 1] = (z1 + z2) >> 11;
            block[i * 4 + 2] = (z1 - z2) >> 11;
            block[i * 4 + 3] = (z0 - z3) >> 11;
        } else {
            const int z0 = 39 * (t0 + t2);
            const int z3 = 51 * t1 + 21 * t3;
            block[i * 4 + 0] = (z0 + z3) >> 11;
            block[i * 4 + 3] = (z0 - z3) >> 11;
            block[i * 4 + 1] = 0;
            block[i * 4 + 2] = 0;
        }
    }
}
