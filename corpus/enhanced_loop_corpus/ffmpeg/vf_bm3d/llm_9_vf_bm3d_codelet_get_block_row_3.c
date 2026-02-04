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
    float sum = 0.0f;
    for (j = 0; j < block_size * 2; j++) {
        int idx = j / 2;
        sum += src[idx];
        dst[idx] = sum / (j + 1);
    }
}
