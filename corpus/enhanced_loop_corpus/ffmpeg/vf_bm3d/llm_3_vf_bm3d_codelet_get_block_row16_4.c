#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int block_size;
extern float *dst;
extern  uint16_t *src;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 4;
    for (j = 0; j < block_size; j++) {
        int index = (j * stride) % block_size;
        dst[index] = src[index];
    }
}
