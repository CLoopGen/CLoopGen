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
for (i = 2; i < width - 2; i += 2) {
    uint16_t val00 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t valm1m1 = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (-1)])))->l;
    uint16_t valm1p1 = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (1)])))->l;
    uint16_t valp1m1 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (-1)])))->l;
    uint16_t valp1p1 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;
    uint16_t valm10 = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (0)])))->l;
    uint16_t val0m1 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (-1)])))->l;
    uint16_t val0p1 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
    uint16_t valp10 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
    uint16_t val0p2 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l;
    uint16_t valp20 = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (0)])))->l;
    uint16_t valp1p2 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (2)])))->l;
    uint16_t valp2p1 = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (1)])))->l;
    uint16_t valp2p2 = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (2)])))->l;

    unsigned int sum_corner_avg = (valm1m1 + valm1p1 + valp1m1 + valp1p1) >> 2;
    unsigned int sum_cross_avg = (valm10 + val0m1 + val0p1 + valp10) >> 2;
    unsigned int sum_right_pair = (valm1p1 + valp1p1) >> 1;
    unsigned int sum_bottom_pair = (valp1m1 + valp1p1) >> 1;
    unsigned int sum_center_right = (val00 + val0p2) >> 1;
    unsigned int sum_center_bottom = (val00 + valp20) >> 1;
    unsigned int sum_inner_cross = (val0p1 + valp10 + valp1p2 + valp2p1) >> 2;
    unsigned int sum_outer_corner_avg = (val00 + val0p2 + valp20 + valp2p2) >> 2;

    dst[(0) * dst_stride + (0) * 3 + 2] = sum_corner_avg >> 8;
    dst[(0) * dst_stride + (0) * 3 + 1] = sum_cross_avg >> 8;
    dst[(0) * dst_stride + (0) * 3 + 0] = val00 >> 8;
    dst[(0) * dst_stride + (1) * 3 + 2] = sum_right_pair >> 8;
    dst[(0) * dst_stride + (1) * 3 + 1] = val0p1 >> 8;
    dst[(0) * dst_stride + (1) * 3 + 0] = sum_center_right >> 8;
    dst[(1) * dst_stride + (0) * 3 + 2] = sum_bottom_pair >> 8;
    dst[(1) * dst_stride + (0) * 3 + 1] = valp10 >> 8;
    dst[(1) * dst_stride + (0) * 3 + 0] = sum_center_bottom >> 8;
    dst[(1) * dst_stride + (1) * 3 + 2] = valp1p1 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 1] = sum_inner_cross >> 8;
    dst[(1) * dst_stride + (1) * 3 + 0] = sum_outer_corner_avg >> 8;

    src += 2 * 2;
    dst += 6;
}
}
