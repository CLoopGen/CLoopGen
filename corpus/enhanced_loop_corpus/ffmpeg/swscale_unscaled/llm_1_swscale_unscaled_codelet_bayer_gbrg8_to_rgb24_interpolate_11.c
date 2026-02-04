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
for (i = 2; i < width - 2; i += 4) {
    for (int k = 0; k < 2 && (i + 2*k) < width - 2; ++k) {
        int offset_i = 2 * k;
        uint8_t* local_src = src + offset_i * 1;
        uint8_t* local_dst = dst + offset_i * 3;

        local_dst[(0) * dst_stride + (0) * 3 + 0] = ((unsigned int)(local_src[(-1) * src_stride + 1 * (0)]) + (unsigned int)(local_src[(1) * src_stride + 1 * (0)])) >> (1 + 0);
        local_dst[(0) * dst_stride + (0) * 3 + 1] = (local_src[(0) * src_stride + 1 * (0)]) >> 0;
        local_dst[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)(local_src[(0) * src_stride + 1 * (-1)]) + (unsigned int)(local_src[(0) * src_stride + 1 * (1)])) >> (1 + 0);
        local_dst[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)(local_src[(-1) * src_stride + 1 * (0)]) + (unsigned int)(local_src[(-1) * src_stride + 1 * (2)]) + (unsigned int)(local_src[(1) * src_stride + 1 * (0)]) + (unsigned int)(local_src[(1) * src_stride + 1 * (2)])) >> (2 + 0);
        local_dst[(0) * dst_stride + (1) * 3 + 1] = ((unsigned int)(local_src[(-1) * src_stride + 1 * (1)]) + (unsigned int)(local_src[(0) * src_stride + 1 * (0)]) + (unsigned int)(local_src[(0) * src_stride + 1 * (2)]) + (unsigned int)(local_src[(1) * src_stride + 1 * (1)])) >> (2 + 0);
        local_dst[(0) * dst_stride + (1) * 3 + 2] = (local_src[(0) * src_stride + 1 * (1)]) >> 0;
        local_dst[(1) * dst_stride + (0) * 3 + 0] = (local_src[(1) * src_stride + 1 * (0)]) >> 0;
        local_dst[(1) * dst_stride + (0) * 3 + 1] = ((unsigned int)(local_src[(0) * src_stride + 1 * (0)]) + (unsigned int)(local_src[(1) * src_stride + 1 * (-1)]) + (unsigned int)(local_src[(1) * src_stride + 1 * (1)]) + (unsigned int)(local_src[(2) * src_stride + 1 * (0)])) >> (2 + 0);
        local_dst[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)(local_src[(0) * src_stride + 1 * (-1)]) + (unsigned int)(local_src[(0) * src_stride + 1 * (1)]) + (unsigned int)(local_src[(2) * src_stride + 1 * (-1)]) + (unsigned int)(local_src[(2) * src_stride + 1 * (1)])) >> (2 + 0);
        local_dst[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)(local_src[(1) * src_stride + 1 * (0)]) + (unsigned int)(local_src[(1) * src_stride + 1 * (2)])) >> (1 + 0);
        local_dst[(1) * dst_stride + (1) * 3 + 1] = (local_src[(1) * src_stride + 1 * (1)]) >> 0;
        local_dst[(1) * dst_stride + (1) * 3 + 2] = ((unsigned int)(local_src[(0) * src_stride + 1 * (1)]) + (unsigned int)(local_src[(2) * src_stride + 1 * (1)])) >> (1 + 0);
    }
    src += 4 * 1;
    dst += 12;
}
}
