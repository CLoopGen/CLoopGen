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
    for (x = 0; x < 16; x++) {
        int val1 = (c * tmp[x] + d * tmp[x + 16] + 8) >> 4;
        int val2 = (d * tmp[x] + c * tmp[x + 16] + 8) >> 4;
        dst[x] = val1;
        dst[dstride + x] = val2;
    }
    dst += 2 * dstride;
    tmp += 16;
}
}
