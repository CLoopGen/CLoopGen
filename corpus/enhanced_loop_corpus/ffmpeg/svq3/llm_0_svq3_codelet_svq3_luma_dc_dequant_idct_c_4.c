#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *output;
extern  unsigned int qmul;
extern int i;
extern int temp[16];
extern  uint8_t x_offset[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int offset = x_offset[i];
    const int z0 = 13 * (temp[4 * 0 + i] + temp[4 * 2 + i]);
    const int z1 = 13 * (temp[4 * 0 + i] - temp[4 * 2 + i]);
    const int z2 = 7 * temp[4 * 1 + i] - 17 * temp[4 * 3 + i];
    const int z3 = 17 * temp[4 * 1 + i] + 7 * temp[4 * 3 + i];
    output[16 * 0 + offset] = (int)((z0 + z3) * qmul + 524288) >> 20;
    output[16 * 2 + offset] = (int)((z1 + z2) * qmul + 524288) >> 20;
    output[16 * 8 + offset] = (int)((z1 - z2) * qmul + 524288) >> 20;
    output[16 * 10 + offset] = (int)((z0 - z3) * qmul + 524288) >> 20;

    // Additional inner loop unrolling simulation: process same logic with fixed indices
    for (int j = 1; j < 2; j++) {
        const int idx = j % 4;
        const int offset_inner = x_offset[idx];
        const int t0 = 13 * (temp[4 * 0 + idx] + temp[4 * 2 + idx]);
        const int t1 = 13 * (temp[4 * 0 + idx] - temp[4 * 2 + idx]);
        const int t2 = 7 * temp[4 * 1 + idx] - 17 * temp[4 * 3 + idx];
        const int t3 = 17 * temp[4 * 1 + idx] + 7 * temp[4 * 3 + idx];
        output[16 * 1 + offset_inner] = (int)((t0 + t3) * qmul + 524288) >> 20;
        output[16 * 3 + offset_inner] = (int)((t1 + t2) * qmul + 524288) >> 20;
        output[16 * 9 + offset_inner] = (int)((t1 - t2) * qmul + 524288) >> 20;
        output[16 * 11 + offset_inner] = (int)((t0 - t3) * qmul + 524288) >> 20;
    }
}
}
