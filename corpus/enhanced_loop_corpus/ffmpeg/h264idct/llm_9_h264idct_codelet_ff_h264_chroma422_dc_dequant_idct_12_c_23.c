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
for (i = 0; i < 4; i += 2) {
    uint32_t sum0 = block[stride * i + xStride * 0] + (unsigned int)block[stride * i + xStride * 1];
    uint32_t diff0 = block[stride * i + xStride * 0] - (unsigned int)block[stride * i + xStride * 1];
    uint32_t sum1 = block[stride * (i+1) + xStride * 0] + (unsigned int)block[stride * (i+1) + xStride * 1];
    uint32_t diff1 = block[stride * (i+1) + xStride * 0] - (unsigned int)block[stride * (i+1) + xStride * 1];

    temp[2 * i + 0] = sum0;
    temp[2 * i + 1] = diff0;
    temp[2 * (i+1) + 0] = sum1;
    temp[2 * (i+1) + 1] = diff1;
}
}
