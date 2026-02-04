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
int i_total = 0;
for (i = 0; i < dstW; i++) {
    int srcPos = filterPos[i];
    int val = 0;
    int j_start, j_step = filterSize;
    for (j_start = 0; j_start < filterSize; j_start++) {
        val += src[srcPos + j_start] * filter[filterSize * i + j_start];
    }
    dst[i] = ((val >> sh) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val >> sh));
}
}
