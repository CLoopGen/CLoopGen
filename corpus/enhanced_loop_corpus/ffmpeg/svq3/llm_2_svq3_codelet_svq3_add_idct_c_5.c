#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize data access to process elements in consecutive order
    // assuming block is now arranged as [0,1,2,3, 4,5,6,7, ...] instead of column-major
    int temp[4];
    for (i = 0; i < 4; i++) {
        const int idx = i * 4;
        temp[0] = block[idx + 0];
        temp[1] = block[idx + 1];
        temp[2] = block[idx + 2];
        temp[3] = block[idx + 3];

        const int z0 = 13 * (temp[0] + temp[2]);
        const int z1 = 13 * (temp[0] - temp[2]);
        const int z2 = 7 * temp[1] - 17 * temp[3];
        const int z3 = 17 * temp[1] + 7 * temp[3];

        block[idx + 0] = z0 + z3;
        block[idx + 1] = z1 + z2;
        block[idx + 2] = z1 - z2;
        block[idx + 3] = z0 - z3;
    }
}
