#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x += 2) {
        dst[x] = src[x] << (14 - 8);
        if (x + 1 < width)
            dst[x + 1] = src[x + 1] << (14 - 8);
    }
    for (x = 0; x < width && y + 1 < height; x++)
        dst[64 + x] = src[srcstride + x] << (14 - 8);
    src += srcstride * 2;
    dst += 128;
}
}
