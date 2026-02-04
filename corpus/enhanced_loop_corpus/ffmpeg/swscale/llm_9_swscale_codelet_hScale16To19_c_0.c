#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dstW;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;
extern int32_t *dst;
extern  uint16_t *src;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstW; i += 2) {
    int j;
    int srcPos1 = filterPos[i];
    int srcPos2 = (i + 1 < dstW) ? filterPos[i + 1] : srcPos1;
    int val1 = 0, val2 = 0;
    for (j = 0; j < filterSize; j++) {
        val1 += src[srcPos1 + j] * filter[filterSize * i + j];
        if (i + 1 < dstW) {
            val2 += src[srcPos2 + j] * filter[filterSize * (i + 1) + j];
        }
    }
    dst[i] = ((val1 >> sh) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val1 >> sh));
    if (i + 1 < dstW) {
        dst[i + 1] = ((val2 >> sh) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val2 >> sh));
    }
}
}
