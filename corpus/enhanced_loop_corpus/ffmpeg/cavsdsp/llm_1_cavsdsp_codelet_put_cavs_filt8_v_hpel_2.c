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
        for (int k = 0; k < 2 && (i + k) < w; k++) {
            uint8_t *local_src = src + k;
            const int srcB = local_src[-2 * srcStride];
            const int srcA = local_src[-1 * srcStride];
            const int src0 = local_src[0 * srcStride];
            const int src1 = local_src[1 * srcStride];
            const int src2 = local_src[2 * srcStride];
            const int src3 = local_src[3 * srcStride];
            const int src4 = local_src[4 * srcStride];
            const int src5 = local_src[5 * srcStride];
            const int src6 = local_src[6 * srcStride];
            const int src7 = local_src[7 * srcStride];
            const int src8 = local_src[8 * srcStride];
            const int src9 = local_src[9 * srcStride];
            const int src10 = local_src[10 * srcStride];
            uint8_t *local_dst = dst + k;
            local_dst[0 * dstStride] = cm[((0 * srcB + -1 * srcA + 5 * src0 + 5 * src1 + -1 * src2 + 0 * src3) + 4) >> 3];
            local_dst[1 * dstStride] = cm[((0 * srcA + -1 * src0 + 5 * src1 + 5 * src2 + -1 * src3 + 0 * src4) + 4) >> 3];
            local_dst[2 * dstStride] = cm[((0 * src0 + -1 * src1 + 5 * src2 + 5 * src3 + -1 * src4 + 0 * src5) + 4) >> 3];
            local_dst[3 * dstStride] = cm[((0 * src1 + -1 * src2 + 5 * src3 + 5 * src4 + -1 * src5 + 0 * src6) + 4) >> 3];
            local_dst[4 * dstStride] = cm[((0 * src2 + -1 * src3 + 5 * src4 + 5 * src5 + -1 * src6 + 0 * src7) + 4) >> 3];
            local_dst[5 * dstStride] = cm[((0 * src3 + -1 * src4 + 5 * src5 + 5 * src6 + -1 * src7 + 0 * src8) + 4) >> 3];
            local_dst[6 * dstStride] = cm[((0 * src4 + -1 * src5 + 5 * src6 + 5 * src7 + -1 * src8 + 0 * src9) + 4) >> 3];
            local_dst[7 * dstStride] = cm[((0 * src5 + -1 * src6 + 5 * src7 + 5 * src8 + -1 * src9 + 0 * src10) + 4) >> 3];
        }
        dst += 2;
        src += 2;
    }
}
