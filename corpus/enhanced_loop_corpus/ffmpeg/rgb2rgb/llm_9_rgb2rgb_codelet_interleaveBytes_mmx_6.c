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
for (h = 0; h < height; h += 2) {
    int w;
    for (w = 0; w < (width & (~15)); w += 16) {
        for (int s = 0; s < 16; s++) {
            dest[2 * (w + s)] = src1[w + s];
            dest[2 * (w + s) + 1] = src2[w + s];
        }
    }
    for (; w < width; w++) {
        dest[2 * w] = src1[w];
        dest[2 * w + 1] = src2[w];
    }
    if (h + 1 < height) {
        uint8_t* d1 = dest + dstStride;
        uint8_t* s1_1 = src1 + src1Stride;
        uint8_t* s2_1 = src2 + src2Stride;
        for (w = 0; w < width; w++) {
            d1[2 * w] = s1_1[w];
            d1[2 * w + 1] = s2_1[w];
        }
        dest += 2 * dstStride;
        src1 += 2 * src1Stride;
        src2 += 2 * src2Stride;
    } else {
        dest += dstStride;
        src1 += src1Stride;
        src2 += src2Stride;
    }
}
}
