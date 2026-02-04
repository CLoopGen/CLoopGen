#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int temp[16];
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computations to access block elements in increasing order
    for (i = 0; i < 4; i++) {
        const int idx0 = i + 4 * 0;
        const int idx1 = i + 4 * 1;
        const int idx2 = i + 4 * 2;
        const int idx3 = i + 4 * 3;

        // Reorder computation to access block consecutively: idx0, idx1, idx2, idx3
        const int b0 = block[idx0];
        const int b1 = block[idx1];
        const int b2 = block[idx2];
        const int b3 = block[idx3];

        const int z0 = 13 * (b0 + b2);
        const int z1 = 13 * (b0 - b2);
        const int z2 = 7 * b1 - 17 * b3;
        const int z3 = 17 * b1 + 7 * b3;

        temp[4 * i + 0] = z0 + z3;
        temp[4 * i + 1] = z1 + z2;
        temp[4 * i + 2] = z1 - z2;
        temp[4 * i + 3] = z0 - z3;
    }
}
