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
ptrdiff_t j;
int offset_table[8] = {0, 1, 2, 3, 4, 5, 6, 7};
for (i = 0; i < w; i++) {
    const int16_t *base_tmp = tmp + offset_table[0] * 8;
    const int values[11] = {
        base_tmp[-2], base_tmp[-1],
        base_tmp[0], base_tmp[1], base_tmp[2], base_tmp[3],
        base_tmp[4], base_tmp[5], base_tmp[6], base_tmp[7], base_tmp[8]
    };
    uint8_t *dst_offsets[8];
    for (j = 0; j < 8; j++) {
        dst_offsets[j] = &dst[j * dstStride];
    }
    *dst_offsets[0] = ((*dst_offsets[0]) + cm[((0 * values[0] + -1 * values[1] + 5 * values[2] + 5 * values[3] + -1 * values[4] + 0 * values[5]) + 32) >> 6] + 1) >> 1;
    *dst_offsets[1] = ((*dst_offsets[1]) + cm[((0 * values[1] + -1 * values[2] + 5 * values[3] + 5 * values[4] + -1 * values[5] + 0 * values[6]) + 32) >> 6] + 1) >> 1;
    *dst_offsets[2] = ((*dst_offsets[2]) + cm[((0 * values[2] + -1 * values[3] + 5 * values[4] + 5 * values[5] + -1 * values[6] + 0 * values[7]) + 32) >> 6] + 1) >> 1;
    *dst_offsets[3] = ((*dst_offsets[3]) + cm[((0 * values[3] + -1 * values[4] + 5 * values[5] + 5 * values[6] + -1 * values[7] + 0 * values[8]) + 32) >> 6] + 1) >> 1;
    *dst_offsets[4] = ((*dst_offsets[4]) + cm[((0 * values[4] + -1 * values[5] + 5 * values[6] + 5 * values[7] + -1 * values[8] + 0 * values[9]) + 32) >> 6] + 1) >> 1;
    *dst_offsets[5] = ((*dst_offsets[5]) + cm[((0 * values[5] + -1 * values[6] + 5 * values[7] + 5 * values[8] + -1 * values[9] + 0 * values[10]) + 32) >> 6] + 1) >> 1;
    *dst_offsets[6] = ((*dst_offsets[6]) + cm[((0 * values[6] + -1 * values[7] + 5 * values[8] + 5 * values[9] + -1 * values[10] + 0) + 32) >> 6] + 1) >> 1;
    *dst_offsets[7] = ((*dst_offsets[7]) + cm[((0 * values[7] + -1 * values[8] + 5 * values[9] + 5 * values[10] + -1 * 0 + 0) + 32) >> 6] + 1) >> 1;
    dst++;
    tmp++;
}
}
