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
    for (j = 0; j < width; j += 2) {
        dst[j] = (dst[j] + (((3 * src[j] + 2 * src[j + 1] + 4 * src[j + stride] + 3 * src[j + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
        if (j + 1 < width) {
            dst[j + 1] = (dst[j + 1] + (((3 * src[j + 1] + 2 * src[j + 2] + 4 * src[j + 1 + stride] + 3 * src[j + 2 + stride] + 6) * 2731) >> 15) + 1) >> 1;
        }
    }
    if (i + 1 < height) {
        src += stride;
        dst += stride;
        for (j = 0; j < width; j++) {
            dst[j] = (dst[j] + (((src[j] + src[j + 1] + src[j + stride] + src[j + stride + 1] + 2) * 8192) >> 16) + 1) >> 1;
        }
    }
    src += stride;
    dst += stride;
}
}
