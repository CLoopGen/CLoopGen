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
        for (x = 0; x < width; x++) {
            if (src[x] > 100) {
                dst[x] = src[x] << (14 - 12);
            } else {
                dst[x] = 50 << (14 - 12);
            }
        }
        src += srcstride;
        dst += 64;
    }
}
