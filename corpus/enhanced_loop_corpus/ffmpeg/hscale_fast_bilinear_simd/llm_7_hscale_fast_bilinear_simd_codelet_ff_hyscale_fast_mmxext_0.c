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
    int prev_i = dstWidth;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--) {
        dst[i] = src[srcW - 1] * 128;
        if (prev_i != dstWidth) {
            dst[i] += (dst[prev_i] >> 4); // Introduce WAW and RAW dependency
        }
        prev_i = i;
    }
}
