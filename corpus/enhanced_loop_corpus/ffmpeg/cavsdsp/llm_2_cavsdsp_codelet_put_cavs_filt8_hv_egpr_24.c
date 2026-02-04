#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Array Access with Pointer Arithmetic
    // Instead of strided access via indexing with *8, we pre-scale the tmp pointer to access elements consecutively.
    int16_t *tmp_offset = tmp - 2; // Adjust base so tmp_offset[0] corresponds to tmp[-2*8]
    for (i = 0; i < w; i++) {
        const int tmpB = tmp_offset[0];
        const int tmpA = tmp_offset[1];
        const int tmp0 = tmp_offset[2];
        const int tmp1 = tmp_offset[3];
        const int tmp2 = tmp_offset[4];
        const int tmp3 = tmp_offset[5];
        const int tmp4 = tmp_offset[6];
        const int tmp5 = tmp_offset[7];
        const int tmp6 = tmp_offset[8];
        const int tmp7 = tmp_offset[9];
        const int tmp8 = tmp_offset[10];
        const int tmp9 = tmp_offset[11];
        const int tmp10 = tmp_offset[12];

        dst[0 * dstStride] = cm[((0 * tmpB + -1 * tmpA + 5 * tmp0 + 5 * tmp1 + -1 * tmp2 + 0 * tmp3) + 64) >> 7];
        dst[1 * dstStride] = cm[((0 * tmpA + -1 * tmp0 + 5 * tmp1 + 5 * tmp2 + -1 * tmp3 + 0 * tmp4) + 64) >> 7];
        dst[2 * dstStride] = cm[((0 * tmp0 + -1 * tmp1 + 5 * tmp2 + 5 * tmp3 + -1 * tmp4 + 0 * tmp5) + 64) >> 7];
        dst[3 * dstStride] = cm[((0 * tmp1 + -1 * tmp2 + 5 * tmp3 + 5 * tmp4 + -1 * tmp5 + 0 * tmp6) + 64) >> 7];
        dst[4 * dstStride] = cm[((0 * tmp2 + -1 * tmp3 + 5 * tmp4 + 5 * tmp5 + -1 * tmp6 + 0 * tmp7) + 64) >> 7];
        dst[5 * dstStride] = cm[((0 * tmp3 + -1 * tmp4 + 5 * tmp5 + 5 * tmp6 + -1 * tmp7 + 0 * tmp8) + 64) >> 7];
        dst[6 * dstStride] = cm[((0 * tmp4 + -1 * tmp5 + 5 * tmp6 + 5 * tmp7 + -1 * tmp8 + 0 * tmp9) + 64) >> 7];
        dst[7 * dstStride] = cm[((0 * tmp5 + -1 * tmp6 + 5 * tmp7 + 5 * tmp8 + -1 * tmp9 + 0 * tmp10) + 64) >> 7];

        dst++;
        tmp_offset++;
    }
}
