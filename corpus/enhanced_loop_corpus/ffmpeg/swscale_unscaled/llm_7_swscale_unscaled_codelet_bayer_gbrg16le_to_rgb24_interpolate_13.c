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
uint8_t *local_src = src;
uint8_t *local_dst = dst;
int local_i = i;

for (local_i = 2; local_i < width - 2; local_i += 2) {
    uint16_t val_center = ((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t val_left   = ((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (-1)])))->l;
    uint16_t val_right  = ((const union unaligned_16 *)(&(local_src[(0) * src_stride + 2 * (1)])))->l;
    uint16_t val_up     = ((const union unaligned_16 *)(&(local_src[(-1) * src_stride + 2 * (0)])))->l;
    uint16_t val_down   = ((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (0)])))->l;
    uint16_t val_up_r   = ((const union unaligned_16 *)(&(local_src[(-1) * src_stride + 2 * (2)])))->l;
    uint16_t val_down_r = ((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (2)])))->l;
    uint16_t val_up_c1  = ((const union unaligned_16 *)(&(local_src[(-1) * src_stride + 2 * (1)])))->l;
    uint16_t val_down_c1= ((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (1)])))->l;
    uint16_t val_right_c0 = ((const union unaligned_16 *)(&(local_src[(1) * src_stride + 2 * (-1)])))->l;
    uint16_t val_below_c0 = ((const union unaligned_16 *)(&(local_src[(2) * src_stride + 2 * (0)])))->l;
    uint16_t val_below_l= ((const union unaligned_16 *)(&(local_src[(2) * src_stride + 2 * (-1)])))->l;
    uint16_t val_below_r= ((const union unaligned_16 *)(&(local_src[(2) * src_stride + 2 * (1)])))->l;

    dst[(0) * dst_stride + (0) * 3 + 0] = ((unsigned int)val_up + (unsigned int)val_down) >> 9;
    dst[(0) * dst_stride + (0) * 3 + 1] = val_center >> 8;
    dst[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)val_left + (unsigned int)val_right) >> 9;
    dst[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)val_up + (unsigned int)val_up_r + (unsigned int)val_down + (unsigned int)val_down_r) >> 10;
    dst[(0) * dst_stride + (1) * 3 + 1] = ((unsigned int)val_up_c1 + (unsigned int)val_center + (unsigned int)val_down_c1 + (unsigned int)val_down_c1) >> 10;
    dst[(0) * dst_stride + (1) * 3 + 2] = val_right >> 8;
    dst[(1) * dst_stride + (0) * 3 + 0] = val_down >> 8;
    dst[(1) * dst_stride + (0) * 3 + 1] = ((unsigned int)val_center + (unsigned int)val_right_c0 + (unsigned int)val_down_c1 + (unsigned int)val_below_c0) >> 10;
    dst[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)val_left + (unsigned int)val_right + (unsigned int)val_below_l + (unsigned int)val_below_r) >> 10;
    dst[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)val_down + (unsigned int)val_down_r) >> 9;
    dst[(1) * dst_stride + (1) * 3 + 1] = val_down_c1 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 2] = ((unsigned int)val_right + (unsigned int)val_below_r) >> 9;

    local_src += 4;
    local_dst += 6;
}

src = local_src;
dst = local_dst;
i = local_i;
}
