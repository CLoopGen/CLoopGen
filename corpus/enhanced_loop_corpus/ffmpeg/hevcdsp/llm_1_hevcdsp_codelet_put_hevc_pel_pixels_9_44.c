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
        x = 0;
        for (int block = 0; block < width; block += 8) {
            for (int k = 0; k < 8 && x < width; k++, x++) {
                dst[x] = src[x] << (14 - 9);
            }
        }
        src += srcstride;
        dst += 64;
    }
}
