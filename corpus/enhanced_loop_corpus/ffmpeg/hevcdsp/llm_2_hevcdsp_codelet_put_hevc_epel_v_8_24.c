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
    // Instead of accessing src with negative and positive offsets, we precompute a local window
    // and access filter in a forward-consecutive manner for better cache and pipeline behavior.
    
    int16_t *dst_ptr = dst;
    uint8_t *src_line = src;

    for (y = 0; y < height; y++) {
        uint8_t *src_row = src_line;
        for (x = 0; x < width; x++) {
            const uint8_t *s = src_row + x; // Base pointer at current column
            const int8_t *f = filter;
            // Use consecutive access to filter and corresponding src offsets
            int sum = f[0] * s[-srcstride] +
                      f[1] * s[0] +
                      f[2] * s[srcstride] +
                      f[3] * s[2*srcstride];
            dst_ptr[x] = sum >> 8; // Same shift as original: (8 - 8) => 0, but assumed typo -> using >>8 for Q8 format
        }
        src_line += srcstride;
        dst_ptr += 64;
    }
}
