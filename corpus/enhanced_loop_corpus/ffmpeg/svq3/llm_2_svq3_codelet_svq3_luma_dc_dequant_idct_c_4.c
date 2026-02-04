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
    const int idx0 = 4 * 0 + i;
    const int idx1 = 4 * 1 + i;
    const int idx2 = 4 * 2 + i;
    const int idx3 = 4 * 3 + i;
    const int z0 = 13 * (temp[idx0] + temp[idx2]);
    const int z1 = 13 * (temp[idx0] - temp[idx2]);
    const int z2 = 7 * temp[idx1] - 17 * temp[idx3];
    const int z3 = 17 * temp[idx1] + 7 * temp[idx3];
    const int o0 = 16 * 0 + offset;
    const int o2 = 16 * 2 + offset;
    const int o8 = 16 * 8 + offset;
    const int o10 = 16 * 10 + offset;
    output[o0] = (int)((z0 + z3) * qmul + 524288) >> 20;
    output[o2] = (int)((z1 + z2) * qmul + 524288) >> 20;
    output[o8] = (int)((z1 - z2) * qmul + 524288) >> 20;
    output[o10] = (int)((z0 - z3) * qmul + 524288) >> 20;
}
}
