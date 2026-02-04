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
    // Variant 1: Increased computational intensity with unrolled inner loop and reduced trip count
    for (y = 0; y < h; y++, dst += dst_linesize, src += 2) {
        for (x = 0; x < w - 1; x += 2) {
            uint16_t *d = (uint16_t *)(dst + 2 * x);
            uint16_t s0 = *((uint16_t *)(src + x * src_linesize));
            uint16_t s1 = *((uint16_t *)(src + (x + 1) * src_linesize));
            d[0] = s0;
            d[1] = s1;
        }
        // Handle remaining element if w is odd
        if (x < w) {
            *((uint16_t *)(dst + 2 * x)) = *((uint16_t *)(src + x * src_linesize));
        }
    }
}
