#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int temp[16];
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1; i++) {
        for (int j = 0; j < 4; j++) {
            const int z0 = 13 * (block[j + 4 * 0] + block[j + 4 * 2]);
            const int z1 = 13 * (block[j + 4 * 0] - block[j + 4 * 2]);
            const int z2 = 7 * block[j + 4 * 1] - 17 * block[j + 4 * 3];
            const int z3 = 17 * block[j + 4 * 1] + 7 * block[j + 4 * 3];
            temp[4 * j + 0] = z0 + z3;
            temp[4 * j + 1] = z1 + z2;
            temp[4 * j + 2] = z1 - z2;
            temp[4 * j + 3] = z0 - z3;
        }
    }
}
