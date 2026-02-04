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
for (i = 2; i < width - 2; i += 2) {
    uint8_t temp1 = src[(-1) * src_stride + 1 * (0)];
    uint8_t temp2 = src[(1) * src_stride + 1 * (0)];
    uint8_t temp3 = src[(0) * src_stride + 1 * (-1)];
    uint8_t temp4 = src[(0) * src_stride + 1 * (1)];
    uint8_t temp5 = src[(-1) * src_stride + 1 * (2)];
    uint8_t temp6 = src[(1) * src_stride + 1 * (2)];
    uint8_t temp7 = src[(-1) * src_stride + 1 * (1)];
    uint8_t temp8 = src[(0) * src_stride + 1 * (0)];
    uint8_t temp9 = src[(0) * src_stride + 1 * (2)];
    uint8_t temp10 = src[(1) * src_stride + 1 * (1)];
    uint8_t temp11 = src[(2) * src_stride + 1 * (0)];
    uint8_t temp12 = src[(2) * src_stride + 1 * (-1)];
    uint8_t temp13 = src[(2) * src_stride + 1 * (1)];

    dst[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)temp1 + (unsigned int)temp2) >> 1;
    dst[(0) * dst_stride + (0) * 3 + 1] = temp8 >> 0;
    dst[(0) * dst_stride + (0) * 3 + 0] = ((unsigned int)temp3 + (unsigned int)temp4) >> 1;
    dst[(0) * dst_stride + (1) * 3 + 2] = ((unsigned int)temp1 + (unsigned int)temp5 + (unsigned int)temp2 + (unsigned int)temp6) >> 2;
    dst[(0) * dst_stride + (1) * 3 + 1] = ((unsigned int)temp7 + (unsigned int)temp8 + (unsigned int)temp9 + (unsigned int)temp10) >> 2;
    dst[(0) * dst_stride + (1) * 3 + 0] = temp10 >> 0;
    dst[(1) * dst_stride + (0) * 3 + 2] = temp2 >> 0;
    dst[(1) * dst_stride + (0) * 3 + 1] = ((unsigned int)temp8 + (unsigned int)src[(1) * src_stride + 1 * (-1)] + (unsigned int)src[(1) * src_stride + 1 * (1)] + (unsigned int)temp11) >> 2;
    dst[(1) * dst_stride + (0) * 3 + 0] = ((unsigned int)temp3 + (unsigned int)temp4 + (unsigned int)temp12 + (unsigned int)temp13) >> 2;
    dst[(1) * dst_stride + (1) * 3 + 2] = ((unsigned int)src[(1) * src_stride + 1 * (0)] + (unsigned int)src[(1) * src_stride + 1 * (2)]) >> 1;
    dst[(1) * dst_stride + (1) * 3 + 1] = src[(1) * src_stride + 1 * (1)] >> 0;
    dst[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)src[(0) * src_stride + 1 * (1)] + (unsigned int)src[(2) * src_stride + 1 * (1)]) >> 1;

    src += 2 * 1;
    dst += 6;
}
}
