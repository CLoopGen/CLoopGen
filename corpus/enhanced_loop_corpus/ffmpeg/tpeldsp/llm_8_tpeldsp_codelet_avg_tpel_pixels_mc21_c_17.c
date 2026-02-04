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
        dst[j] = (dst[j] + (((2 * src[j] + 3 * src[j + 1] + src[j + stride] + 2 * src[j + stride + 1] + 4) * 1820) >> 14) + 1) >> 1;
        if (j + 1 < width)
            dst[j + 1] = (dst[j + 1] + (((2 * src[j + 1] + 3 * src[j + 2] + src[j + stride + 1] + 2 * src[j + stride + 2] + 4) * 1820) >> 14) + 1) >> 1;
    }
    src += 2 * stride;
    dst += 2 * stride;
}
}
