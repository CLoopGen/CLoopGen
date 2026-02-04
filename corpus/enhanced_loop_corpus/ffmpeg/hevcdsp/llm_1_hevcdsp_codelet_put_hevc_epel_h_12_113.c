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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        dst[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
        if (y + 1 < height) {
            int16_t *dst_next = dst + 64;
            uint16_t *src_next = (uint16_t*)((uint8_t*)src + srcstride);
            dst_next[x] = (filter[0] * src_next[x - 1] + filter[1] * src_next[x] + 
                           filter[2] * src_next[x + 1] + filter[3] * src_next[x + 2]) >> 4;
        }
    }
    src += srcstride;
    dst += 64;
    if (y + 1 < height) {
        src += srcstride;
        dst += 64;
    }
}
}
