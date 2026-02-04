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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, we precompute pointers to each row and access elements consecutively
    // assuming srcStride and dstStride are multiples of element size and layout allows reindexing
    uint8_t *src_ptrs[17];
    uint8_t *dst_ptrs[16];

    for (i = 0; i < w; i++) {
        // Precompute base addresses for each offset using stride
        for (int j = 0; j < 17; j++) {
            src_ptrs[j] = &src[j * srcStride];
        }
        for (int j = 0; j < 16; j++) {
            dst_ptrs[j] = &dst[j * dstStride];
        }

        const int src0 = src_ptrs[0][0];
        const int src1 = src_ptrs[1][0];
        const int src2 = src_ptrs[2][0];
        const int src3 = src_ptrs[3][0];
        const int src4 = src_ptrs[4][0];
        const int src5 = src_ptrs[5][0];
        const int src6 = src_ptrs[6][0];
        const int src7 = src_ptrs[7][0];
        const int src8 = src_ptrs[8][0];
        const int src9 = src_ptrs[9][0];
        const int src10 = src_ptrs[10][0];
        const int src11 = src_ptrs[11][0];
        const int src12 = src_ptrs[12][0];
        const int src13 = src_ptrs[13][0];
        const int src14 = src_ptrs[14][0];
        const int src15 = src_ptrs[15][0];
        const int src16 = src_ptrs[16][0];

        dst_ptrs[0][0] = cm[(((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5];
        dst_ptrs[1][0] = cm[(((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5];
        dst_ptrs[2][0] = cm[(((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5];
        dst_ptrs[3][0] = cm[(((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5];
        dst_ptrs[4][0] = cm[(((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 16) >> 5];
        dst_ptrs[5][0] = cm[(((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src9)) + 16) >> 5];
        dst_ptrs[6][0] = cm[(((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src9) * 3 - (src3 + src10)) + 16) >> 5];
        dst_ptrs[7][0] = cm[(((src7 + src8) * 20 - (src6 + src9) * 6 + (src5 + src10) * 3 - (src4 + src11)) + 16) >> 5];
        dst_ptrs[8][0] = cm[(((src8 + src9) * 20 - (src7 + src10) * 6 + (src6 + src11) * 3 - (src5 + src12)) + 16) >> 5];
        dst_ptrs[9][0] = cm[(((src9 + src10) * 20 - (src8 + src11) * 6 + (src7 + src12) * 3 - (src6 + src13)) + 16) >> 5];
        dst_ptrs[10][0] = cm[(((src10 + src11) * 20 - (src9 + src12) * 6 + (src8 + src13) * 3 - (src7 + src14)) + 16) >> 5];
        dst_ptrs[11][0] = cm[(((src11 + src12) * 20 - (src10 + src13) * 6 + (src9 + src14) * 3 - (src8 + src15)) + 16) >> 5];
        dst_ptrs[12][0] = cm[(((src12 + src13) * 20 - (src11 + src14) * 6 + (src10 + src15) * 3 - (src9 + src16)) + 16) >> 5];
        dst_ptrs[13][0] = cm[(((src13 + src14) * 20 - (src12 + src15) * 6 + (src11 + src16) * 3 - (src10 + src16)) + 16) >> 5];
        dst_ptrs[14][0] = cm[(((src14 + src15) * 20 - (src13 + src16) * 6 + (src12 + src16) * 3 - (src11 + src15)) + 16) >> 5];
        dst_ptrs[15][0] = cm[(((src15 + src16) * 20 - (src14 + src16) * 6 + (src13 + src15) * 3 - (src12 + src14)) + 16) >> 5];

        dst++;
        src++;
    }
}
