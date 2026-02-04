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
    for (int i = 0; i < block_size / 2; i++) {
        for (j = i * 2; j < (i + 1) * 2 && j < block_size; j++) {
            dst[j] = src[j];
        }
    }
    if (block_size % 2 != 0) {
        j = block_size - 1;
        dst[j] = src[j];
    }
}
