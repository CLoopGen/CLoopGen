#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  uint8_t *cm;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];
    const int src5 = src[5 * srcStride];
    const int src6 = src[6 * srcStride];
    const int src7 = src[7 * srcStride];
    const int src8 = src[8 * srcStride];

    int index;
    int base_value, offset;

    if (src4 > 128) {
        base_value = src4;
        offset = 0;
    } else if (src4 < 64) {
        base_value = src0;
        offset = 4;
    } else {
        base_value = (src0 + src8) / 2;
        offset = 2;
    }

    index = (base_value + offset + 15) >> 5;

    dst[0 * dstStride] = cm[index ^ (((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) & 31)];
    dst[1 * dstStride] = cm[index ^ (((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) & 31)];
    dst[2 * dstStride] = cm[index ^ (((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) & 31)];
    dst[3 * dstStride] = cm[index ^ (((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) & 31)];
    dst[4 * dstStride] = cm[index ^ (((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) & 31)];
    dst[5 * dstStride] = cm[index ^ (((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src8)) & 31)];
    dst[6 * dstStride] = cm[index ^ (((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src8) * 3 - (src3 + src7)) & 31)];
    dst[7 * dstStride] = cm[index ^ (((src7 + src8) * 20 - (src6 + src8) * 6 + (src5 + src7) * 3 - (src4 + src6)) & 31)];

    dst++;
    src++;
}
}
