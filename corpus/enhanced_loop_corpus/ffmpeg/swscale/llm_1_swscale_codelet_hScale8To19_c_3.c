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
    int i, j, k;
    for (i = 0; i < dstW; i++) {
        int srcPos = filterPos[i];
        int val = 0;
        for (k = 0; k < (filterSize + 3) / 4; k++) {
            for (j = 0; j < 4 && (j + 4*k) < filterSize; j++) {
                int idx = 4 * k + j;
                val += ((int)src[srcPos + idx]) * filter[filterSize * i + idx];
            }
        }
        dst[i] = ((val >> 3) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val >> 3));
    }
}
