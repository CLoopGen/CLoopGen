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



void loop(){
for (i = 0; i < w; i++) {
    const int16_t *tmp_offset = &tmp[0];
    const int tmp_vals[11] = {
        tmp_offset[-2 * 8], tmp_offset[-1 * 8], tmp_offset[0 * 8],
        tmp_offset[1 * 8], tmp_offset[2 * 8], tmp_offset[3 * 8],
        tmp_offset[4 * 8], tmp_offset[5 * 8], tmp_offset[6 * 8],
        tmp_offset[7 * 8], tmp_offset[8 * 8]
    };
    dst[0 * dstStride] = cm[((0 * tmp_vals[0] + -1 * tmp_vals[1] + 5 * tmp_vals[2] + 5 * tmp_vals[3] + -1 * tmp_vals[4] + 0 * tmp_vals[5]) + 32) >> 6];
    dst[1 * dstStride] = cm[((0 * tmp_vals[1] + -1 * tmp_vals[2] + 5 * tmp_vals[3] + 5 * tmp_vals[4] + -1 * tmp_vals[5] + 0 * tmp_vals[6]) + 32) >> 6];
    dst[2 * dstStride] = cm[((0 * tmp_vals[2] + -1 * tmp_vals[3] + 5 * tmp_vals[4] + 5 * tmp_vals[5] + -1 * tmp_vals[6] + 0 * tmp_vals[7]) + 32) >> 6];
    dst[3 * dstStride] = cm[((0 * tmp_vals[3] + -1 * tmp_vals[4] + 5 * tmp_vals[5] + 5 * tmp_vals[6] + -1 * tmp_vals[7] + 0 * tmp_vals[8]) + 32) >> 6];
    dst[4 * dstStride] = cm[((0 * tmp_vals[4] + -1 * tmp_vals[5] + 5 * tmp_vals[6] + 5 * tmp_vals[7] + -1 * tmp_vals[8] + 0 * tmp_vals[9]) + 32) >> 6];
    dst[5 * dstStride] = cm[((0 * tmp_vals[5] + -1 * tmp_vals[6] + 5 * tmp_vals[7] + 5 * tmp_vals[8] + -1 * tmp_vals[9] + 0 * tmp_vals[10]) + 32) >> 6];
    dst[6 * dstStride] = cm[((0 * tmp_vals[6] + -1 * tmp_vals[7] + 5 * tmp_vals[8] + 5 * tmp_vals[9] + -1 * tmp_vals[10]) + 32) >> 6];
    int temp9 = tmp[9 * 8], temp10 = tmp[10 * 8];
    dst[7 * dstStride] = cm[((0 * tmp_vals[7] + -1 * tmp_vals[8] + 5 * tmp_vals[9] + 5 * tmp_vals[10] + -1 * temp9 + 0 * temp10) + 32) >> 6];
    dst++;
    tmp++;
}
}
