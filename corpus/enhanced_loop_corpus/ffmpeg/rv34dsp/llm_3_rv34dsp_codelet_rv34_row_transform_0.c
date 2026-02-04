#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int temp[16];
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed block indexing (strided read pattern)
    for (i = 0; i < 4; i++) {
        // Access block with a negative stride: process from last to first row for each column
        const int z0 = 13 * (block[i + 4 * 3] + block[i + 4 * 1]);  // swapped 0 and 2 -> now 3 and 1
        const int z1 = 13 * (block[i + 4 * 3] - block[i + 4 * 1]);
        const int z2 = 7 * block[i + 4 * 2] - 17 * block[i + 4 * 0];  // swapped 1 and 3 -> now 2 and 0
        const int z3 = 17 * block[i + 4 * 2] + 7 * block[i + 4 * 0];

        // Store results in normal order
        temp[4 * i + 0] = z0 + z3;
        temp[4 * i + 1] = z1 + z2;
        temp[4 * i + 2] = z1 - z2;
        temp[4 * i + 3] = z0 - z3;
    }
}
