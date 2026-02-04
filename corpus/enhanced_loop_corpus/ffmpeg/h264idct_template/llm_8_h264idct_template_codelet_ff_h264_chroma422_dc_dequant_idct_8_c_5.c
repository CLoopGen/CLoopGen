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
for (i = 0; i < 8; i++) {
    int idx = stride * (i / 2) + xStride * (i % 2);
    temp[i] = (i % 2 == 0) ? 
        block[idx] + (unsigned int)block[idx + xStride] : 
        block[idx - xStride] - (unsigned int)block[idx];
}
}
