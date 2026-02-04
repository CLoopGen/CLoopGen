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
        int temp_filter_index = filterSize * i;
        for (j = 0; j < filterSize; j++) {
            int filtered_val = filter[temp_filter_index + j];
            val += src[srcPos + j] * filtered_val;
        }
        int shifted_val = val >> sh;
        dst[i] = (shifted_val > ((1 << 15) - 1)) ? ((1 << 15) - 1) : shifted_val;
    }
}
