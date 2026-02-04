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
    int shift_val;
    for (j = 0; j < filterSize; j++) {
        val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
    }
    shift_val = val >> 3;
    if (shift_val <= ((1 << 19) - 1)) {
        dst[i] = shift_val;
    } else {
        dst[i] = (1 << 19) - 1;
    }
}
}
