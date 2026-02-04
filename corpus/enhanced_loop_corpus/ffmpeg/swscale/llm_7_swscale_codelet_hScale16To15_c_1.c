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
    int prev_dst_val = 0;
    for (i = 0; i < dstW; i++) {
        int j;
        int srcPos = filterPos[i];
        int val = (i > 0) ? prev_dst_val : 0; // Introduce WAW and loop-carried dependency
        for (j = 0; j < filterSize; j++) {
            val += src[srcPos + j] * filter[filterSize * i + j];
        }
        int shifted_val = val >> sh;
        int clamped_val = (shifted_val > ((1 << 15) - 1)) ? ((1 << 15) - 1) : shifted_val;
        dst[i] = clamped_val;
        prev_dst_val = clamped_val; // Create loop-carried dependence (WAW -> RAW)
    }
}
