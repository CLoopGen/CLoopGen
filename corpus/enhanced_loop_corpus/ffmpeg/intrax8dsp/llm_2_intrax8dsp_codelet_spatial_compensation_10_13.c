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
    uint8_t *dst_row = dst + y * stride;
    for (x = 0; x < 8; x++) {
        ptrdiff_t src_offset1 = (8) + 7 - y;
        ptrdiff_t src_offset2 = (8 + 8 + 1) + x;
        dst_row[x] = (src[src_offset1] * (8 - x) + src[src_offset2] * x + 4) >> 3;
    }
}
}
