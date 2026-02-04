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
    const int8_t offsets[] = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int tmp_vals[13] = {
        tmp[offsets[0] * 8], tmp[offsets[1] * 8], tmp[offsets[2] * 8],
        tmp[offsets[3] * 8], tmp[offsets[4] * 8], tmp[offsets[5] * 8],
        tmp[offsets[6] * 8], tmp[offsets[7] * 8], tmp[offsets[8] * 8],
        tmp[offsets[9] * 8], tmp[offsets[10] * 8], tmp[offsets[11] * 8], tmp[offsets[12] * 8]
    };
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-1 * tmp_vals[0] + -2 * tmp_vals[1] + 96 * tmp_vals[2] + 42 * tmp_vals[3] + -7 * tmp_vals[4] + 0 * tmp_vals[5]) + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * tmp_vals[1] + -2 * tmp_vals[2] + 96 * tmp_vals[3] + 42 * tmp_vals[4] + -7 * tmp_vals[5] + 0 * tmp_vals[6]) + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((-1 * tmp_vals[2] + -2 * tmp_vals[3] + 96 * tmp_vals[4] + 42 * tmp_vals[5] + -7 * tmp_vals[6] + 0 * tmp_vals[7]) + 512) >> 10] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((-1 * tmp_vals[3] + -2 * tmp_vals[4] + 96 * tmp_vals[5] + 42 * tmp_vals[6] + -7 * tmp_vals[7] + 0 * tmp_vals[8]) + 512) >> 10] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((-1 * tmp_vals[4] + -2 * tmp_vals[5] + 96 * tmp_vals[6] + 42 * tmp_vals[7] + -7 * tmp_vals[8] + 0 * tmp_vals[9]) + 512) >> 10] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((-1 * tmp_vals[5] + -2 * tmp_vals[6] + 96 * tmp_vals[7] + 42 * tmp_vals[8] + -7 * tmp_vals[9] + 0 * tmp_vals[10]) + 512) >> 10] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((-1 * tmp_vals[6] + -2 * tmp_vals[7] + 96 * tmp_vals[8] + 42 * tmp_vals[9] + -7 * tmp_vals[10] + 0 * tmp_vals[11]) + 512) >> 10] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((-1 * tmp_vals[7] + -2 * tmp_vals[8] + 96 * tmp_vals[9] + 42 * tmp_vals[10] + -7 * tmp_vals[11] + 0 * tmp_vals[12]) + 512) >> 10] + 1) >> 1;
    dst++;
    tmp++;
}
}
