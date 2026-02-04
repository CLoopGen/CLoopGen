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
int block_h;
for (block_h = 0; block_h < height; block_h += 2) {
    int adjusted_h;
    for (adjusted_h = block_h; adjusted_h < height && adjusted_h < block_h + 2; adjusted_h++) {
        int w;
        for (w = 0; w < width; w++) {
            dest[2 * w + 0] = src1[w];
            dest[2 * w + 1] = src2[w];
        }
        dest += dstStride;
        src1 += src1Stride;
        src2 += src2Stride;
    }
}
}
