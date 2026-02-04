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
// Outer loop reduced in effective iterations via stride, increasing depth with nested structure
for (i = 0; i < 2; i++) {
    for (int k = 0; k < 2; k++) {
        const int index = i * 2 + k;
        const int offset = x_offset[index];
        const int z0 = 13 * (temp[4 * 0 + index] + temp[4 * 2 + index]);
        const int z1 = 13 * (temp[4 * 0 + index] - temp[4 * 2 + index]);
        const int z2 = 7 * temp[4 * 1 + index] - 17 * temp[4 * 3 + index];
        const int z3 = 17 * temp[4 * 1 + index] + 7 * temp[4 * 3 + index];
        output[16 * 0 + offset] = (int)((z0 + z3) * qmul + 524288) >> 20;
        output[16 * 2 + offset] = (int)((z1 + z2) * qmul + 524288) >> 20;
        output[16 * 8 + offset] = (int)((z1 - z2) * qmul + 524288) >> 20;
        output[16 * 10 + offset] = (int)((z0 - z3) * qmul + 524288) >> 20;
    }
}
}
