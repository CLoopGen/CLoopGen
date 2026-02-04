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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize memory access to prefetch and process data in a more cache-friendly, consecutive manner
    // by transposing the iteration order and using local accumulators for filter taps.
    
    int16_t *dst_line = dst;
    uint8_t *src_line = src;

    for (y = 0; y < height; y++) {
        const uint8_t *base_ptr = &src_line[x];
        for (x = 0; x < width; x++) {
            int sum = 0;
            // Access source pixels with fixed offsets relative to current x
            sum += filter[0] * src_line[x - 3*srcstride];
            sum += filter[1] * src_line[x - 2*srcstride];
            sum += filter[2] * src_line[x -   srcstride];
            sum += filter[3] * src_line[x                 ];
            sum += filter[4] * src_line[x +   srcstride];
            sum += filter[5] * src_line[x + 2*srcstride];
            sum += filter[6] * src_line[x + 3*srcstride];
            sum += filter[7] * src_line[x + 4*srcstride];
            dst_line[x] = sum >> 8;
        }
        src_line += srcstride;
        dst_line += 64;
    }
}
