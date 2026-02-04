#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int temp[16];
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int t[4];
    for (i = 0; i < 4; i++) {
        const int z0 = 13 * (block[i + 4 * 0] + block[i + 4 * 2]);
        const int z1 = 13 * (block[i + 4 * 0] - block[i + 4 * 2]);
        const int z2 = 7 * block[i + 4 * 1] - 17 * block[i + 4 * 3];
        const int z3 = 17 * block[i + 4 * 1] + 7 * block[i + 4 * 3];
        t[0] = z0 + z3;
        t[1] = z1 + z2;
        t[2] = z1 - z2;
        t[3] = z0 - z3;
        temp[4 * i + 0] = t[0];
        temp[4 * i + 1] = t[1];
        temp[4 * i + 2] = t[2];
        temp[4 * i + 3] = t[3];
    }
}
