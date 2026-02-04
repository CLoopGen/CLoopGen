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
int prev_dst_val = 0;
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = (prev_dst_val << 3); // Introduce WAW and loop-carried dependency: reuse previous output
    for (j = 0; j < filterSize; j++) {
        val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
    }
    int result = val >> 3;
    result = (result > ((1 << 19) - 1)) ? ((1 << 19) - 1) : result;
    dst[i] = result;
    prev_dst_val = result; // Create loop-carried dependence (WAW via prev_dst_val)
}
}
