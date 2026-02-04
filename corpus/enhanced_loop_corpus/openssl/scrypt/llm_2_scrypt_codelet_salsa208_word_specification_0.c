#include <stdio.h>

#include <inttypes.h>

extern int i;
extern uint32_t x[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize array accesses to follow a more sequential memory layout by processing elements in contiguous groups.
    // This improves cache locality by accessing nearby indices consecutively.

    for (i = 8; i > 0; i -= 2) {
        // Column round - consecutive access: process columns as if transposed
        uint32_t temp[4];

        // Process column 0: indices 0, 4, 8, 12
        temp[0] = x[0]; temp[1] = x[4]; temp[2] = x[8]; temp[3] = x[12];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[0] = temp[0]; x[4] = temp[1]; x[8] = temp[2]; x[12] = temp[3];

        // Process column 1: indices 1, 5, 9, 13
        temp[0] = x[1]; temp[1] = x[5]; temp[2] = x[9]; temp[3] = x[13];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[1] = temp[0]; x[5] = temp[1]; x[9] = temp[2]; x[13] = temp[3];

        // Process column 2: indices 2, 6, 10, 14
        temp[0] = x[2]; temp[1] = x[6]; temp[2] = x[10]; temp[3] = x[14];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[2] = temp[0]; x[6] = temp[1]; x[10] = temp[2]; x[14] = temp[3];

        // Process column 3: indices 3, 7, 11, 15
        temp[0] = x[3]; temp[1] = x[7]; temp[2] = x[11]; temp[3] = x[15];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[3] = temp[0]; x[7] = temp[1]; x[11] = temp[2]; x[15] = temp[3];

        // Diagonal round - now using strided access but grouped for coherence
        temp[0] = x[0]; temp[1] = x[1]; temp[2] = x[2]; temp[3] = x[3];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[0] = temp[0]; x[1] = temp[1]; x[2] = temp[2]; x[3] = temp[3];

        temp[0] = x[5]; temp[1] = x[6]; temp[2] = x[7]; temp[3] = x[4];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[5] = temp[0]; x[6] = temp[1]; x[7] = temp[2]; x[4] = temp[3];

        temp[0] = x[10]; temp[1] = x[11]; temp[2] = x[8]; temp[3] = x[9];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[10] = temp[0]; x[11] = temp[1]; x[8] = temp[2]; x[9] = temp[3];

        temp[0] = x[15]; temp[1] = x[12]; temp[2] = x[13]; temp[3] = x[14];
        temp[1] ^= (((temp[0] + temp[3]) << 7) | ((temp[0] + temp[3]) >> 25));
        temp[2] ^= (((temp[1] + temp[0]) << 9) | ((temp[1] + temp[0]) >> 23));
        temp[3] ^= (((temp[2] + temp[1]) << 13) | ((temp[2] + temp[1]) >> 19));
        temp[0] ^= (((temp[3] + temp[2]) << 18) | ((temp[3] + temp[2]) >> 14));
        x[15] = temp[0]; x[12] = temp[1]; x[13] = temp[2]; x[14] = temp[3];
    }
}
