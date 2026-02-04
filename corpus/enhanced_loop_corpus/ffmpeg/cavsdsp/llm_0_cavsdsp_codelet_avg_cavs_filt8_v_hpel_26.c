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
for (int outer = 0; outer < w; outer += 4) {
    for (int inner = 0; inner < 4 && (outer + inner) < w; inner++) {
        const int i = outer + inner;
        uint8_t *src_i = src + i;
        uint8_t *dst_i = dst + i;
        const int srcB = src_i[-2 * srcStride];
        const int srcA = src_i[-1 * srcStride];
        const int src0 = src_i[0 * srcStride];
        const int src1 = src_i[1 * srcStride];
        const int src2 = src_i[2 * srcStride];
        const int src3 = src_i[3 * srcStride];
        const int src4 = src_i[4 * srcStride];
        const int src5 = src_i[5 * srcStride];
        const int src6 = src_i[6 * srcStride];
        const int src7 = src_i[7 * srcStride];
        const int src8 = src_i[8 * srcStride];
        const int src9 = src_i[9 * srcStride];
        const int src10 = src_i[10 * srcStride];
        dst_i[0 * dstStride] = ((dst_i[0 * dstStride]) + cm[((0 * srcB + -1 * srcA + 5 * src0 + 5 * src1 + -1 * src2 + 0 * src3) + 4) >> 3] + 1) >> 1;
        dst_i[1 * dstStride] = ((dst_i[1 * dstStride]) + cm[((0 * srcA + -1 * src0 + 5 * src1 + 5 * src2 + -1 * src3 + 0 * src4) + 4) >> 3] + 1) >> 1;
        dst_i[2 * dstStride] = ((dst_i[2 * dstStride]) + cm[((0 * src0 + -1 * src1 + 5 * src2 + 5 * src3 + -1 * src4 + 0 * src5) + 4) >> 3] + 1) >> 1;
        dst_i[3 * dstStride] = ((dst_i[3 * dstStride]) + cm[((0 * src1 + -1 * src2 + 5 * src3 + 5 * src4 + -1 * src5 + 0 * src6) + 4) >> 3] + 1) >> 1;
        dst_i[4 * dstStride] = ((dst_i[4 * dstStride]) + cm[((0 * src2 + -1 * src3 + 5 * src4 + 5 * src5 + -1 * src6 + 0 * src7) + 4) >> 3] + 1) >> 1;
        dst_i[5 * dstStride] = ((dst_i[5 * dstStride]) + cm[((0 * src3 + -1 * src4 + 5 * src5 + 5 * src6 + -1 * src7 + 0 * src8) + 4) >> 3] + 1) >> 1;
        dst_i[6 * dstStride] = ((dst_i[6 * dstStride]) + cm[((0 * src4 + -1 * src5 + 5 * src6 + 5 * src7 + -1 * src8 + 0 * src9) + 4) >> 3] + 1) >> 1;
        dst_i[7 * dstStride] = ((dst_i[7 * dstStride]) + cm[((0 * src5 + -1 * src6 + 5 * src7 + 5 * src8 + -1 * src9 + 0 * src10) + 4) >> 3] + 1) >> 1;
    }
}
}
