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
    // Change to strided memory access: access every 2nd element in filter and src, with wrap-around logic if needed
    for (j = 0; j < filterSize; j += 2) {
        val += src[srcPos + j] * filter[filterSize * i + j];
        if (j + 1 < filterSize) {
            val += src[srcPos + j + 1] * filter[filterSize * i + j + 1];
        }
    }
    dst[i] = ((val >> sh) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val >> sh));
}
}
