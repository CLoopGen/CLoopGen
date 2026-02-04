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
    uint8_t val_center = src[(0) * src_stride + 1 * (0)];
    uint8_t val_left   = src[(0) * src_stride + 1 * (-1)];
    uint8_t val_right  = src[(0) * src_stride + 1 * (1)];
    uint8_t val_top    = src[(-1) * src_stride + 1 * (0)];
    uint8_t val_bottom = src[(1) * src_stride + 1 * (0)];
    uint8_t val_tl     = src[(-1) * src_stride + 1 * (-1)];
    uint8_t val_tr     = src[(-1) * src_stride + 1 * (1)];
    uint8_t val_bl     = src[(1) * src_stride + 1 * (-1)];
    uint8_t val_br     = src[(1) * src_stride + 1 * (1)];

    dst[(0) * dst_stride + (0) * 3 + 0] = ((unsigned int)val_tl + (unsigned int)val_tr + (unsigned int)val_bl + (unsigned int)val_br) >> 2;
    dst[(0) * dst_stride + (0) * 3 + 1] = ((unsigned int)val_top + (unsigned int)val_left + (unsigned int)val_right + (unsigned int)val_bottom) >> 2;
    dst[(0) * dst_stride + (0) * 3 + 2] = val_center;
    dst[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)val_tr + (unsigned int)val_br) >> 1;
    dst[(0) * dst_stride + (1) * 3 + 1] = val_right;
    dst[(0) * dst_stride + (1) * 3 + 2] = ((unsigned int)val_center + (unsigned int)src[(0) * src_stride + 1 * (2)]) >> 1;
    dst[(1) * dst_stride + (0) * 3 + 0] = ((unsigned int)val_bl + (unsigned int)val_br) >> 1;
    dst[(1) * dst_stride + (0) * 3 + 1] = val_bottom;
    dst[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)val_center + (unsigned int)src[(2) * src_stride + 1 * (0)]) >> 1;
    dst[(1) * dst_stride + (1) * 3 + 0] = val_br;
    dst[(1) * dst_stride + (1) * 3 + 1] = ((unsigned int)val_right + (unsigned int)val_bottom + (unsigned int)src[(1) * src_stride + 1 * (2)] + (unsigned int)src[(2) * src_stride + 1 * (1)]) >> 2;
    dst[(1) * dst_stride + (1) * 3 + 2] = ((unsigned int)val_center + (unsigned int)src[(0) * src_stride + 1 * (2)] + (unsigned int)src[(2) * src_stride + 1 * (0)] + (unsigned int)src[(2) * src_stride + 1 * (2)]) >> 2;

    src += 1 * 1;
    dst += 6;
}
}
