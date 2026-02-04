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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        int offset = j;
        dst[offset] = (dst[offset] + (((3 * src[offset] + 2 * src[offset + 1] + 4 * src[offset + stride] + 3 * src[offset + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
    }
    src += stride;
    dst += stride;
}
}
