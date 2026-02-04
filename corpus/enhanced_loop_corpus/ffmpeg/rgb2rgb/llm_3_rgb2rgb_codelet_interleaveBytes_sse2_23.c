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
        int idx0 = w + 0, idx1 = w + 1, idx2 = w + 2, idx3 = w + 3;
        if (idx0 < width) {
            dest[2 * idx0 + 0] = src1[idx0];
            dest[2 * idx0 + 1] = src2[idx0];
        }
        if (idx1 < width) {
            dest[2 * idx1 + 0] = src1[idx1];
            dest[2 * idx1 + 1] = src2[idx1];
        }
        if (idx2 < width) {
            dest[2 * idx2 + 0] = src1[idx2];
            dest[2 * idx2 + 1] = src2[idx2];
        }
        if (idx3 < width) {
            dest[2 * idx3 + 0] = src1[idx3];
            dest[2 * idx3 + 1] = src2[idx3];
        }
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
