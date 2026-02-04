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
    // Variant 1: Consecutive Memory Access (transpose inner loop to access memory sequentially)
    for (y = 0; y < h; y++) {
        uint16_t *d = (uint16_t *)(dst + y * dst_linesize);
        const uint8_t *s_row = src + 2 * y;
        for (x = 0; x < w; x++) {
            d[x] = *((uint16_t *)(s_row + x * src_linesize));
        }
    }
}
