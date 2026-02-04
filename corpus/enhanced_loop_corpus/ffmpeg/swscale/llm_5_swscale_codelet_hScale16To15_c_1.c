#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstW;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;
extern  uint16_t *src;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = 0;
    int shifted_val;
    for (j = 0; j < filterSize; j++) {
        val += src[srcPos + j] * filter[filterSize * i + j];
    }
    shifted_val = val >> sh;
    if (shifted_val < 0) {
        dst[i] = 0;
    } else if (shifted_val > ((1 << 15) - 1)) {
        dst[i] = (1 << 15) - 1;
    } else {
        dst[i] = shifted_val;
    }
}
}
