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
    for (w = 0; w < width; w += 4) {
        dest[2 * w + 0] = src1[w];
        dest[2 * w + 1] = src2[w];
        if (w + 1 < width) {
            dest[2 * (w + 1) + 0] = src1[w + 1];
            dest[2 * (w + 1) + 1] = src2[w + 1];
        }
        if (w + 2 < width) {
            dest[2 * (w + 2) + 0] = src1[w + 2];
            dest[2 * (w + 2) + 1] = src2[w + 2];
        }
        if (w + 3 < width) {
            dest[2 * (w + 3) + 0] = src1[w + 3];
            dest[2 * (w + 3) + 1] = src2[w + 3];
        }
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
