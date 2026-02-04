#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < 4; x++) {
        int base = x * 4;
        dst[base + 0] = (c * tmp[base + 0] + d * tmp[base + 16 + 0] + 4) >> 3;
        dst[base + 1] = (c * tmp[base + 1] + d * tmp[base + 16 + 1] + 4) >> 3;
        dst[base + 2] = (c * tmp[base + 2] + d * tmp[base + 16 + 2] + 4) >> 3;
        dst[base + 3] = (c * tmp[base + 3] + d * tmp[base + 16 + 3] + 4) >> 3;
    }
    dst += dstride;
    tmp += 16;
}
}
