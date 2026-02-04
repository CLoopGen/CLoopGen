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
int prev_dst_val = 0;
for (i = 0; i < dstW; i++) {
    int j;
    int srcPos = filterPos[i];
    int val = prev_dst_val; // Introduce WAW dependency: current iteration depends on previous write to dst
    for (j = 0; j < filterSize; j++) {
        val += ((int)src[srcPos + j]) * filter[filterSize * i + j];
    }
    dst[i] = ((val >> 7) > ((1 << 15) - 1) ? ((1 << 15) - 1) : (val >> 7));
    prev_dst_val = dst[i]; // Carry forward written value to next iteration
}
}
