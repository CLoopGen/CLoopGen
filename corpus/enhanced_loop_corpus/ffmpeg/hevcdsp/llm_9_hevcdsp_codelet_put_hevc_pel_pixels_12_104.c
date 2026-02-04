#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        int unroll_factor = (width / 4) * 4;
        for (x = 0; x < unroll_factor; x += 4) {
            dst[x + 0] = src[x + 0] << (14 - 12);
            dst[x + 1] = src[x + 1] << (14 - 12);
            dst[x + 2] = src[x + 2] << (14 - 12);
            dst[x + 3] = src[x + 3] << (14 - 12);
        }
        for (; x < width; x++) {
            dst[x] = src[x] << (14 - 12);
        }
        src += srcstride;
        dst += 64;
    }
}
