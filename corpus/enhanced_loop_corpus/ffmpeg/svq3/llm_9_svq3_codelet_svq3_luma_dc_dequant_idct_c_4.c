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
for (i = 0; i < 8; i += 2) {
    const int offset0 = x_offset[i % 4];
    const int offset1 = x_offset[(i + 1) % 4];
    const int t0_0 = temp[4 * 0 + i % 4];
    const int t1_0 = temp[4 * 1 + i % 4];
    const int t2_0 = temp[4 * 2 + i % 4];
    const int t3_0 = temp[4 * 3 + i % 4];
    const int t0_1 = temp[4 * 0 + (i + 1) % 4];
    const int t1_1 = temp[4 * 1 + (i + 1) % 4];
    const int t2_1 = temp[4 * 2 + (i + 1) % 4];
    const int t3_1 = temp[4 * 3 + (i + 1) % 4];

    const int z0_0 = 13 * (t0_0 + t2_0);
    const int z1_0 = 13 * (t0_0 - t2_0);
    const int z2_0 = 7 * t1_0 - 17 * t3_0;
    const int z3_0 = 17 * t1_0 + 7 * t3_0;

    const int z0_1 = 13 * (t0_1 + t2_1);
    const int z1_1 = 13 * (t0_1 - t2_1);
    const int z2_1 = 7 * t1_1 - 17 * t3_1;
    const int z3_1 = 17 * t1_1 + 7 * t3_1;

    output[16 * 0 + offset0] = (int)((z0_0 + z3_0) * qmul + 524288) >> 20;
    output[16 * 2 + offset0] = (int)((z1_0 + z2_0) * qmul + 524288) >> 20;
    output[16 * 8 + offset0] = (int)((z1_0 - z2_0) * qmul + 524288) >> 20;
    output[16 * 10 + offset0] = (int)((z0_0 - z3_0) * qmul + 524288) >> 20;

    output[16 * 0 + offset1] = (int)((z0_1 + z3_1) * qmul + 524288) >> 20;
    output[16 * 2 + offset1] = (int)((z1_1 + z2_1) * qmul + 524288) >> 20;
    output[16 * 8 + offset1] = (int)((z1_1 - z2_1) * qmul + 524288) >> 20;
    output[16 * 10 + offset1] = (int)((z0_1 - z3_1) * qmul + 524288) >> 20;
}
}
