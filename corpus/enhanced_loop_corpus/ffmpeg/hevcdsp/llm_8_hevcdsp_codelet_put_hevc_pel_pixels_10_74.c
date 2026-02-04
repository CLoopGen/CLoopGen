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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        dst[x] = src[x] << (14 - 10);
        if (y + 1 < height) {
            dst[64 + x] = src[srcstride + x] << (14 - 10);
        }
    }
    src += srcstride * (y + 1 < height ? 2 : 1);
    dst += 64 * (y + 1 < height ? 2 : 1);
}
}
