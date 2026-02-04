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
    // Variant 2: Reduced arithmetic operations via precomputed pointers and simplified indexing
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    for (y = 0; y < h; y++) {
        uint16_t *d = (uint16_t *)dst_row;
        uint8_t *s = src_row;
        for (x = 0; x < w; x++) {
            d[x] = *((uint16_t *)s);
            s += src_linesize;
        }
        dst_row += dst_linesize;
        src_row += 2;
    }
}
