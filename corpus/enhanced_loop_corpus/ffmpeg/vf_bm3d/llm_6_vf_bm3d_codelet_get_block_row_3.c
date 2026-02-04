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
    float temp;
    for (j = 0; j < block_size; j++) {
        temp = src[j];
        dst[j] = temp;
    }
}
