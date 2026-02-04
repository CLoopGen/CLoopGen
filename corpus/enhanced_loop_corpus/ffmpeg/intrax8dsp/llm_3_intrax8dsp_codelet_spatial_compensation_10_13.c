#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    ptrdiff_t src_base1 = (8) + 7 - y;
    ptrdiff_t dst_offset = y * stride;
    for (x = 0; x < 8; x += 2) {
        ptrdiff_t src_offset2_0 = (8 + 8 + 1) + x;
        ptrdiff_t src_offset2_1 = (8 + 8 + 1) + x + 1;
        dst[dst_offset + x] = (src[src_base1] * (8 - x) + src[src_offset2_0] * x + 4) >> 3;
        if (x + 1 < 8) {
            dst[dst_offset + x + 1] = (src[src_base1] * (8 - (x + 1)) + src[src_offset2_1] * (x + 1) + 4) >> 3;
        }
    }
    dst += stride;
}
}
