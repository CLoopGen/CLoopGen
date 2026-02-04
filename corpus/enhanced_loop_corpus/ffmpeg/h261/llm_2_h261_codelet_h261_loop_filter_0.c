#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int x;
extern int temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices
    int base_src = 0;
    int base_src_stride = 7 * stride;
    for (x = 0; x < 8; x++) {
        temp[x] = 4 * src[base_src + x];
        temp[x + 56] = 4 * src[base_src_stride + x];
    }
}
