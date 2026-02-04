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
    for (j = 0; j < filterSize; j++) {
        if (filter[filterSize * i + j] != 0) {
            val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
        }
    }
    dst[i] = ((val >> 3) > ((1 << 19) - 1)) ? ((1 << 19) - 1) : (val >> 3);
}
}
