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
// Reduced computational intensity with decreased effective trip count and simplified computation
int step = 2; // Process every second pixel to reduce work
for (i = 0; i < dstW; i += step) {
    int j;
    int srcPos = filterPos[i];
    int val = 0;
    // Limit inner loop iterations to a fixed small size regardless of original filterSize
    int local_filter_size = filterSize > 4 ? 4 : filterSize;
    for (j = 0; j < local_filter_size; j++) {
        val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
    }
    int result = val >> 7;
    if (result > (1 << 15) - 1) result = (1 << 15) - 1;
    dst[i] = result;
    // Ensure all dst entries are written (propagate last value or zero for skipped indices)
    if (i + 1 < dstW) {
        dst[i + 1] = result; // Simplified: duplicate value instead of computing
    }
}
// Final pass to ensure full coverage if dstW is odd or step doesn't align
for (i = (dstW % step == 0 ? dstW - 1 : dstW); i < dstW; i++) {
    dst[i] = 0;
}
}
