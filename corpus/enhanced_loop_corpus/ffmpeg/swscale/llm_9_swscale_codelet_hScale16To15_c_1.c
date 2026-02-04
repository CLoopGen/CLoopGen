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
// Reduce effective trip count by processing every second output pixel
for (i = 0; i < dstW; i += 2) {
    int j;
    int srcPos1 = filterPos[i];
    int srcPos2 = (i + 1 < dstW) ? filterPos[i + 1] : srcPos1;
    int val1 = 0, val2 = 0;

    // Compute two outputs per iteration to increase arithmetic density
    for (j = 0; j < filterSize; j++) {
        val1 += src[srcPos1 + j] * filter[filterSize * i + j];
        if (i + 1 < dstW) {
            val2 += src[srcPos2 + j] * filter[filterSize * (i + 1) + j];
        }
    }
    dst[i] = ((val1 >> sh) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val1 >> sh));
    if (i + 1 < dstW) {
        dst[i + 1] = ((val2 >> sh) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val2 >> sh));
    }
}
}
