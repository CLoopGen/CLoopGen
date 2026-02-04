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
    for (j = 0; j < width - 2; j += 2) {
        dst[j]   = ((3 * src[j] + 2 * src[j + 1] + src[j + 2] + 2) * 455) >> 10;
        dst[j+1] = ((3 * src[j+1] + 2 * src[j + 2] + src[j + 3] + 2) * 455) >> 10;
    }
    if (j == width - 2)
        dst[j] = ((3 * src[j] + 2 * src[j + 1] + src[j + 2] + 2) * 455) >> 10;
    src += stride;
    dst += stride;
}
}
