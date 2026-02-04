#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int offset = i * srcStride;
    const int src_offsets[] = {
        -srcStride, 0, srcStride, 2*srcStride, 3*srcStride,
        4*srcStride, 5*srcStride, 6*srcStride, 7*srcStride,
        8*srcStride, 9*srcStride
    };

    const int src_1 = src[src_offsets[0]];
    const int src0 = src[src_offsets[1]];
    const int src1 = src[src_offsets[2]];
    const int src2 = src[src_offsets[3]];
    const int src3 = src[src_offsets[4]];
    const int src4 = src[src_offsets[5]];
    const int src5 = src[src_offsets[6]];
    const int src6 = src[src_offsets[7]];
    const int src7 = src[src_offsets[8]];
    const int src8 = src[src_offsets[9]];
    const int src9 = src[src_offsets[10]];

    const int dst_offsets[] = {0, dstStride, 2*dstStride, 3*dstStride,
                               4*dstStride, 5*dstStride, 6*dstStride, 7*dstStride};

    const int val0 = (9 * (src0 + src1) - (src_1 + src2) + 8) >> 4;
    const int val1 = (9 * (src1 + src2) - (src0 + src3) + 8) >> 4;
    const int val2 = (9 * (src2 + src3) - (src1 + src4) + 8) >> 4;
    const int val3 = (9 * (src3 + src4) - (src2 + src5) + 8) >> 4;
    const int val4 = (9 * (src4 + src5) - (src3 + src6) + 8) >> 4;
    const int val5 = (9 * (src5 + src6) - (src4 + src7) + 8) >> 4;
    const int val6 = (9 * (src6 + src7) - (src5 + src8) + 8) >> 4;
    const int val7 = (9 * (src7 + src8) - (src6 + src9) + 8) >> 4;

    dst[dst_offsets[0]] = cm[val0];
    dst[dst_offsets[1]] = cm[val1];
    dst[dst_offsets[2]] = cm[val2];
    dst[dst_offsets[3]] = cm[val3];
    dst[dst_offsets[4]] = cm[val4];
    dst[dst_offsets[5]] = cm[val5];
    dst[dst_offsets[6]] = cm[val6];
    dst[dst_offsets[7]] = cm[val7];

    src++;
    dst++;
}
}
