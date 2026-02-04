#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int block_size;
extern int y;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < block_size * block_size; y++) {
    int idx = y % block_size;
    int offset = (y / block_size) * stride + idx;
    sum += src[offset] * 2; // Increased arithmetic per element
}
}
