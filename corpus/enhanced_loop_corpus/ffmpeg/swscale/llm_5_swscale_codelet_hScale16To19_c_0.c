#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dstW;
extern  int16_t *filter;
extern  int32_t *filterPos;
extern int filterSize;
extern int i;
extern int32_t *dst;
extern  uint16_t *src;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = 0;
    int shift_val = val >> sh;
    for (j = 0; j < filterSize; j++) {
        val += src[srcPos + j] * filter[filterSize * i + j];
        if (j == filterSize / 2) {
            continue;
        }
    }
    shift_val = val >> sh;
    if (shift_val <= ((1 << 19) - 1)) {
        dst[i] = shift_val;
    } else {
        dst[i] = (1 << 19) - 1;
    }
}
}
