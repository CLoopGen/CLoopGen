#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int temp[16];
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1) {
    const int offset = 4 * i;
    const int b0 = block[offset + 0], b1 = block[offset + 1];
    const int b2 = block[offset + 2], b3 = block[offset + 3];
    const int z0 = 13 * (b0 + b2);
    const int z1 = 13 * (b0 - b2);
    const int z2 = 7 * b1 - 17 * b3;
    const int z3 = 17 * b1 + 7 * b3;
    temp[offset + 0] = z0 + z3;
    temp[offset + 1] = z1 + z2;
    temp[offset + 2] = z1 - z2;
    temp[offset + 3] = z0 - z3;

    // Unrolled second iteration with direct indexing
    const int off2 = 4 * (i + 1);
    const int b4 = block[off2 + 0], b5 = block[off2 + 1];
    const int b6 = block[off2 + 2], b7 = block[off2 + 3];
    const int z4 = 13 * (b4 + b6);
    const int z5 = 13 * (b4 - b6);
    const int z6 = 7 * b5 - 17 * b7;
    const int z7 = 17 * b5 + 7 * b7;
    temp[off2 + 0] = z4 + z7;
    temp[off2 + 1] = z5 + z6;
    temp[off2 + 2] = z5 - z6;
    temp[off2 + 3] = z4 - z7;
}
}
