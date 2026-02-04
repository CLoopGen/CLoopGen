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
for (i = 0; i < w; i += 2) {
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

    // Process two rows per iteration to reduce trip count and increase computational intensity
    for (int j = 0; j < 2 && (i + j) < w; j++) {
        const int offset = j * dstStride;
        const int s0 = src[j + 0 * srcStride];
        const int s1 = src[j + 1 * srcStride];
        const int s2 = src[j + 2 * srcStride];
        const int s3 = src[j + 3 * srcStride];
        const int s4 = src[j + 4 * srcStride];
        const int s5 = src[j + 5 * srcStride];
        const int s6 = src[j + 6 * srcStride];
        const int s7 = src[j + 7 * srcStride];
        const int s8 = src[j + 8 * srcStride];
        const int s9 = src[j + 9 * srcStride];
        const int s10 = src[j + 10 * srcStride];
        const int s11 = src[j + 11 * srcStride];
        const int s12 = src[j + 12 * srcStride];
        const int s13 = src[j + 13 * srcStride];
        const int s14 = src[j + 14 * srcStride];
        const int s15 = src[j + 15 * srcStride];
        const int s16 = src[j + 16 * srcStride];

        dst[offset + 0 * dstStride] = (((dst[offset + 0 * dstStride]) + cm[(((s0 + s1) * 20 - (s0 + s2) * 6 + (s1 + s3) * 3 - (s2 + s4)) + 16) >> 5] + 1) >> 1);
        dst[offset + 1 * dstStride] = (((dst[offset + 1 * dstStride]) + cm[(((s1 + s2) * 20 - (s0 + s3) * 6 + (s0 + s4) * 3 - (s1 + s5)) + 16) >> 5] + 1) >> 1);
        dst[offset + 2 * dstStride] = (((dst[offset + 2 * dstStride]) + cm[(((s2 + s3) * 20 - (s1 + s4) * 6 + (s0 + s5) * 3 - (s0 + s6)) + 16) >> 5] + 1) >> 1);
        dst[offset + 3 * dstStride] = (((dst[offset + 3 * dstStride]) + cm[(((s3 + s4) * 20 - (s2 + s5) * 6 + (s1 + s6) * 3 - (s0 + s7)) + 16) >> 5] + 1) >> 1);
        dst[offset + 4 * dstStride] = (((dst[offset + 4 * dstStride]) + cm[(((s4 + s5) * 20 - (s3 + s6) * 6 + (s2 + s7) * 3 - (s1 + s8)) + 16) >> 5] + 1) >> 1);
        dst[offset + 5 * dstStride] = (((dst[offset + 5 * dstStride]) + cm[(((s5 + s6) * 20 - (s4 + s7) * 6 + (s3 + s8) * 3 - (s2 + s9)) + 16) >> 5] + 1) >> 1);
        dst[offset + 6 * dstStride] = (((dst[offset + 6 * dstStride]) + cm[(((s6 + s7) * 20 - (s5 + s8) * 6 + (s4 + s9) * 3 - (s3 + s10)) + 16) >> 5] + 1) >> 1);
        dst[offset + 7 * dstStride] = (((dst[offset + 7 * dstStride]) + cm[(((s7 + s8) * 20 - (s6 + s9) * 6 + (s5 + s10) * 3 - (s4 + s11)) + 16) >> 5] + 1) >> 1);
        dst[offset + 8 * dstStride] = (((dst[offset + 8 * dstStride]) + cm[(((s8 + s9) * 20 - (s7 + s10) * 6 + (s6 + s11) * 3 - (s5 + s12)) + 16) >> 5] + 1) >> 1);
        dst[offset + 9 * dstStride] = (((dst[offset + 9 * dstStride]) + cm[(((s9 + s10) * 20 - (s8 + s11) * 6 + (s7 + s12) * 3 - (s6 + s13)) + 16) >> 5] + 1) >> 1);
        dst[offset + 10 * dstStride] = (((dst[offset + 10 * dstStride]) + cm[(((s10 + s11) * 20 - (s9 + s12) * 6 + (s8 + s13) * 3 - (s7 + s14)) + 16) >> 5] + 1) >> 1);
        dst[offset + 11 * dstStride] = (((dst[offset + 11 * dstStride]) + cm[(((s11 + s12) * 20 - (s10 + s13) * 6 + (s9 + s14) * 3 - (s8 + s15)) + 16) >> 5] + 1) >> 1);
        dst[offset + 12 * dstStride] = (((dst[offset + 12 * dstStride]) + cm[(((s12 + s13) * 20 - (s11 + s14) * 6 + (s10 + s15) * 3 - (s9 + s16)) + 16) >> 5] + 1) >> 1);
        dst[offset + 13 * dstStride] = (((dst[offset + 13 * dstStride]) + cm[(((s13 + s14) * 20 - (s12 + s15) * 6 + (s11 + s16) * 3 - (s10 + s16)) + 16) >> 5] + 1) >> 1);
        dst[offset + 14 * dstStride] = (((dst[offset + 14 * dstStride]) + cm[(((s14 + s15) * 20 - (s13 + s16) * 6 + (s12 + s16) * 3 - (s11 + s15)) + 16) >> 5] + 1) >> 1);
        dst[offset + 15 * dstStride] = (((dst[offset + 15 * dstStride]) + cm[(((s15 + s16) * 20 - (s14 + s16) * 6 + (s13 + s15) * 3 - (s12 + s14)) + 16) >> 5] + 1) >> 1);
    }
    dst += 2;
    src += 2;
}
}
