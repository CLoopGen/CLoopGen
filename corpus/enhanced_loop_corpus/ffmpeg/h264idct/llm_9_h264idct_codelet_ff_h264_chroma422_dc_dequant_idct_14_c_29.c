#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int stride;
extern  int xStride;
extern int i;
extern unsigned int temp[8];
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int base_idx1 = stride * (2 * i) + xStride * 0;
    int base_idx2 = stride * (2 * i + 1) + xStride * 0;
    temp[4 * i + 0] = block[base_idx1] + (unsigned int)block[base_idx1 + xStride];
    temp[4 * i + 1] = block[base_idx1] - (unsigned int)block[base_idx1 + xStride];
    temp[4 * i + 2] = block[base_idx2] + (unsigned int)block[base_idx2 + xStride];
    temp[4 * i + 3] = block[base_idx2] - (unsigned int)block[base_idx2 + xStride];
}
}
