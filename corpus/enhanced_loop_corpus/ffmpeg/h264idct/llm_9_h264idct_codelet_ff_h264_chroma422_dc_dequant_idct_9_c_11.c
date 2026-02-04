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
        int idx0 = stride * (2 * i + 0);
        int idx1 = stride * (2 * i + 1);
        temp[4 * i + 0] = block[idx0 + xStride * 0] + (unsigned int)block[idx0 + xStride * 1];
        temp[4 * i + 1] = block[idx0 + xStride * 0] - (unsigned int)block[idx0 + xStride * 1];
        temp[4 * i + 2] = block[idx1 + xStride * 0] + (unsigned int)block[idx1 + xStride * 1];
        temp[4 * i + 3] = block[idx1 + xStride * 0] - (unsigned int)block[idx1 + xStride * 1];
    }
}
