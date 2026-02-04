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
    if (width >= 4) {
        for (j = 0; j < width - 3; j += 4) {
            dst[j]   = (dst[j]   + (((src[j]   + 2 * src[j + 1] + 1) * 683) >> 11) + 1) >> 1;
            dst[j+1] = (dst[j+1] + (((src[j+1] + 2 * src[j + 2] + 1) * 683) >> 11) + 1) >> 1;
            dst[j+2] = (dst[j+2] + (((src[j+2] + 2 * src[j + 3] + 1) * 683) >> 11) + 1) >> 1;
            dst[j+3] = (dst[j+3] + (((src[j+3] + 2 * src[j + 4] + 1) * 683) >> 11) + 1) >> 1;
        }
        for (; j < width; j++)
            dst[j] = (dst[j] + (((src[j] + 2 * src[j + 1] + 1) * 683) >> 11) + 1) >> 1;
    } else {
        for (j = 0; j < width; j++)
            dst[j] = (dst[j] + (((src[j] + 2 * src[j + 1] + 1) * 683) >> 11) + 1) >> 1;
    }
    src += stride;
    dst += stride;
}
}
