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
    for (int outer = 0; outer < w; outer += 2) {
        for (int inner = 0; inner < 2 && (outer + inner) < w; inner++) {
            const int i_offset = outer + inner;
            uint8_t *src_temp = src + i_offset;
            uint8_t *dst_temp = dst + i_offset;

            const int src0 = src_temp[0 * srcStride];
            const int src1 = src_temp[1 * srcStride];
            const int src2 = src_temp[2 * srcStride];
            const int src3 = src_temp[3 * srcStride];
            const int src4 = src_temp[4 * srcStride];
            const int src5 = src_temp[5 * srcStride];
            const int src6 = src_temp[6 * srcStride];
            const int src7 = src_temp[7 * srcStride];
            const int src8 = src_temp[8 * srcStride];

            dst_temp[0 * dstStride] = cm[(((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5];
            dst_temp[1 * dstStride] = cm[(((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5];
            dst_temp[2 * dstStride] = cm[(((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5];
            dst_temp[3 * dstStride] = cm[(((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5];
            dst_temp[4 * dstStride] = cm[(((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 16) >> 5];
            dst_temp[5 * dstStride] = cm[(((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src8)) + 16) >> 5];
            dst_temp[6 * dstStride] = cm[(((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src8) * 3 - (src3 + src7)) + 16) >> 5];
            dst_temp[7 * dstStride] = cm[(((src7 + src8) * 20 - (src6 + src8) * 6 + (src5 + src7) * 3 - (src4 + src6)) + 16) >> 5];
        }
    }
}
