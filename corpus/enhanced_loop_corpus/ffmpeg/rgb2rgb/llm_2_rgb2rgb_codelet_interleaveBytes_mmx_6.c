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
    uint8_t *dest_row = dest;
    uint8_t *src1_row = src1;
    uint8_t *src2_row = src2;
    for (w = 0; w < width; w++) {
        dest_row[2 * w + 0] = src1_row[w];
        dest_row[2 * w + 1] = src2_row[w];
    }
    dest += dstStride;
    src1 += src1Stride;
    src2 += src2Stride;
}
}
