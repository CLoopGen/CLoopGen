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
    int16_t *filterBase = &filter[filterSize * i];
    const uint8_t *srcBase = &src[srcPos];
    for (j = 0; j < filterSize; j++) {
        val += ((int)srcBase[j]) * filterBase[j];
    }
    dst[i] = ((val >> 7) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val >> 7));
}
}
