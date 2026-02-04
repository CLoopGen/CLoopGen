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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        dst[x]             = (src[15 - y] * y + src[17 + x] * (8 - y) + 4) >> 3;
        dst[x + 4]         = (src[15 - y] * y + src[17 + x + 4] * (8 - y) + 4) >> 3;
    }
    for (x = 0; x < 4; x++) {
        dst[stride/2 + x]     = (src[15 - y] * (y+1) + src[17 + x] * (7 - y) + 4) >> 3;
        dst[stride/2 + x + 4] = (src[15 - y] * (y+1) + src[17 + x + 4] * (7 - y) + 4) >> 3;
    }
    dst += stride * 2;
}
}
