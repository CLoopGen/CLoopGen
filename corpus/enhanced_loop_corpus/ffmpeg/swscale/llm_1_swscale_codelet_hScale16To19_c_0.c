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
    int i, j, k;
    for (i = 0; i < dstW; i++) {
        int srcPos = filterPos[i];
        int val = 0;
        for (j = 0; j < (filterSize + 3) / 4; j++) {
            int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
            int idx = j * 4;
            if (idx < filterSize) {
                sum1 = src[srcPos + idx] * filter[filterSize * i + idx];
            }
            if (idx + 1 < filterSize) {
                sum2 = src[srcPos + idx + 1] * filter[filterSize * i + idx + 1];
            }
            if (idx + 2 < filterSize) {
                sum3 = src[srcPos + idx + 2] * filter[filterSize * i + idx + 2];
            }
            if (idx + 3 < filterSize) {
                sum4 = src[srcPos + idx + 3] * filter[filterSize * i + idx + 3];
            }
            val += sum1 + sum2 + sum3 + sum4;
        }
        dst[i] = ((val >> sh) > ((1 << 19) - 1) ? ((1 << 19) - 1) : (val >> sh));
    }
}
