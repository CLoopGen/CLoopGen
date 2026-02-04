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
for (y = 0; y < h; y += 2) {
    if (y + 1 < h) {
        for (x = 0; x < 8; x++) {
            dst[x] = (c * tmp[x] + d * tmp[x + 8] + 4) >> 3;
            dst[dstride + x] = (c * tmp[x + 16] + d * tmp[x + 24] + 4) >> 3;
        }
        dst += 2 * dstride;
        tmp += 32;
    } else {
        for (x = 0; x < 8; x++)
            dst[x] = (c * tmp[x] + d * tmp[x + 8] + 4) >> 3;
        dst += dstride;
        tmp += 8;
    }
}
}
