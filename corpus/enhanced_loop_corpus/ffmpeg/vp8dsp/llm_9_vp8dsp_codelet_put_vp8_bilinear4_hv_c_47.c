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
    for (x = 0; x < 4; x++) {
        dst[x] = (c * tmp[x] + d * tmp[x + 4] + 4) >> 3;
        if (y + 1 < h)
            dst[dstride + x] = (c * tmp[x + 8] + d * tmp[x + 12] + 4) >> 3;
    }
    dst += 2 * dstride;
    tmp += 16;
}
}
