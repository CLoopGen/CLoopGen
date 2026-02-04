#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstWidth;
extern  uint8_t *src;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = xInc >> 8;
    int threshold = (srcW - 1) << 8;
    for (i = dstWidth - 1; (i * step) >= threshold; i -= 2) {
        int16_t pixel = src[srcW - 1] * 128;
        dst[i] = pixel;
        if (i > 0) dst[i-1] = pixel;
    }
}
