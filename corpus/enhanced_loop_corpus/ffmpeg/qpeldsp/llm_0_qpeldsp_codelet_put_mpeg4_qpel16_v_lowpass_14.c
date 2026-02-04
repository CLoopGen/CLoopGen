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



void loop() {
    for (int outer = 0; outer < w; outer += 2) {
        for (int inner = 0; inner < 2 && (outer + inner) < w; inner++) {
            const int idx = outer + inner;
            const uint8_t *s = src + idx;
            uint8_t *d = dst + idx;
            const int src0 = s[0 * srcStride];
            const int src1 = s[1 * srcStride];
            const int src2 = s[2 * srcStride];
            const int src3 = s[3 * srcStride];
            const int src4 = s[4 * srcStride];
            const int src5 = s[5 * srcStride];
            const int src6 = s[6 * srcStride];
            const int src7 = s[7 * srcStride];
            const int src8 = s[8 * srcStride];
            const int src9 = s[9 * srcStride];
            const int src10 = s[10 * srcStride];
            const int src11 = s[11 * srcStride];
            const int src12 = s[12 * srcStride];
            const int src13 = s[13 * srcStride];
            const int src14 = s[14 * srcStride];
            const int src15 = s[15 * srcStride];
            const int src16 = s[16 * srcStride];

            d[0 * dstStride] = cm[(((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5];
            d[1 * dstStride] = cm[(((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5];
            d[2 * dstStride] = cm[(((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5];
            d[3 * dstStride] = cm[(((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5];
            d[4 * dstStride] = cm[(((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 16) >> 5];
            d[5 * dstStride] = cm[(((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src9)) + 16) >> 5];
            d[6 * dstStride] = cm[(((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src9) * 3 - (src3 + src10)) + 16) >> 5];
            d[7 * dstStride] = cm[(((src7 + src8) * 20 - (src6 + src9) * 6 + (src5 + src10) * 3 - (src4 + src11)) + 16) >> 5];
            d[8 * dstStride] = cm[(((src8 + src9) * 20 - (src7 + src10) * 6 + (src6 + src11) * 3 - (src5 + src12)) + 16) >> 5];
            d[9 * dstStride] = cm[(((src9 + src10) * 20 - (src8 + src11) * 6 + (src7 + src12) * 3 - (src6 + src13)) + 16) >> 5];
            d[10 * dstStride] = cm[(((src10 + src11) * 20 - (src9 + src12) * 6 + (src8 + src13) * 3 - (src7 + src14)) + 16) >> 5];
            d[11 * dstStride] = cm[(((src11 + src12) * 20 - (src10 + src13) * 6 + (src9 + src14) * 3 - (src8 + src15)) + 16) >> 5];
            d[12 * dstStride] = cm[(((src12 + src13) * 20 - (src11 + src14) * 6 + (src10 + src15) * 3 - (src9 + src16)) + 16) >> 5];
            d[13 * dstStride] = cm[(((src13 + src14) * 20 - (src12 + src15) * 6 + (src11 + src16) * 3 - (src10 + src16)) + 16) >> 5];
            d[14 * dstStride] = cm[(((src14 + src15) * 20 - (src13 + src16) * 6 + (src12 + src16) * 3 - (src11 + src15)) + 16) >> 5];
            d[15 * dstStride] = cm[(((src15 + src16) * 20 - (src14 + src16) * 6 + (src13 + src15) * 3 - (src12 + src14)) + 16) >> 5];
        }
    }
}
