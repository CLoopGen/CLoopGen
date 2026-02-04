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
    int offset = stride * (2 * i);
    temp[2 * (2 * i) + 0] = block[offset + xStride * 0] + (unsigned int)block[offset + xStride * 1];
    temp[2 * (2 * i) + 1] = block[offset + xStride * 0] - (unsigned int)block[offset + xStride * 1];
    if (2 * i + 1 < 4) {
        offset = stride * (2 * i + 1);
        temp[2 * (2 * i + 1) + 0] = block[offset + xStride * 0] + (unsigned int)block[offset + xStride * 1];
        temp[2 * (2 * i + 1) + 1] = block[offset + xStride * 0] - (unsigned int)block[offset + xStride * 1];
    }
}
}
