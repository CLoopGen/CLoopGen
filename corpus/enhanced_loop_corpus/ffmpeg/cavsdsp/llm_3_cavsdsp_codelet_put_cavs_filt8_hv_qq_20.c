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
    const int offset = i * 8;
    const int base_idx = 8 * 8; // Center index for sliding window access

    // Load tmp values using a fixed-offset array with consecutive indexing
    const int tmp_vals[13] = {
        tmp[offset - 2*8], tmp[offset - 1*8], tmp[offset + 0*8],
        tmp[offset + 1*8], tmp[offset + 2*8], tmp[offset + 3*8],
        tmp[offset + 4*8], tmp[offset + 5*8], tmp[offset + 6*8],
        tmp[offset + 7*8], tmp[offset + 8*8], tmp[offset + 9*8],
        tmp[offset + 10*8]
    };

    // Precompute source2 values using consecutive load
    const int src2_vals[8] = {
        ((int)(src2[0])) << 6, ((int)(src2[1])) << 6,
        ((int)(src2[2])) << 6, ((int)(src2[3])) << 6,
        ((int)(src2[4])) << 6, ((int)(src2[5])) << 6,
        ((int)(src2[6])) << 6, ((int)(src2[7])) << 6
    };

    // Use direct strided writes via computed indices
    dst[0 * dstStride] = cm[(src2_vals[0] -7*tmp_vals[1] + 42*tmp_vals[2] + 96*tmp_vals[3] -2*tmp_vals[4] -1*tmp_vals[5] + 512) >> 10];
    dst[1 * dstStride] = cm[(src2_vals[1] -7*tmp_vals[2] + 42*tmp_vals[3] + 96*tmp_vals[4] -2*tmp_vals[5] -1*tmp_vals[6] + 512) >> 10];
    dst[2 * dstStride] = cm[(src2_vals[2] -7*tmp_vals[3] + 42*tmp_vals[4] + 96*tmp_vals[5] -2*tmp_vals[6] -1*tmp_vals[7] + 512) >> 10];
    dst[3 * dstStride] = cm[(src2_vals[3] -7*tmp_vals[4] + 42*tmp_vals[5] + 96*tmp_vals[6] -2*tmp_vals[7] -1*tmp_vals[8] + 512) >> 10];
    dst[4 * dstStride] = cm[(src2_vals[4] -7*tmp_vals[5] + 42*tmp_vals[6] + 96*tmp_vals[7] -2*tmp_vals[8] -1*tmp_vals[9] + 512) >> 10];
    dst[5 * dstStride] = cm[(src2_vals[5] -7*tmp_vals[6] + 42*tmp_vals[7] + 96*tmp_vals[8] -2*tmp_vals[9] -1*tmp_vals[10] + 512) >> 10];
    dst[6 * dstStride] = cm[(src2_vals[6] -7*tmp_vals[7] + 42*tmp_vals[8] + 96*tmp_vals[9] -2*tmp_vals[10] -1*tmp_vals[11] + 512) >> 10];
    dst[7 * dstStride] = cm[(src2_vals[7] -7*tmp_vals[8] + 42*tmp_vals[9] + 96*tmp_vals[10] -2*tmp_vals[11] -1*tmp_vals[12] + 512) >> 10];

    dst++;
    tmp++;
    src2++;
}
}
