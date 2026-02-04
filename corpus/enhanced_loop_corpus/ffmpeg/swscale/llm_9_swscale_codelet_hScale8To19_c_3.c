#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dstW;
extern  uint8_t *src;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstW; i += 2) {
    int j;
    int srcPos1 = filterPos[i];
    int srcPos2 = (i + 1 < dstW) ? filterPos[i + 1] : srcPos1;
    int val1 = 0, val2 = 0;
    int doSecond = (i + 1) < dstW;
    for (j = 0; j < filterSize; j++) {
        val1 += ((int)src[srcPos1 + j]) * filter[filterSize * i + j];
        if (doSecond) {
            val2 += ((int)src[srcPos2 + j]) * filter[filterSize * (i + 1) + j];
        }
    }
    dst[i] = ((val1 >> 3) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val1 >> 3));
    if (doSecond) {
        dst[i + 1] = ((val2 >> 3) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val2 >> 3));
    }
}
}
