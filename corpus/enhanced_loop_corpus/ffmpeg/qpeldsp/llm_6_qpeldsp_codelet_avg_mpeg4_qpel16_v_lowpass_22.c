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
    const int src9 = src[9 * srcStride];
    const int src10 = src[10 * srcStride];
    const int src11 = src[11 * srcStride];
    const int src12 = src[12 * srcStride];
    const int src13 = src[13 * srcStride];
    const int src14 = src[14 * srcStride];
    const int src15 = src[15 * srcStride];
    const int src16 = src[16 * srcStride];

    // Introduce temporary variables to break direct RAW dependencies and enable reordering
    const int sum01 = src0 + src1;
    const int sum12 = src1 + src2;
    const int sum23 = src2 + src3;
    const int sum34 = src3 + src4;
    const int sum45 = src4 + src5;
    const int sum56 = src5 + src6;
    const int sum67 = src6 + src7;
    const int sum78 = src7 + src8;
    const int sum89 = src8 + src9;
    const int sum9a = src9 + src10;
    const int suma_b = src10 + src11;
    const int sumb_c = src11 + src12;
    const int sumc_d = src12 + src13;
    const int sumd_e = src13 + src14;
    const int sume_f = src14 + src15;
    const int sumf_g = src15 + src16;

    // Reuse intermediate sums to create more uniform expression structure
    dst[0 * dstStride] = (((dst[0 * dstStride]) + cm[((sum01 * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5] + 1) >> 1);
    dst[1 * dstStride] = (((dst[1 * dstStride]) + cm[((sum12 * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5] + 1) >> 1);
    dst[2 * dstStride] = (((dst[2 * dstStride]) + cm[((sum23 * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5] + 1) >> 1);
    dst[3 * dstStride] = (((dst[3 * dstStride]) + cm[((sum34 * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5] + 1) >> 1);
    dst[4 * dstStride] = (((dst[4 * dstStride]) + cm[((sum45 * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 16) >> 5] + 1) >> 1);
    dst[5 * dstStride] = (((dst[5 * dstStride]) + cm[((sum56 * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src9)) + 16) >> 5] + 1) >> 1);
    dst[6 * dstStride] = (((dst[6 * dstStride]) + cm[((sum67 * 20 - (src5 + src8) * 6 + (src4 + src9) * 3 - (src3 + src10)) + 16) >> 5] + 1) >> 1);
    dst[7 * dstStride] = (((dst[7 * dstStride]) + cm[((sum78 * 20 - (src6 + src9) * 6 + (src5 + src10) * 3 - (src4 + src11)) + 16) >> 5] + 1) >> 1);
    dst[8 * dstStride] = (((dst[8 * dstStride]) + cm[((sum89 * 20 - (src7 + src10) * 6 + (src6 + src11) * 3 - (src5 + src12)) + 16) >> 5] + 1) >> 1);
    dst[9 * dstStride] = (((dst[9 * dstStride]) + cm[((sum9a * 20 - (src8 + src11) * 6 + (src7 + src12) * 3 - (src6 + src13)) + 16) >> 5] + 1) >> 1);
    dst[10 * dstStride] = (((dst[10 * dstStride]) + cm[((suma_b * 20 - (src9 + src12) * 6 + (src8 + src13) * 3 - (src7 + src14)) + 16) >> 5] + 1) >> 1);
    dst[11 * dstStride] = (((dst[11 * dstStride]) + cm[((sumb_c * 20 - (src10 + src13) * 6 + (src9 + src14) * 3 - (src8 + src15)) + 16) >> 5] + 1) >> 1);
    dst[12 * dstStride] = (((dst[12 * dstStride]) + cm[((sumc_d * 20 - (src11 + src14) * 6 + (src10 + src15) * 3 - (src9 + src16)) + 16) >> 5] + 1) >> 1);
    dst[13 * dstStride] = (((dst[13 * dstStride]) + cm[((sumd_e * 20 - (src12 + src15) * 6 + (src11 + src16) * 3 - (src10 + src16)) + 16) >> 5] + 1) >> 1);
    dst[14 * dstStride] = (((dst[14 * dstStride]) + cm[((sume_f * 20 - (src13 + src16) * 6 + (src12 + src16) * 3 - (src11 + src15)) + 16) >> 5] + 1) >> 1);
    dst[15 * dstStride] = (((dst[15 * dstStride]) + cm[((sumf_g * 20 - (src14 + src16) * 6 + (src13 + src15) * 3 - (src12 + src14)) + 16) >> 5] + 1) >> 1);

    dst++;
    src++;
}
}
