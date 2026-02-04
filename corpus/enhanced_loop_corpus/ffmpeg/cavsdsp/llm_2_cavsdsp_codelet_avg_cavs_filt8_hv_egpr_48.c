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
    const int16_t *tmp_ptr = tmp;
    const int tmp_vals[11] = {
        tmp_ptr[offsets[0] * 8], tmp_ptr[offsets[1] * 8], tmp_ptr[offsets[2] * 8],
        tmp_ptr[offsets[3] * 8], tmp_ptr[offsets[4] * 8], tmp_ptr[offsets[5] * 8],
        tmp_ptr[offsets[6] * 8], tmp_ptr[offsets[7] * 8], tmp_ptr[offsets[8] * 8],
        tmp_ptr[offsets[9] * 8], tmp_ptr[offsets[10] * 8]
    };
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0 * tmp_vals[0] + -1 * tmp_vals[1] + 5 * tmp_vals[2] + 5 * tmp_vals[3] + -1 * tmp_vals[4] + 0 * tmp_vals[5]) + 64) >> 7] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0 * tmp_vals[1] + -1 * tmp_vals[2] + 5 * tmp_vals[3] + 5 * tmp_vals[4] + -1 * tmp_vals[5] + 0 * tmp_vals[6]) + 64) >> 7] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0 * tmp_vals[2] + -1 * tmp_vals[3] + 5 * tmp_vals[4] + 5 * tmp_vals[5] + -1 * tmp_vals[6] + 0 * tmp_vals[7]) + 64) >> 7] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0 * tmp_vals[3] + -1 * tmp_vals[4] + 5 * tmp_vals[5] + 5 * tmp_vals[6] + -1 * tmp_vals[7] + 0 * tmp_vals[8]) + 64) >> 7] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0 * tmp_vals[4] + -1 * tmp_vals[5] + 5 * tmp_vals[6] + 5 * tmp_vals[7] + -1 * tmp_vals[8] + 0 * tmp_vals[9]) + 64) >> 7] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0 * tmp_vals[5] + -1 * tmp_vals[6] + 5 * tmp_vals[7] + 5 * tmp_vals[8] + -1 * tmp_vals[9] + 0 * tmp_vals[10]) + 64) >> 7] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0 * tmp_vals[6] + -1 * tmp_vals[7] + 5 * tmp_vals[8] + 5 * tmp_vals[9] + -1 * tmp_vals[10] + 0) + 64) >> 7] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0 * tmp_vals[7] + -1 * tmp_vals[8] + 5 * tmp_vals[9] + 5 * tmp_vals[10] + -1 * 0 + 0) + 64) >> 7] + 1) >> 1;
    dst++;
    tmp++;
}
}
