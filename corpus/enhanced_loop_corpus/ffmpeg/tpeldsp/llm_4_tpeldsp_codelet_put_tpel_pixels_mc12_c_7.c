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
    if (width > 0) {
        j = 0;
        dst[j] = ((3 * src[j] + 2 * src[j + 1] + 4 * src[j + stride] + 3 * src[j + stride + 1] + 6) * 2731) >> 15;
        for (j = 1; j < width - 1; j++)
            dst[j] = ((3 * src[j] + 2 * src[j + 1] + 4 * src[j + stride] + 3 * src[j + stride + 1] + 6) * 2731) >> 15;
        if (width > 1)
            dst[width - 1] = ((3 * src[width - 1] + 2 * src[width] + 4 * src[width - 1 + stride] + 3 * src[width + stride] + 6) * 2731) >> 15;
    }
    src += stride;
    dst += stride;
}
}
