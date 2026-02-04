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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // Access pattern changed to process two pixels consecutively per iteration to promote spatial locality
    for (y = 0; y < h; y++, dst += dst_linesize, src += 4) {
        uint32_t *d = (uint32_t *)dst;
        uint8_t *s = src;
        for (x = 0; x + 1 < w; x += 2) {
            d[x]     = *((uint32_t *)(s + x * src_linesize));
            d[x + 1] = *((uint32_t *)(s + (x + 1) * src_linesize));
        }
        // Handle remaining element if w is odd
        if (x < w) {
            d[x] = *((uint32_t *)(s + x * src_linesize));
        }
    }
}
