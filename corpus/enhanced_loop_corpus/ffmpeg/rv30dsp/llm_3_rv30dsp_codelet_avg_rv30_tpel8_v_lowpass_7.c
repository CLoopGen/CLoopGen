#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Replace direct strided indexing with an indirect access pattern using precomputed indices.
    // This simulates irregular memory access useful in sparse or gather-style operations.

    // Precompute offset indices for src and dst based on stride
    int src_offsets[11];
    int dst_offsets[8];

    for (int j = -1; j <= 9; j++) {
        src_offsets[j + 1] = j * srcStride;
    }
    for (int j = 0; j < 8; j++) {
        dst_offsets[j] = j * dstStride;
    }

    for (i = 0; i < w; i++) {
        // Use indirect access through offsets
        const int srcA = src[src_offsets[0]];
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

        dst[dst_offsets[0]] = (((dst[dst_offsets[0]]) + cm[(-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4] + 1) >> 1);
        dst[dst_offsets[1]] = (((dst[dst_offsets[1]]) + cm[(-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4] + 1) >> 1);
        dst[dst_offsets[2]] = (((dst[dst_offsets[2]]) + cm[(-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4] + 1) >> 1);
        dst[dst_offsets[3]] = (((dst[dst_offsets[3]]) + cm[(-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4] + 1) >> 1);
        dst[dst_offsets[4]] = (((dst[dst_offsets[4]]) + cm[(-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4] + 1) >> 1);
        dst[dst_offsets[5]] = (((dst[dst_offsets[5]]) + cm[(-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4] + 1) >> 1);
        dst[dst_offsets[6]] = (((dst[dst_offsets[6]]) + cm[(-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4] + 1) >> 1);
        dst[dst_offsets[7]] = (((dst[dst_offsets[7]]) + cm[(-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4] + 1) >> 1);

        dst++;
        src++;
    }
}
