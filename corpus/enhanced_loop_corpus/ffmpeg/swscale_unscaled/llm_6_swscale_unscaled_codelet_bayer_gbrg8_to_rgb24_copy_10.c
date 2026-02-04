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
for (i = 0; i < width; i += 2) {
    uint8_t temp1 = src[(0) * src_stride + 1 * (0)];
    uint8_t temp2 = src[(1) * src_stride + 1 * (1)];
    uint8_t temp3 = src[(0) * src_stride + 1 * (1)];

    dst[(0) * dst_stride + (0) * 3 + 0] = temp1;
    dst[(0) * dst_stride + (1) * 3 + 0] = temp1;
    dst[(1) * dst_stride + (1) * 3 + 0] = temp1;
    dst[(1) * dst_stride + (0) * 3 + 0] = temp1;

    dst[(0) * dst_stride + (0) * 3 + 1] = temp1;
    dst[(1) * dst_stride + (1) * 3 + 1] = temp2;
    dst[(0) * dst_stride + (1) * 3 + 1] = ((unsigned int)temp1 + (unsigned int)temp2) >> 1;
    dst[(1) * dst_stride + (0) * 3 + 1] = ((unsigned int)temp1 + (unsigned int)temp2) >> 1;

    dst[(1) * dst_stride + (1) * 3 + 2] = temp3;
    dst[(0) * dst_stride + (0) * 3 + 2] = temp3;
    dst[(0) * dst_stride + (1) * 3 + 2] = temp3;
    dst[(1) * dst_stride + (0) * 3 + 2] = temp3;

    src += 2 * 1;
    dst += 6;
}
}
