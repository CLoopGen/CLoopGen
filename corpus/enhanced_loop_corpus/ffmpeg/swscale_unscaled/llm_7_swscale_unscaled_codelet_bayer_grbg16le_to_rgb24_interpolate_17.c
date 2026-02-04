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
    uint16_t center = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t left = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (-1)])))->l;
    uint16_t right = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
    uint16_t top = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (0)])))->l;
    uint16_t bottom = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
    uint16_t top_right = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (2)])))->l;
    uint16_t bottom_right = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (2)])))->l;
    uint16_t top_mid = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (1)])))->l;
    uint16_t bottom_mid = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;
    uint16_t center_right = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l;
    uint16_t next_bottom = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (0)])))->l;
    uint16_t bottom_left = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (-1)])))->l;
    uint16_t next_bottom_left = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (-1)])))->l;
    uint16_t next_bottom_mid = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (1)])))->l;

    unsigned int avg_horiz = (left + right) >> 1;
    unsigned int avg_vert = (top + bottom) >> 1;
    unsigned int avg_cross = (top + top_right + bottom + bottom_right) >> 2;
    unsigned int avg_diag_center = (top_mid + center + center_right + bottom_mid) >> 2;
    unsigned int avg_cross_bottom = (center + bottom_left + bottom_mid + next_bottom) >> 2;
    unsigned int avg_horiz_edges = (left + right + next_bottom_left + next_bottom_mid) >> 2;
    unsigned int avg_right_pair = (right + next_bottom_mid) >> 1;

    dst[(0) * dst_stride + (0) * 3 + 2] = avg_vert >> 8;
    dst[(0) * dst_stride + (0) * 3 + 1] = center >> 8;
    dst[(0) * dst_stride + (0) * 3 + 0] = avg_horiz >> 8;
    dst[(0) * dst_stride + (1) * 3 + 2] = avg_cross >> 8;
    dst[(0) * dst_stride + (1) * 3 + 1] = avg_diag_center >> 8;
    dst[(0) * dst_stride + (1) * 3 + 0] = right >> 8;
    dst[(1) * dst_stride + (0) * 3 + 2] = bottom >> 8;
    dst[(1) * dst_stride + (0) * 3 + 1] = avg_cross_bottom >> 8;
    dst[(1) * dst_stride + (0) * 3 + 0] = avg_horiz_edges >> 8;
    dst[(1) * dst_stride + (1) * 3 + 2] = (bottom + bottom_right) >> (1 + 8);
    dst[(1) * dst_stride + (1) * 3 + 1] = bottom_mid >> 8;
    dst[(1) * dst_stride + (1) * 3 + 0] = avg_right_pair >> (1 + 8);

    src += 2 * 2;
    dst += 6;
}
}
