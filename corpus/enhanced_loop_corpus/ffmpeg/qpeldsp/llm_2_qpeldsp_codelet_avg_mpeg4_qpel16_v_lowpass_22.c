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

        // Use consecutive memory access in cm via precomputed indices
        int indices[16];
        indices[0] = (((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5;
        indices[1] = (((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5;
        indices[2] = (((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5;
        indices[3] = (((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5;
        indices[4] = (((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 16) >> 5;
        indices[5] = (((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src9)) + 16) >> 5;
        indices[6] = (((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src9) * 3 - (src3 + src10)) + 16) >> 5;
        indices[7] = (((src7 + src8) * 20 - (src6 + src9) * 6 + (src5 + src10) * 3 - (src4 + src11)) + 16) >> 5;
        indices[8] = (((src8 + src9) * 20 - (src7 + src10) * 6 + (src6 + src11) * 3 - (src5 + src12)) + 16) >> 5;
        indices[9] = (((src9 + src10) * 20 - (src8 + src11) * 6 + (src7 + src12) * 3 - (src6 + src13)) + 16) >> 5;
        indices[10] = (((src10 + src11) * 20 - (src9 + src12) * 6 + (src8 + src13) * 3 - (src7 + src14)) + 16) >> 5;
        indices[11] = (((src11 + src12) * 20 - (src10 + src13) * 6 + (src9 + src14) * 3 - (src8 + src15)) + 16) >> 5;
        indices[12] = (((src12 + src13) * 20 - (src11 + src14) * 6 + (src10 + src15) * 3 - (src9 + src16)) + 16) >> 5;
        indices[13] = (((src13 + src14) * 20 - (src12 + src15) * 6 + (src11 + src16) * 3 - (src10 + src16)) + 16) >> 5;
        indices[14] = (((src14 + src15) * 20 - (src13 + src16) * 6 + (src12 + src16) * 3 - (src11 + src15)) + 16) >> 5;
        indices[15] = (((src15 + src16) * 20 - (src14 + src16) * 6 + (src13 + src15) * 3 - (src12 + src14)) + 16) >> 5;

        // Sequential access to dst and cm using index array
        for (int j = 0; j < 16; j++) {
            dst[j * dstStride] = ((dst[j * dstStride] + cm[indices[j]] + 1) >> 1);
        }

        dst++;
        src++;
    }
}
