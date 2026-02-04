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
        for (x = 7; x >= 0; x--) {
            uint8_t val = (c * tmp[x] + d * tmp[x + 8] + 4) >> 3;
            dst[x] = val;
        }
        dst += dstride;
        tmp += 8;
    }
}
