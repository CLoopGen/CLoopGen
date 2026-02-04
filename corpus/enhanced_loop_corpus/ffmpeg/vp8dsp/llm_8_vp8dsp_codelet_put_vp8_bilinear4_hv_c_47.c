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
    for (x = 0; x < 8; x += 2) {
        int val1 = (c * tmp[x] + d * tmp[x + 4] + 8) >> 4;
        int val2 = (c * tmp[x + 1] + d * tmp[x + 5] + 8) >> 4;
        dst[x] = val1;
        dst[x + 1] = val2;
    }
    dst += dstride;
    tmp += 8;
}
}
