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
for (i = 2; i < width - 2; i += 1) {
    uint8_t s_m1_0 = src[(-1) * src_stride + 1 * (0)];
    uint8_t s_0_0 = src[(0) * src_stride + 1 * (0)];
    uint8_t s_1_0 = src[(1) * src_stride + 1 * (0)];
    uint8_t s_2_0 = src[(2) * src_stride + 1 * (0)];
    uint8_t s_0_m1 = src[(0) * src_stride + 1 * (-1)];
    uint8_t s_0_1 = src[(0) * src_stride + 1 * (1)];
    uint8_t s_1_m1 = src[(1) * src_stride + 1 * (-1)];
    uint8_t s_1_1 = src[(1) * src_stride + 1 * (1)];
    uint8_t s_m1_2 = src[(-1) * src_stride + 1 * (2)];
    uint8_t s_1_2 = src[(1) * src_stride + 1 * (2)];
    uint8_t s_m1_1 = src[(-1) * src_stride + 1 * (1)];
    uint8_t s_0_2 = src[(0) * src_stride + 1 * (2)];
    uint8_t s_2_m1 = src[(2) * src_stride + 1 * (-1)];
    uint8_t s_2_1 = src[(2) * src_stride + 1 * (1)];

    unsigned int avg00 = ((unsigned int)s_m1_0 + (unsigned int)s_1_0) >> 1;
    unsigned int avg02 = ((unsigned int)s_0_m1 + (unsigned int)s_0_1) >> 1;
    unsigned int avg10 = (s_0_0 + s_m1_2 + s_1_0 + s_1_2) >> 2;
    unsigned int avg11 = (s_m1_1 + s_0_0 + s_0_2 + s_1_1) >> 2;
    unsigned int avg20 = (s_1_0 + s_1_2) >> 1;
    unsigned int avg22 = (s_0_1 + s_2_1) >> 1;
    unsigned int avg30 = (s_0_0 + s_1_m1 + s_1_1 + s_2_0) >> 2;
    unsigned int avg32 = (s_0_m1 + s_0_1 + s_2_m1 + s_2_1) >> 2;

    dst[(0) * dst_stride + (0) * 3 + 0] = avg00;
    dst[(0) * dst_stride + (0) * 3 + 1] = s_0_0;
    dst[(0) * dst_stride + (0) * 3 + 2] = avg02;
    dst[(0) * dst_stride + (1) * 3 + 0] = avg10;
    dst[(0) * dst_stride + (1) * 3 + 1] = avg11;
    dst[(0) * dst_stride + (1) * 3 + 2] = s_0_1;
    dst[(1) * dst_stride + (0) * 3 + 0] = s_1_0;
    dst[(1) * dst_stride + (0) * 3 + 1] = avg30;
    dst[(1) * dst_stride + (0) * 3 + 2] = avg32;
    dst[(1) * dst_stride + (1) * 3 + 0] = avg20;
    dst[(1) * dst_stride + (1) * 3 + 1] = s_1_1;
    dst[(1) * dst_stride + (1) * 3 + 2] = avg22;

    src += 1 * 1;
    dst += 3;
}
}
