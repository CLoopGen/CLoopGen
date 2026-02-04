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
        dst[j] = (dst[j] + (((3 * src[j] + 2 * src[j + 1] + 2 * src[j + stride] + src[j + stride + 1] + 4) * 1638) >> 14) + 1) >> 1;
    }
    if (i + 1 < height) {
        src += stride;
        dst += stride;
        for (j = 0; j < width; j++) {
            dst[j] = (dst[j] + (((src[j] + src[j + 1] + src[j + stride] + src[j + stride + 1] + 2) * 819) >> 13) + 1) >> 1;
        }
    }
    src += stride;
    dst += stride;
}
}
