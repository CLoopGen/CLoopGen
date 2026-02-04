#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        for (x = 0; x < 4; x++) {
            int temp_src = src[x];
            int temp_src_next = src[x + 1];
            if (temp_src < 16 || temp_src_next < 16) {
                dst[x] = 0;
            } else {
                dst[x] = (a * temp_src + b * temp_src_next + 4) >> 3;
            }
        }
        dst += dstride;
        src += sstride;
    }
}
