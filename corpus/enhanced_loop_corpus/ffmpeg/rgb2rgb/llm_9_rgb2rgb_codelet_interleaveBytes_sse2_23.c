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
    for (w = 0; w < (width & (~1)); w += 2) {
        uint8_t s1_val = src1[w];
        uint8_t s2_val = src2[w];
        dest[2 * w + 0] = s1_val;
        dest[2 * w + 1] = s2_val;
        if (w + 1 < width) {
            s1_val = src1[w + 1];
            s2_val = src2[w + 1];
            dest[2 * (w + 1) + 0] = s1_val;
            dest[2 * (w + 1) + 1] = s2_val;
        }
    }
    dest += 2 * dstStride;
    src1 += 2 * src1Stride;
    src2 += 2 * src2Stride;
    if (h + 1 >= height) break;
    for (w = 0; w < (width & (~1)); w += 2) {
        dest[2 * w + 0] = src1[w];
        dest[2 * w + 1] = src2[w];
        if (w + 1 < width) {
            dest[2 * (w + 1) + 0] = src1[w + 1];
            dest[2 * (w + 1) + 1] = src2[w + 1];
        }
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
