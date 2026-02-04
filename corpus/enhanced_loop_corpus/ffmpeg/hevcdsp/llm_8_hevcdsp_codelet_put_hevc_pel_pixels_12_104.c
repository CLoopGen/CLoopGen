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
            int16_t val1 = src[x] << (14 - 12);
            int16_t val2 = src[x] >> 1;
            dst[x] = val1 + val2;
        }
        for (x = 0; x < width; x++) {
            dst[x] += dst[x] >> 4;
        }
        if (y + 1 < height) {
            src += srcstride * 2;
            dst += 64 * 2;
        } else {
            src += srcstride;
            dst += 64;
        }
    }
}
