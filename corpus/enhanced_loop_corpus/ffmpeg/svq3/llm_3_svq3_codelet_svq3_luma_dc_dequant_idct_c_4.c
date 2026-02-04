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
for (i = 0; i < 4; ++i) {
    const int offset = x_offset[i];
    const int base_idx[4] = {0, 4, 8, 12};
    const int t0 = temp[base_idx[0] + i];
    const int t1 = temp[base_idx[1] + i];
    const int t2 = temp[base_idx[2] + i];
    const int t3 = temp[base_idx[3] + i];
    const int z0 = 13 * (t0 + t2);
    const int z1 = 13 * (t0 - t2);
    const int z2 = 7 * t1 - 17 * t3;
    const int z3 = 17 * t1 + 7 * t3;
    const int out_offsets[4] = {0, 32, 128, 160};
    output[out_offsets[0] + offset] = (int)((z0 + z3) * qmul + 524288) >> 20;
    output[out_offsets[1] + offset] = (int)((z1 + z2) * qmul + 524288) >> 20;
    output[out_offsets[2] + offset] = (int)((z1 - z2) * qmul + 524288) >> 20;
    output[out_offsets[3] + offset] = (int)((z0 - z3) * qmul + 524288) >> 20;
}
}
