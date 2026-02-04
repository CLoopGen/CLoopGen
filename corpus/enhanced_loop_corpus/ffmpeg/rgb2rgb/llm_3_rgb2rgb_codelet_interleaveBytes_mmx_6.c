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
    ptrdiff_t offset = 0;
    for (w = 0; w < width; w++, offset += 2) {
        *(dest + offset + 0) = *(src1 + w);
        *(dest + offset + 1) = *(src2 + w);
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
