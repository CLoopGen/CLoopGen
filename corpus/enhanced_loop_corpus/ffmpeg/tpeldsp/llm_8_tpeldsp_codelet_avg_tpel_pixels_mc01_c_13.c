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
        dst[j] = (dst[j] + (((3 * src[j] + 2 * src[j + stride] + src[j + 2*stride] + 1) * 455) >> 10) + 1) >> 1;
    }
    for (j = 0; j < width; j++) {
        dst[j + stride] = (dst[j + stride] + (((src[j] + 3 * src[j + stride] + 1) * 683) >> 11)) >> 1;
    }
    src += 2 * stride;
    dst += 2 * stride;
}
}
