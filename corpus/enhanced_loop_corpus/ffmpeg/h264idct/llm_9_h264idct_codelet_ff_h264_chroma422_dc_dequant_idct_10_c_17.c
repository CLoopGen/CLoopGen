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
    int base1 = stride * (2 * i) + xStride * 0;
    int base2 = stride * (2 * i + 1) + xStride * 0;
    temp[4 * i + 0] = block[base1] + (unsigned int)block[base1 + xStride];
    temp[4 * i + 1] = block[base1] - (unsigned int)block[base1 + xStride];
    temp[4 * i + 2] = block[base2] + (unsigned int)block[base2 + xStride];
    temp[4 * i + 3] = block[base2] - (unsigned int)block[base2 + xStride];
}
}
