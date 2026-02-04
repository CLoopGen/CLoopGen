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
    for (i = 0; i < w; i++) {
        // Unroll with strided pointer arithmetic instead of indexing
        uint8_t *s = src;
        uint8_t *d = dst;

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

        // Modify memory access pattern: use intermediate variables and reorder computation
        // to encourage compiler to schedule loads earlier and exploit memory-level parallelism

        int sum0 = (src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4);
        int sum1 = (src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5);
        int sum2 = (src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6);
        int sum3 = (src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7);
        int sum4 = (src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8);
        int sum5 = (src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src9);
        int sum6 = (src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src9) * 3 - (src3 + src10);
        int sum7 = (src7 + src8) * 20 - (src6 + src9) * 6 + (src5 + src10) * 3 - (src4 + src11);
        int sum8 = (src8 + src9) * 20 - (src7 + src10) * 6 + (src6 + src11) * 3 - (src5 + src12);
        int sum9 = (src9 + src10) * 20 - (src8 + src11) * 6 + (src7 + src12) * 3 - (src6 + src13);
        int sum10 = (src10 + src11) * 20 - (src9 + src12) * 6 + (src8 + src13) * 3 - (src7 + src14);
        int sum11 = (src11 + src12) * 20 - (src10 + src13) * 6 + (src9 + src14) * 3 - (src8 + src15);
        int sum12 = (src12 + src13) * 20 - (src11 + src14) * 6 + (src10 + src15) * 3 - (src9 + src16);
        int sum13 = (src13 + src14) * 20 - (src12 + src15) * 6 + (src11 + src16) * 3 - (src10 + src16);
        int sum14 = (src14 + src15) * 20 - (src13 + src16) * 6 + (src12 + src16) * 3 - (src11 + src15);
        int sum15 = (src15 + src16) * 20 - (src14 + src16) * 6 + (src13 + src15) * 3 - (src12 + src14);

        d[0 * dstStride] = ((d[0 * dstStride] + cm[(sum0 + 16) >> 5] + 1) >> 1);
        d[1 * dstStride] = ((d[1 * dstStride] + cm[(sum1 + 16) >> 5] + 1) >> 1);
        d[2 * dstStride] = ((d[2 * dstStride] + cm[(sum2 + 16) >> 5] + 1) >> 1);
        d[3 * dstStride] = ((d[3 * dstStride] + cm[(sum3 + 16) >> 5] + 1) >> 1);
        d[4 * dstStride] = ((d[4 * dstStride] + cm[(sum4 + 16) >> 5] + 1) >> 1);
        d[5 * dstStride] = ((d[5 * dstStride] + cm[(sum5 + 16) >> 5] + 1) >> 1);
        d[6 * dstStride] = ((d[6 * dstStride] + cm[(sum6 + 16) >> 5] + 1) >> 1);
        d[7 * dstStride] = ((d[7 * dstStride] + cm[(sum7 + 16) >> 5] + 1) >> 1);
        d[8 * dstStride] = ((d[8 * dstStride] + cm[(sum8 + 16) >> 5] + 1) >> 1);
        d[9 * dstStride] = ((d[9 * dstStride] + cm[(sum9 + 16) >> 5] + 1) >> 1);
        d[10 * dstStride] = ((d[10 * dstStride] + cm[(sum10 + 16) >> 5] + 1) >> 1);
        d[11 * dstStride] = ((d[11 * dstStride] + cm[(sum11 + 16) >> 5] + 1) >> 1);
        d[12 * dstStride] = ((d[12 * dstStride] + cm[(sum12 + 16) >> 5] + 1) >> 1);
        d[13 * dstStride] = ((d[13 * dstStride] + cm[(sum13 + 16) >> 5] + 1) >> 1);
        d[14 * dstStride] = ((d[14 * dstStride] + cm[(sum14 + 16) >> 5] + 1) >> 1);
        d[15 * dstStride] = ((d[15 * dstStride] + cm[(sum15 + 16) >> 5] + 1) >> 1);

        dst++;
        src++;
    }
}
