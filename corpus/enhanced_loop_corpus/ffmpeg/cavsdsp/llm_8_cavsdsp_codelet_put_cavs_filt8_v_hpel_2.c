#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i += 2) {
    const int srcB0 = src[-2 * srcStride];
    const int srcA0 = src[-1 * srcStride];
    const int src00 = src[0 * srcStride];
    const int src10 = src[1 * srcStride];
    const int src20 = src[2 * srcStride];
    const int src30 = src[3 * srcStride];
    const int src40 = src[4 * srcStride];
    const int src50 = src[5 * srcStride];
    const int src60 = src[6 * srcStride];
    const int src70 = src[7 * srcStride];
    const int src80 = src[8 * srcStride];
    const int src90 = src[9 * srcStride];
    const int src100 = src[10 * srcStride];

    const int srcB1 = src[1 - 2 * srcStride];
    const int srcA1 = src[1 - 1 * srcStride];
    const int src01 = src[1 + 0 * srcStride];
    const int src11 = src[1 + 1 * srcStride];
    const int src21 = src[1 + 2 * srcStride];
    const int src31 = src[1 + 3 * srcStride];
    const int src41 = src[1 + 4 * srcStride];
    const int src51 = src[1 + 5 * srcStride];
    const int src61 = src[1 + 6 * srcStride];
    const int src71 = src[1 + 7 * srcStride];
    const int src81 = src[1 + 8 * srcStride];
    const int src91 = src[1 + 9 * srcStride];
    const int src101 = src[1 + 10 * srcStride];

    dst[0 * dstStride] = cm[((0 * srcB0 + -1 * srcA0 + 5 * src00 + 5 * src10 + -1 * src20 + 0 * src30) + 4) >> 3];
    dst[1 * dstStride] = cm[((0 * srcA0 + -1 * src00 + 5 * src10 + 5 * src20 + -1 * src30 + 0 * src40) + 4) >> 3];
    dst[2 * dstStride] = cm[((0 * src00 + -1 * src10 + 5 * src20 + 5 * src30 + -1 * src40 + 0 * src50) + 4) >> 3];
    dst[3 * dstStride] = cm[((0 * src10 + -1 * src20 + 5 * src30 + 5 * src40 + -1 * src50 + 0 * src60) + 4) >> 3];
    dst[4 * dstStride] = cm[((0 * src20 + -1 * src30 + 5 * src40 + 5 * src50 + -1 * src60 + 0 * src70) + 4) >> 3];
    dst[5 * dstStride] = cm[((0 * src30 + -1 * src40 + 5 * src50 + 5 * src60 + -1 * src70 + 0 * src80) + 4) >> 3];
    dst[6 * dstStride] = cm[((0 * src40 + -1 * src50 + 5 * src60 + 5 * src70 + -1 * src80 + 0 * src90) + 4) >> 3];
    dst[7 * dstStride] = cm[((0 * src50 + -1 * src60 + 5 * src70 + 5 * src80 + -1 * src90 + 0 * src100) + 4) >> 3];

    dst[8 * dstStride] = cm[((0 * srcB1 + -1 * srcA1 + 5 * src01 + 5 * src11 + -1 * src21 + 0 * src31) + 4) >> 3];
    dst[9 * dstStride] = cm[((0 * srcA1 + -1 * src01 + 5 * src11 + 5 * src21 + -1 * src31 + 0 * src41) + 4) >> 3];
    dst[10 * dstStride] = cm[((0 * src01 + -1 * src11 + 5 * src21 + 5 * src31 + -1 * src41 + 0 * src51) + 4) >> 3];
    dst[11 * dstStride] = cm[((0 * src11 + -1 * src21 + 5 * src31 + 5 * src41 + -1 * src51 + 0 * src61) + 4) >> 3];
    dst[12 * dstStride] = cm[((0 * src21 + -1 * src31 + 5 * src41 + 5 * src51 + -1 * src61 + 0 * src71) + 4) >> 3];
    dst[13 * dstStride] = cm[((0 * src31 + -1 * src41 + 5 * src51 + 5 * src61 + -1 * src71 + 0 * src81) + 4) >> 3];
    dst[14 * dstStride] = cm[((0 * src41 + -1 * src51 + 5 * src61 + 5 * src71 + -1 * src81 + 0 * src91) + 4) >> 3];
    dst[15 * dstStride] = cm[((0 * src51 + -1 * src61 + 5 * src71 + 5 * src81 + -1 * src91 + 0 * src101) + 4) >> 3];

    dst += 2;
    src += 2;
}
}
