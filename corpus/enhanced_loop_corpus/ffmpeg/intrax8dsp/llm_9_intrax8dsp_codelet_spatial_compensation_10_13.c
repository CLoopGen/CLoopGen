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
for (y = 0; y < 16; y += 2) {
    for (x = 0; x < 4; x++) {
        int offset1 = 15 - (y % 8);
        int offset2 = 25 + x;
        int weight1 = 8 - x;
        int weight2 = x;
        dst[x] = (src[offset1] * weight1 + src[offset2] * weight2 + 4) >> 3;
    }
    dst += stride;
    if (y + 1 < 16) {
        for (x = 0; x < 4; x++) {
            int offset1 = 15 - ((y + 1) % 8);
            int offset2 = 25 + x;
            dst[x] = (src[offset1] * (8 - x) + src[offset2] * x + 12) >> 4;
        }
        dst += stride;
    }
}
}
