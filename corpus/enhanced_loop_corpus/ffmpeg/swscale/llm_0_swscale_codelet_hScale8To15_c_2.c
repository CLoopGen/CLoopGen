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
    int i, j;
    for (i = 0; i < dstW; i++) {
        int srcPos = filterPos[i];
        int val = 0;
        int unroll_factor = 4;
        int remainder = filterSize % unroll_factor;
        
        // Unrolled loop for better performance
        for (j = 0; j < filterSize - remainder; j += unroll_factor) {
            val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
            val += ((int)src[srcPos + j + 1]) * filter[filterSize * i + j + 1];
            val += ((int)src[srcPos + j + 2]) * filter[filterSize * i + j + 2];
            val += ((int)src[srcPos + j + 3]) * filter[filterSize * i + j + 3];
        }
        // Handle remaining iterations
        for (; j < filterSize; j++) {
            val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
        }
        dst[i] = ((val >> 7) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val >> 7));
    }
}
