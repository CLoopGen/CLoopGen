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
int prev_srcPos = 0;
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = (srcPos < prev_srcPos) ? 0 : dst[i-1] & 0xFFFF; // Introduce WAW and RAW dependency using prior dst
    for (j = 0; j < filterSize; j++) {
        int idx = srcPos + j;
        val += src[idx] * filter[filterSize * i + j];
    }
    prev_srcPos = srcPos;
    dst[i] = ((val >> sh) > ((1 << 19) - 1)) ? ((1 << 19) - 1) : (val >> sh);
}
}
