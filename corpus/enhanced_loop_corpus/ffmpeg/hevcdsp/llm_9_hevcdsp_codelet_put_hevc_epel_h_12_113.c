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
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += 4) {
            for (int offset = 0; offset < 4 && (x + offset) < width; offset++) {
                int idx = x + offset;
                dst[idx] = (filter[0] * src[idx - 1] + 
                            filter[1] * src[idx] + 
                            filter[2] * src[idx + 1] + 
                            filter[3] * src[idx + 2]) >> 4;
            }
        }
        src += srcstride;
        dst += 64;
    }
}
