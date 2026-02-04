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
    uint8_t temp_center = src[(1) * src_stride + 1 * (1)];
    uint8_t temp_left   = src[(0) * src_stride + 1 * (1)];
    uint8_t temp_right  = src[(1) * src_stride + 1 * (0)];
    uint8_t temp_corner = src[(0) * src_stride + 1 * (0)];

    uint8_t smoothed_center = (temp_center + prev_temp) >> 1;

    dst[(0) * dst_stride + (0) * 3 + 0] = smoothed_center;
    dst[(0) * dst_stride + (1) * 3 + 0] = smoothed_center;
    dst[(1) * dst_stride + (1) * 3 + 0] = smoothed_center;
    dst[(1) * dst_stride + (0) * 3 + 0] = smoothed_center;

    dst[(0) * dst_stride + (1) * 3 + 1] = temp_left;

    uint8_t avg_val = ((unsigned int)temp_left + (unsigned int)temp_right) >> 1;
    dst[(0) * dst_stride + (0) * 3 + 1] = avg_val;
    dst[(1) * dst_stride + (1) * 3 + 1] = avg_val;

    dst[(1) * dst_stride + (0) * 3 + 1] = temp_right;

    dst[(1) * dst_stride + (1) * 3 + 2] = temp_corner;
    dst[(0) * dst_stride + (0) * 3 + 2] = temp_corner;
    dst[(0) * dst_stride + (1) * 3 + 2] = temp_corner;
    dst[(1) * dst_stride + (0) * 3 + 2] = temp_corner;

    prev_temp = temp_center;

    src += 2 * 1;
    dst += 6;
}
}
