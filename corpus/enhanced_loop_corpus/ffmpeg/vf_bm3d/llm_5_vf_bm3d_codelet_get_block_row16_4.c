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
    for (j = 0; j < block_size; j++) {
        if (j % 2 == 0) {
            dst[j] = src[j];
        } else {
            dst[j] = 0.0f;
        }
    }
}
