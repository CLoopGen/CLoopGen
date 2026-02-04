#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling by factor of 2
    // This modifies the access pattern to process two elements at a time, making it more sequential
    for (; x < w; x += 2) {
        if (x + 0 < w) dst[x + 0] = src[(x + 0) >> 1];
        if (x + 1 < w) dst[x + 1] = src[(x + 1) >> 1];
    }
}
