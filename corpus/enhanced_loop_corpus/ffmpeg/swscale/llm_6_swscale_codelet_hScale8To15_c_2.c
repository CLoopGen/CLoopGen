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
    int temp_filter_index;
    for (j = 0; j < filterSize; j++) {
        temp_filter_index = filterSize * i + j;
        val += ((int)src[srcPos + j]) * filter[temp_filter_index];
    }
    dst[i] = ((val >> 7) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val >> 7));
}
}
