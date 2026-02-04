#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstW;
extern  uint8_t *src;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = 0;
    int clampedVal;
    for (j = 0; j < filterSize; j++) {
        val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
    }
    clampedVal = val >> 7;
    if (clampedVal <= (1 << 15) - 1) {
        dst[i] = clampedVal;
    } else {
        dst[i] = (1 << 15) - 1;
    }
}
}
