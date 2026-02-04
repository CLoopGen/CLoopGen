#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w; i += 2) { // Outer loop now processes two iterations at a time
        for (int k = 0; k < 2 && (i + k) < w; k++) { // Inner loop handles individual element updates with bounds check
            const int offset = i + k;
            uint8_t *local_src = src + offset;
            uint8_t *local_dst = dst + offset;

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

            local_dst[0 * dstStride] = (((local_dst[0 * dstStride]) + cm[(srcB + src3 - 5 * (srcA + src2) + src0 * C1 + src1 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
            local_dst[1 * dstStride] = (((local_dst[1 * dstStride]) + cm[(srcA + src4 - 5 * (src0 + src3) + src1 * C1 + src2 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
            local_dst[2 * dstStride] = (((local_dst[2 * dstStride]) + cm[(src0 + src5 - 5 * (src1 + src4) + src2 * C1 + src3 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
            local_dst[3 * dstStride] = (((local_dst[3 * dstStride]) + cm[(src1 + src6 - 5 * (src2 + src5) + src3 * C1 + src4 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
            local_dst[4 * dstStride] = (((local_dst[4 * dstStride]) + cm[(src2 + src7 - 5 * (src3 + src6) + src4 * C1 + src5 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
            local_dst[5 * dstStride] = (((local_dst[5 * dstStride]) + cm[(src3 + src8 - 5 * (src4 + src7) + src5 * C1 + src6 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
            local_dst[6 * dstStride] = (((local_dst[6 * dstStride]) + cm[(src4 + src9 - 5 * (src5 + src8) + src6 * C1 + src7 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
            local_dst[7 * dstStride] = (((local_dst[7 * dstStride]) + cm[(src5 + src10 - 5 * (src6 + src9) + src7 * C1 + src8 * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        }
    }
}
