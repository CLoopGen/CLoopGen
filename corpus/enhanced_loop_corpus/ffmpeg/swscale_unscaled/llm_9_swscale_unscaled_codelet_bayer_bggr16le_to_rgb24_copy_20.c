#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < width; i += 1) {
    uint16_t src_val_00 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t src_val_01 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
    uint16_t src_val_10 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
    uint16_t src_val_11 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;

    uint8_t c0 = src_val_11 >> 8;
    uint8_t c1 = src_val_01 >> 8;
    uint8_t c2 = src_val_10 >> 8;
    uint8_t c3 = (unsigned int)(src_val_01 + src_val_10) >> (1 + 8);
    uint8_t c4 = src_val_00 >> 8;

    dst[(0) * dst_stride + (0) * 3 + 0] = c0;
    dst[(0) * dst_stride + (1) * 3 + 0] = c0;
    dst[(1) * dst_stride + (1) * 3 + 0] = c0;
    dst[(1) * dst_stride + (0) * 3 + 0] = c0;

    dst[(0) * dst_stride + (1) * 3 + 1] = c1;

    dst[(0) * dst_stride + (0) * 3 + 1] = c3;
    dst[(1) * dst_stride + (1) * 3 + 1] = c3;

    dst[(1) * dst_stride + (0) * 3 + 1] = c2;

    dst[(1) * dst_stride + (1) * 3 + 2] = c4;
    dst[(0) * dst_stride + (0) * 3 + 2] = c4;
    dst[(0) * dst_stride + (1) * 3 + 2] = c4;
    dst[(1) * dst_stride + (0) * 3 + 2] = c4;

    src += 2;
    dst += 3;
}
}
