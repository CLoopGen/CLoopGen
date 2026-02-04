#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int temp[16];
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        const int val0 = block[i + 4 * 0];
        const int val1 = block[i + 4 * 1];
        const int val2 = block[i + 4 * 2];
        const int val3 = block[i + 4 * 3];
        const int z0 = 13 * (val0 + val2);
        const int z1 = 13 * (val0 - val2);
        const int z2 = 7 * val1 - 17 * val3;
        const int z3 = 17 * val1 + 7 * val3;
        temp[4 * i + 3] = z0 - z3;
        temp[4 * i + 2] = z1 - z2;
        temp[4 * i + 1] = z1 + z2;
        temp[4 * i + 0] = z0 + z3;
    }
}
