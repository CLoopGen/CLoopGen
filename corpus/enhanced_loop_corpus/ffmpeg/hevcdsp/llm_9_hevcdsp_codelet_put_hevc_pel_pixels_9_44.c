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
        for (x = 0; x < width; x += 4) {
            dst[x + 0] = src[x + 0] << (14 - 9);
            dst[x + 1] = src[x + 1] << (14 - 9);
            dst[x + 2] = src[x + 2] << (14 - 9);
            dst[x + 3] = src[x + 3] << (14 - 9);
        }
        src += srcstride;
        dst += 64;
    }
}
