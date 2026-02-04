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
    for (j = 0; j < width - 3; j += 4) {
        dst[j]   = (dst[j]   + (((5 * src[j]   + 4 * src[j+1]   + 4 * src[j+stride]   + 3 * src[j+stride+1]   + 7) * 2731) >> 15) + 1) >> 1;
        dst[j+1] = (dst[j+1] + (((5 * src[j+1] + 4 * src[j+2]   + 4 * src[j+stride+1] + 3 * src[j+stride+2]   + 7) * 2731) >> 15) + 1) >> 1;
        dst[j+2] = (dst[j+2] + (((5 * src[j+2] + 4 * src[j+3]   + 4 * src[j+stride+2] + 3 * src[j+stride+3]   + 7) * 2731) >> 15) + 1) >> 1;
        dst[j+3] = (dst[j+3] + (((5 * src[j+3] + 4 * src[j+4]   + 4 * src[j+stride+3] + 3 * src[j+stride+4]   + 7) * 2731) >> 15) + 1) >> 1;
    }
    // Handle remaining elements
    for (; j < width; j++)
        dst[j] = (dst[j] + (((4 * src[j] + 3 * src[j + 1] + 3 * src[j + stride] + 2 * src[j + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
    src += stride;
    dst += stride;
}
}
