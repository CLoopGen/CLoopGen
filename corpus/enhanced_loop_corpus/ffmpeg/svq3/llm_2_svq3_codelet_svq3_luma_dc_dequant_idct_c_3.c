#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int i;
extern int temp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing input in blocks of 4 consecutive elements,
    // we now access them with a stride of 1 across the entire array,
    // processing one column at a time as if transposed.
    for (i = 0; i < 4; i++) {
        const int idx0 = i;
        const int idx1 = i + 4;
        const int idx2 = i + 8;
        const int idx3 = i + 12;
        const int z0 = 13 * (input[idx0] + input[idx2]);
        const int z1 = 13 * (input[idx0] - input[idx2]);
        const int z2 = 7 * input[idx1] - 17 * input[idx3];
        const int z3 = 17 * input[idx1] + 7 * input[idx3];
        temp[i + 0]      = z0 + z3;
        temp[i + 4]      = z1 + z2;
        temp[i + 8]      = z1 - z2;
        temp[i + 12]     = z0 - z3;
    }
}
