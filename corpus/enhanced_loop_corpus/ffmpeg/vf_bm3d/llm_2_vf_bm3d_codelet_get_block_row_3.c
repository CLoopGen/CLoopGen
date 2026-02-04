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
    for (j = 0; j < block_size; j += 2) {
        dst[j] = src[j];
        if (j + 1 < block_size) {
            dst[j + 1] = src[j + 1];
        }
    }
}
