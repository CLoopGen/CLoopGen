#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t src_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with manual pointer arithmetic unrolling
    uint8_t *src_line = src;
    uint8_t *dst_line = dst;
    for (y = 0; y < h; y++) {
        uint64_t *d = (uint64_t *)dst_line;
        const uint64_t *s = (const uint64_t *)src_line;
        for (x = 0; x < w; x++) {
            d[x] = s[x * (src_linesize / sizeof(uint64_t))];
        }
        dst_line += dst_linesize;
        src_line += 8;
    }
}
