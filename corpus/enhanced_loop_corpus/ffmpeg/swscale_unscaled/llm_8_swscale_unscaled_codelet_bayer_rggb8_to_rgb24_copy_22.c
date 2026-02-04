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
for (i = 0; i < width; i += 4) {
    dst[(0) * dst_stride + (0) * 3 + 2] = dst[(0) * dst_stride + (1) * 3 + 2] = dst[(1) * dst_stride + (1) * 3 + 2] = dst[(1) * dst_stride + (0) * 3 + 2] = (src[(1) * src_stride + 1 * (1)]) >> 0;
    dst[(0) * dst_stride + (1) * 3 + 1] = (src[(0) * src_stride + 1 * (1)]) >> 0;
    dst[(0) * dst_stride + (0) * 3 + 1] = dst[(1) * dst_stride + (1) * 3 + 1] = ((unsigned int)(src[(0) * src_stride + 1 * (1)]) + (unsigned int)(src[(1) * src_stride + 1 * (0)])) >> (1 + 0);
    dst[(1) * dst_stride + (0) * 3 + 1] = (src[(1) * src_stride + 1 * (0)]) >> 0;
    dst[(1) * dst_stride + (1) * 3 + 0] = dst[(0) * dst_stride + (0) * 3 + 0] = dst[(0) * dst_stride + (1) * 3 + 0] = dst[(1) * dst_stride + (0) * 3 + 0] = (src[(0) * src_stride + 1 * (0)]) >> 0;

    dst[(0) * dst_stride + (2) * 3 + 2] = dst[(0) * dst_stride + (3) * 3 + 2] = dst[(1) * dst_stride + (3) * 3 + 2] = dst[(1) * dst_stride + (2) * 3 + 2] = (src[(1) * src_stride + 1 * (3)]) >> 0;
    dst[(0) * dst_stride + (3) * 3 + 1] = (src[(0) * src_stride + 1 * (3)]) >> 0;
    dst[(0) * dst_stride + (2) * 3 + 1] = dst[(1) * dst_stride + (3) * 3 + 1] = ((unsigned int)(src[(0) * src_stride + 1 * (3)]) + (unsigned int)(src[(1) * src_stride + 1 * (2)])) >> (1 + 0);
    dst[(1) * dst_stride + (2) * 3 + 1] = (src[(1) * src_stride + 1 * (2)]) >> 0;
    dst[(1) * dst_stride + (3) * 3 + 0] = dst[(0) * dst_stride + (2) * 3 + 0] = dst[(0) * dst_stride + (3) * 3 + 0] = dst[(1) * dst_stride + (2) * 3 + 0] = (src[(0) * src_stride + 1 * (2)]) >> 0;

    src += 4 * 1;
    dst += 12;
}
}
