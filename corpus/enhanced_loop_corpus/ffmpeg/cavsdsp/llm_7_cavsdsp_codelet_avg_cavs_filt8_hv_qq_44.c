#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src2;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce data reuse by precomputing shifted pointers and batching loads
    int16_t* base_tmp = tmp - 2 * 8;
    uint8_t* base_src2 = src2;
    uint8_t* base_dst = dst;

    // Load all required tmp values in one go to eliminate repeated indexing (reduces RAW hazards)
    const int vec_tmp[13] = {
        base_tmp[0], base_tmp[1], base_tmp[2], base_tmp[3],
        base_tmp[4], base_tmp[5], base_tmp[6], base_tmp[7],
        base_tmp[8], base_tmp[9], base_tmp[10], base_tmp[11], base_tmp[12]
    };

    // Remove loop-carried dependency on dst by using only current input values
    // Also remove write-after-write (WAW) by computing all outputs before storing
    int out_val[8];

    out_val[0] = cm[((0 * vec_tmp[0] - 7 * vec_tmp[1] + 42 * vec_tmp[2] + 96 * vec_tmp[3] - 2 * vec_tmp[4] - 1 * vec_tmp[5] + 64 * base_src2[0 * srcStride]) + 512) >> 10];
    out_val[1] = cm[((0 * vec_tmp[1] - 7 * vec_tmp[2] + 42 * vec_tmp[3] + 96 * vec_tmp[4] - 2 * vec_tmp[5] - 1 * vec_tmp[6] + 64 * base_src2[1 * srcStride]) + 512) >> 10];
    out_val[2] = cm[((0 * vec_tmp[2] - 7 * vec_tmp[3] + 42 * vec_tmp[4] + 96 * vec_tmp[5] - 2 * vec_tmp[6] - 1 * vec_tmp[7] + 64 * base_src2[2 * srcStride]) + 512) >> 10];
    out_val[3] = cm[((0 * vec_tmp[3] - 7 * vec_tmp[4] + 42 * vec_tmp[5] + 96 * vec_tmp[6] - 2 * vec_tmp[7] - 1 * vec_tmp[8] + 64 * base_src2[3 * srcStride]) + 512) >> 10];
    out_val[4] = cm[((0 * vec_tmp[4] - 7 * vec_tmp[5] + 42 * vec_tmp[6] + 96 * vec_tmp[7] - 2 * vec_tmp[8] - 1 * vec_tmp[9] + 64 * base_src2[4 * srcStride]) + 512) >> 10];
    out_val[5] = cm[((0 * vec_tmp[5] - 7 * vec_tmp[6] + 42 * vec_tmp[7] + 96 * vec_tmp[8] - 2 * vec_tmp[9] - 1 * vec_tmp[10] + 64 * base_src2[5 * srcStride]) + 512) >> 10];
    out_val[6] = cm[((0 * vec_tmp[6] - 7 * vec_tmp[7] + 42 * vec_tmp[8] + 96 * vec_tmp[9] - 2 * vec_tmp[10] - 1 * vec_tmp[11] + 64 * base_src2[6 * srcStride]) + 512) >> 10];
    out_val[7] = cm[((0 * vec_tmp[7] - 7 * vec_tmp[8] + 42 * vec_tmp[9] + 96 * vec_tmp[10] - 2 * vec_tmp[11] - 1 * vec_tmp[12] + 64 * base_src2[7 * srcStride]) + 512) >> 10];

    // Batch store results after all computations to eliminate intra-iteration WAW and WAR
    for (int j = 0; j < 8; ++j) {
        base_dst[j * dstStride] = ((base_dst[j * dstStride]) + out_val[j] + 1) >> 1;
    }

    // Stride updates remain independent and non-carrying
    dst++;
    tmp++;
    src2++;
}
}
