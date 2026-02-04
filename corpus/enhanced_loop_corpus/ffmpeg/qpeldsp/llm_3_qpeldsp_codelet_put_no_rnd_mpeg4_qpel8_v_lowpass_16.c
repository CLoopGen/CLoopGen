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
const uint8_t *src_base = src;
uint8_t *dst_base = dst;
for (i = 0; i < w; i++) {
    const int src0 = src_base[i + 0 * srcStride];
    const int src1 = src_base[i + 1 * srcStride];
    const int src2 = src_base[i + 2 * srcStride];
    const int src3 = src_base[i + 3 * srcStride];
    const int src4 = src_base[i + 4 * srcStride];
    const int src5 = src_base[i + 5 * srcStride];
    const int src6 = src_base[i + 6 * srcStride];
    const int src7 = src_base[i + 7 * srcStride];
    const int src8 = src_base[i + 8 * srcStride];
    dst_base[i + 0 * dstStride] = cm[(((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 15) >> 5];
    dst_base[i + 1 * dstStride] = cm[(((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 15) >> 5];
    dst_base[i + 2 * dstStride] = cm[(((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 15) >> 5];
    dst_base[i + 3 * dstStride] = cm[(((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 15) >> 5];
    dst_base[i + 4 * dstStride] = cm[(((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 15) >> 5];
    dst_base[i + 5 * dstStride] = cm[(((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src8)) + 15) >> 5];
    dst_base[i + 6 * dstStride] = cm[(((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src8) * 3 - (src3 + src7)) + 15) >> 5];
    dst_base[i + 7 * dstStride] = cm[(((src7 + src8) * 20 - (src6 + src8) * 6 + (src5 + src7) * 3 - (src4 + src6)) + 15) >> 5];
}
}
