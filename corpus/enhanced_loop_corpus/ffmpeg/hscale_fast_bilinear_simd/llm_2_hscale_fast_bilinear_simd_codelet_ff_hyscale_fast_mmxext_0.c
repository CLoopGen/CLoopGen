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
    // Variant 1: Consecutive memory access with reverse traversal but sequential store pattern
    int16_t *d = dst + dstWidth - 1;
    uint8_t val = src[srcW - 1] * 128;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--, d--) {
        *d = val;
    }
}
