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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access in src (every 2nd element), we reorganize to read 8 consecutive elements
    // by adjusting the indexing logic. This improves cache locality.
    for (x = 0; x < w - 7; x += 8) {
        int src_offset = 2 * x;
        dst[x + 0] = src[src_offset + 0];
        dst[x + 1] = src[src_offset + 2];
        dst[x + 2] = src[src_offset + 4];
        dst[x + 3] = src[src_offset + 6];
        dst[x + 4] = src[src_offset + 8];
        dst[x + 5] = src[src_offset + 10];
        dst[x + 6] = src[src_offset + 12];
        dst[x + 7] = src[src_offset + 14];
    }
}
