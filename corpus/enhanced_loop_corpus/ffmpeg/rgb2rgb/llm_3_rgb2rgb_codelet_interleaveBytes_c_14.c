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
    for (w = 0; w < width * 2; w += 2) {
        dest[w + 0] = src1[w / 2];
        dest[w + 1] = src2[w / 2];
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
