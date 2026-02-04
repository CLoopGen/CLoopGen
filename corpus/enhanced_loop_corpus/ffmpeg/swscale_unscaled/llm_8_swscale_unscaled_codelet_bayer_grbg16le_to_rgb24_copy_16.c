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
for (i = 0; i < width; i += 4) {
    uint16_t val_00 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t val_01 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
    uint16_t val_10 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
    uint16_t val_11 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;

    uint8_t avg_h = ((unsigned int)val_00 + val_11) >> 9;
    uint8_t avg_v = ((unsigned int)val_01 + val_10) >> 9;

    dst[(0) * dst_stride + (0) * 3 + 2] = dst[(0) * dst_stride + (1) * 3 + 2] = 
    dst[(1) * dst_stride + (1) * 3 + 2] = dst[(1) * dst_stride + (0) * 3 + 2] = val_10 >> 8;

    dst[(0) * dst_stride + (0) * 3 + 1] = val_00 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 1] = val_11 >> 8;
    dst[(0) * dst_stride + (1) * 3 + 1] = dst[(1) * dst_stride + (0) * 3 + 1] = avg_h;

    dst[(1) * dst_stride + (1) * 3 + 0] = dst[(0) * dst_stride + (0) * 3 + 0] = 
    dst[(0) * dst_stride + (1) * 3 + 0] = dst[(1) * dst_stride + (0) * 3 + 0] = val_01 >> 8;

    src += 2 * 2;
    dst += 6;

    if (i + 2 >= width) break;

    val_00 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    val_01 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
    val_10 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
    val_11 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;

    avg_h = ((unsigned int)val_00 + val_11) >> 9;
    avg_v = ((unsigned int)val_01 + val_10) >> 9;

    dst[(0) * dst_stride + (0) * 3 + 2] = dst[(0) * dst_stride + (1) * 3 + 2] = 
    dst[(1) * dst_stride + (1) * 3 + 2] = dst[(1) * dst_stride + (0) * 3 + 2] = val_10 >> 8;

    dst[(0) * dst_stride + (0) * 3 + 1] = val_00 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 1] = val_11 >> 8;
    dst[(0) * dst_stride + (1) * 3 + 1] = dst[(1) * dst_stride + (0) * 3 + 1] = avg_h;

    dst[(1) * dst_stride + (1) * 3 + 0] = dst[(0) * dst_stride + (0) * 3 + 0] = 
    dst[(0) * dst_stride + (1) * 3 + 0] = dst[(1) * dst_stride + (0) * 3 + 0] = val_01 >> 8;

    src += 2 * 2;
    dst += 6;
}
}
