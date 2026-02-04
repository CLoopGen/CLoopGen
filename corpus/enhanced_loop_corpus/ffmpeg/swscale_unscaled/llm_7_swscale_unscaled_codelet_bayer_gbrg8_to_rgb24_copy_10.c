#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_temp = 0;
for (i = 0; i < width; i += 2) {
    uint8_t temp_src_00 = src[(0) * src_stride + 1 * (0)];
    uint8_t temp_src_11 = src[(1) * src_stride + 1 * (1)];
    uint8_t temp_src_01 = src[(0) * src_stride + 1 * (1)];

    uint8_t combined_val = ((unsigned int)temp_src_00 + (unsigned int)temp_src_11) >> 1;

    dst[(0) * dst_stride + (0) * 3 + 0] = temp_src_00;
    dst[(0) * dst_stride + (1) * 3 + 0] = temp_src_00;
    dst[(1) * dst_stride + (1) * 3 + 0] = temp_src_00;
    dst[(1) * dst_stride + (0) * 3 + 0] = temp_src_00;

    dst[(0) * dst_stride + (0) * 3 + 1] = temp_src_00;
    dst[(1) * dst_stride + (1) * 3 + 1] = temp_src_11;
    dst[(0) * dst_stride + (1) * 3 + 1] = combined_val;
    dst[(1) * dst_stride + (0) * 3 + 1] = combined_val;

    dst[(1) * dst_stride + (1) * 3 + 2] = temp_src_01;
    dst[(0) * dst_stride + (0) * 3 + 2] = temp_src_01;
    dst[(0) * dst_stride + (1) * 3 + 2] = temp_src_01;
    dst[(1) * dst_stride + (0) * 3 + 2] = temp_src_01;

    if (i > 0) {
        dst[(0) * dst_stride + (0) * 3 + 0] ^= prev_temp;
    }
    prev_temp = temp_src_00;

    src += 2 * 1;
    dst += 6;
}
}
