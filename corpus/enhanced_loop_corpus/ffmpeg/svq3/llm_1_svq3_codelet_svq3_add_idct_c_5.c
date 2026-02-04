#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            const int idx = j + 2 * i;
            const int z0 = 13 * (block[0 + 4 * idx] + block[2 + 4 * idx]);
            const int z1 = 13 * (block[0 + 4 * idx] - block[2 + 4 * idx]);
            const int z2 = 7 * block[1 + 4 * idx] - 17 * block[3 + 4 * idx];
            const int z3 = 17 * block[1 + 4 * idx] + 7 * block[3 + 4 * idx];
            block[0 + 4 * idx] = z0 + z3;
            block[1 + 4 * idx] = z1 + z2;
            block[2 + 4 * idx] = z1 - z2;
            block[3 + 4 * idx] = z0 - z3;
        }
    }
}
