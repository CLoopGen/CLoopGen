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
    uint16_t tl = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (-1)])))->l;
    uint16_t tr = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (1)])))->l;
    uint16_t bl = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (-1)])))->l;
    uint16_t br = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l;
    uint16_t top = ((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (0)])))->l;
    uint16_t left = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (-1)])))->l;
    uint16_t right = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (1)])))->l;
    uint16_t bottom = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (0)])))->l;
    uint16_t center = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (0)])))->l;
    uint16_t cl1 = ((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (2)])))->l;
    uint16_t cr1 = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (0)])))->l;
    uint16_t cbl = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (2)])))->l;
    uint16_t cbr = ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (1)])))->l;

    dst[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)(tl) + (unsigned int)(tr) + (unsigned int)(bl) + (unsigned int)(br)) >> (2 + 8);
    dst[(0) * dst_stride + (0) * 3 + 1] = ((unsigned int)(top) + (unsigned int)(left) + (unsigned int)(right) + (unsigned int)(bottom)) >> (2 + 8);
    dst[(0) * dst_stride + (0) * 3 + 0] = center >> 8;
    dst[(0) * dst_stride + (1) * 3 + 2] = ((unsigned int)(tr) + (unsigned int)(br)) >> (1 + 8);
    dst[(0) * dst_stride + (1) * 3 + 1] = right >> 8;
    dst[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)(center) + (unsigned int)(cl1)) >> (1 + 8);
    dst[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)(bl) + (unsigned int)(br)) >> (1 + 8);
    dst[(1) * dst_stride + (0) * 3 + 1] = bottom >> 8;
    dst[(1) * dst_stride + (0) * 3 + 0] = ((unsigned int)(center) + (unsigned int)(cr1)) >> (1 + 8);
    dst[(1) * dst_stride + (1) * 3 + 2] = ((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (1)])))->l >> 8;
    dst[(1) * dst_stride + (1) * 3 + 1] = ((unsigned int)(right) + (unsigned int)(bottom) + (unsigned int)(cbl) + (unsigned int)(cbr)) >> (2 + 8);
    dst[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)(center) + (unsigned int)(cl1) + (unsigned int)(cr1) + ((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (2)])))->l) >> (2 + 8);

    src += 2 * 2;
    dst += 6;
}
}
