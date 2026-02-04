#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int block_size;
extern float *dst;
extern  uint8_t *src;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 4;
    for (j = 0; j < block_size; j += stride) {
        for (int k = 0; k < stride && (j + k) < block_size; k++) {
            dst[j + k] = src[j + k];
        }
    }
}
