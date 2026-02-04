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
    int factor = (i % 2 == 0) ? 2896 : 2560;
    for (j = 0; j < width - 3; j += 4) {
        dst[j]   = ((5 * src[j] + 2 * src[j + 1] + src[j + stride] + 6) * factor) >> 15;
        dst[j+1] = ((5 * src[j+1] + 2 * src[j+2] + src[j+1+stride] + 6) * factor) >> 15;
        dst[j+2] = ((5 * src[j+2] + 2 * src[j+3] + src[j+2+stride] + 6) * factor) >> 15;
        dst[j+3] = ((5 * src[j+3] + 2 * src[j+4] + src[j+3+stride] + 6) * factor) >> 15;
    }
    // Handle remaining elements
    for (; j < width; j++) {
        dst[j] = ((4 * src[j] + 3 * src[j + 1] + 3 * src[j + stride] + 2 * src[j + stride + 1] + 6) * 2731) >> 15;
    }
    src += stride;
    dst += stride;
}
}
