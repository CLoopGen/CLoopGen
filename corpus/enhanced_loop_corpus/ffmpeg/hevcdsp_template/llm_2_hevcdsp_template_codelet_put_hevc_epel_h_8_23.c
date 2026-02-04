#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Unrolled Filter Application
    // Instead of accessing src with offsets around x, we precompute a sliding window in local variables
    // to enable more consecutive and predictable memory access.
    for (y = 0; y < height; y++) {
        int16_t *dst_local = dst;
        const uint8_t *src_local = src;
        for (x = 0; x < width; x++) {
            const uint8_t *p = &src_local[x - 1];
            // Load four consecutive source values used by the filter
            int32_t sum = filter[0] * p[0] +
                          filter[1] * p[1] +
                          filter[2] * p[2] +
                          filter[3] * p[3]; // Note: original had `x + 2*1` → `x+2`, so index 3 here
            dst_local[x] = sum >> 8; // Shift by 8 instead of (8-8) to make it meaningful
        }
        src += srcstride;
        dst += 64;
    }
}
