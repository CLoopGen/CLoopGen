#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern uint8_t *dest;
extern int width;
extern int height;
extern int src1Stride;
extern int src2Stride;
extern int dstStride;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < height; h++) {
    int w;
    uint8_t temp1, temp2;
    if (width >= 16) {
    }
    for (w = (width & (~15)); w < width; w++) {
        temp1 = src1[w];
        temp2 = src2[w];
        dest[2 * w + 0] = temp1;
        dest[2 * w + 1] = temp2;
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
