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
for (i = 2; i < width - 6; i += 6) {
    unsigned int s00, s02, s04, s20, s22, s24, s40, s42, s44;
    s00 = ((const union unaligned_16 *)(&(src[-2 * src_stride - 4])))->l;
    s02 = ((const union unaligned_16 *)(&(src[-2 * src_stride + 0])))->l;
    s04 = ((const union unaligned_16 *)(&(src[-2 * src_stride + 4])))->l;
    s20 = ((const union unaligned_16 *)(&(src[0 * src_stride - 4])))->l;
    s22 = ((const union unaligned_16 *)(&(src[0 * src_stride + 0])))->l;
    s24 = ((const union unaligned_16 *)(&(src[0 * src_stride + 4])))->l;
    s40 = ((const union unaligned_16 *)(&(src[2 * src_stride - 4])))->l;
    s42 = ((const union unaligned_16 *)(&(src[2 * src_stride + 0])))->l;
    s44 = ((const union unaligned_16 *)(&(src[2 * src_stride + 4])))->l;

    dst[0 * dst_stride + 0] = s22 >> 8;
    dst[0 * dst_stride + 1] = (s20 + s24) >> 9;
    dst[0 * dst_stride + 2] = (s02 + s42) >> 9;

    dst[1 * dst_stride + 0] = (s00 + s44) >> 9;
    dst[1 * dst_stride + 1] = (s04 + s40) >> 9;
    dst[1 * dst_stride + 2] = (s22 + s22 + s02 + s42 + s20 + s24) >> 11;

    dst[2 * dst_stride + 0] = (s00 + s04 + s40 + s44) >> 10;
    dst[2 * dst_stride + 1] = (s20 + s24 + s02 + s42) >> 10;
    dst[2 * dst_stride + 2] = (s22 + s22 + s22 + s22 + s00 + s04 + s40 + s44) >> 11;

    src += 6 * 2;
    dst += 3 * dst_stride;
}
}
