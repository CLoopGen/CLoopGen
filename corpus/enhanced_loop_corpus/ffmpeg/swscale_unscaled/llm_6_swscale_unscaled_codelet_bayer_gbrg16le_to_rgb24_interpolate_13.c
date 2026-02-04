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
    uint16_t temp1 = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (0)])))->l;
    uint16_t temp2 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
    uint16_t temp3 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t temp4 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (-1)])))->l;
    uint16_t temp5 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
    uint16_t temp6 = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (2)])))->l;
    uint16_t temp7 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (2)])))->l;
    uint16_t temp8 = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (1)])))->l;
    uint16_t temp9 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l;
    uint16_t temp10 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;
    uint16_t temp11 = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (0)])))->l;
    uint16_t temp12 = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (-1)])))->l;
    uint16_t temp13 = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (-1)])))->l;
    uint16_t temp14 = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (1)])))->l;

    dst[(0) * dst_stride + (0) * 3 + 0] = ((unsigned int)temp1 + (unsigned int)temp2) >> (1 + 8);
    dst[(0) * dst_stride + (0) * 3 + 1] = temp3 >> 8;
    dst[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)temp4 + (unsigned int)temp5) >> (1 + 8);
    dst[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)temp1 + (unsigned int)temp6 + (unsigned int)temp2 + (unsigned int)temp7) >> (2 + 8);
    dst[(0) * dst_stride + (1) * 3 + 1] = ((unsigned int)temp8 + (unsigned int)temp3 + (unsigned int)temp9 + (unsigned int)temp10) >> (2 + 8);
    dst[(0) * dst_stride + (1) * 3 + 2] = temp5 >> 8;
    dst[(1) * dst_stride + (0) * 3 + 0] = temp2 >> 8;
    dst[(1) * dst_stride + (0) * 3 + 1] = ((unsigned int)temp3 + (unsigned int)temp12 + (unsigned int)temp10 + (unsigned int)temp11) >> (2 + 8);
    dst[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)temp4 + (unsigned int)temp5 + (unsigned int)temp13 + (unsigned int)temp14) >> (2 + 8);
    dst[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)temp2 + (unsigned int)temp7) >> (1 + 8);
    dst[(1) * dst_stride + (1) * 3 + 1] = temp10 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 2] = ((unsigned int)temp5 + (unsigned int)temp14) >> (1 + 8);

    src += 2 * 2;
    dst += 6;
}
}
