#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int stride;
extern  int xStride;
extern int i;
extern unsigned int temp[8];
extern int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            temp[2 * i + 0] = block[stride * i + xStride * 0] + (unsigned int)block[stride * i + xStride * 1];
            temp[2 * i + 1] = block[stride * i + xStride * 0] - (unsigned int)block[stride * i + xStride * 1];
        } else {
            temp[2 * i + 0] = block[stride * i + xStride * 0] - (unsigned int)block[stride * i + xStride * 1];
            temp[2 * i + 1] = block[stride * i + xStride * 0] + (unsigned int)block[stride * i + xStride * 1];
        }
    }
}
