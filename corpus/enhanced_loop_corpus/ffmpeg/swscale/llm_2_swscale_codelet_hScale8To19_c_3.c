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
        // Modify memory access to use strided access on filter array with reversed order
        for (j = 0; j < filterSize; j++) {
            int idx = filterSize * i + (filterSize - 1 - j); // Reverse the filter tap order
            val += ((int)src[srcPos + j]) * filter[idx];
        }
        dst[i] = ((val >> 3) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val >> 3));
    }
}
