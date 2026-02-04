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
for (i = 0; i < w; i++) {
    const int srcB = *(src - 2 * srcStride);
    const int srcA = *(src - 1 * srcStride);
    const int src0 = *(src + 0 * srcStride);
    const int src1 = *(src + 1 * srcStride);
    const int src2 = *(src + 2 * srcStride);
    const int src3 = *(src + 3 * srcStride);
    const int src4 = *(src + 4 * srcStride);
    const int src5 = *(src + 5 * srcStride);
    const int src6 = *(src + 6 * srcStride);
    const int src7 = *(src + 7 * srcStride);
    const int src8 = *(src + 8 * srcStride);
    const int src9 = *(src + 9 * srcStride);
    const int src10 = *(src + 10 * srcStride);

    int coeffs[] = {0, -1, 5, 5, -1, 0};

    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((coeffs[0] * srcB + coeffs[1] * srcA + coeffs[2] * src0 + coeffs[3] * src1 + coeffs[4] * src2 + coeffs[5] * src3) + 4) >> 3] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((coeffs[0] * srcA + coeffs[1] * src0 + coeffs[2] * src1 + coeffs[3] * src2 + coeffs[4] * src3 + coeffs[5] * src4) + 4) >> 3] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((coeffs[0] * src0 + coeffs[1] * src1 + coeffs[2] * src2 + coeffs[3] * src3 + coeffs[4] * src4 + coeffs[5] * src5) + 4) >> 3] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((coeffs[0] * src1 + coeffs[1] * src2 + coeffs[2] * src3 + coeffs[3] * src4 + coeffs[4] * src5 + coeffs[5] * src6) + 4) >> 3] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((coeffs[0] * src2 + coeffs[1] * src3 + coeffs[2] * src4 + coeffs[3] * src5 + coeffs[4] * src6 + coeffs[5] * src7) + 4) >> 3] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((coeffs[0] * src3 + coeffs[1] * src4 + coeffs[2] * src5 + coeffs[3] * src6 + coeffs[4] * src7 + coeffs[5] * src8) + 4) >> 3] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((coeffs[0] * src4 + coeffs[1] * src5 + coeffs[2] * src6 + coeffs[3] * src7 + coeffs[4] * src8 + coeffs[5] * src9) + 4) >> 3] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((coeffs[0] * src5 + coeffs[1] * src6 + coeffs[2] * src7 + coeffs[3] * src8 + coeffs[4] * src9 + coeffs[5] * src10) + 4) >> 3] + 1) >> 1;

    dst += 1;
    src += 1;
}
}
