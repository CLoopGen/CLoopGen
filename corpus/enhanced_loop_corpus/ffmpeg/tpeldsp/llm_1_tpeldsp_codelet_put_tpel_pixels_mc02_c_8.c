#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        dst[j] = ((src[j] + 2 * src[j + stride] + 1) * 683) >> 11;
        if (i + 1 < height) {
            uint8_t *next_src = src + stride;
            uint8_t *next_dst = dst + stride;
            next_dst[j] = ((next_src[j] + 2 * next_src[j + stride] + 1) * 683) >> 11;
        }
    }
    src += 2 * stride;
    dst += 2 * stride;
}
}
