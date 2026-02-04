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
    int unroll_factor = 4;
    int remainder = filterSize % unroll_factor;
    
    // Unrolled loop for better computational intensity
    for (j = 0; j < filterSize - remainder; j += unroll_factor) {
        val += src[srcPos + j] * filter[filterSize * i + j];
        val += src[srcPos + j + 1] * filter[filterSize * i + j + 1];
        val += src[srcPos + j + 2] * filter[filterSize * i + j + 2];
        val += src[srcPos + j + 3] * filter[filterSize * i + j + 3];
    }
    // Handle leftover iterations
    for (; j < filterSize; j++) {
        val += src[srcPos + j] * filter[filterSize * i + j];
    }
    dst[i] = ((val >> sh) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val >> sh));
}
}
