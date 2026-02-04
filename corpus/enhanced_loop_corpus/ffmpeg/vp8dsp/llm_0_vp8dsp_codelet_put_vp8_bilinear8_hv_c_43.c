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
    x = 0;
    dst[x + 0] = (c * tmp[x + 0] + d * tmp[x + 8] + 4) >> 3;
    dst[x + 1] = (c * tmp[x + 1] + d * tmp[x + 9] + 4) >> 3;
    dst[x + 2] = (c * tmp[x + 2] + d * tmp[x + 10] + 4) >> 3;
    dst[x + 3] = (c * tmp[x + 3] + d * tmp[x + 11] + 4) >> 3;
    dst[x + 4] = (c * tmp[x + 4] + d * tmp[x + 12] + 4) >> 3;
    dst[x + 5] = (c * tmp[x + 5] + d * tmp[x + 13] + 4) >> 3;
    dst[x + 6] = (c * tmp[x + 6] + d * tmp[x + 14] + 4) >> 3;
    dst[x + 7] = (c * tmp[x + 7] + d * tmp[x + 15] + 4) >> 3;
    dst += dstride;
    tmp += 8;
}
}
