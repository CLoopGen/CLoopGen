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
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = 0;
    int temp_filter_offset = filterSize * i;
    for (j = 0; j < filterSize; j++) {
        int fetched_src = (int)src[srcPos + j];
        val += fetched_src * filter[temp_filter_offset + j];
    }
    int shifted_val = val >> 3;
    dst[i] = (shifted_val > ((1 << 19) - 1)) ? ((1 << 19) - 1) : shifted_val;
}
}
