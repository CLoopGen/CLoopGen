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
    for (i = 2; i < width - 2; i += 4) {
        for (int j = 0; j < 2 && (i + j*2) < width - 2; j++) {
            int offset = j * 2;
            dst[(0) * dst_stride + (offset) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (offset)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset)])))->l)) >> (1 + 8);
            dst[(0) * dst_stride + (offset) * 3 + 1] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset)])))->l) >> 8;
            dst[(0) * dst_stride + (offset) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset - 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset + 1)])))->l)) >> (1 + 8);
            dst[(0) * dst_stride + (offset + 1) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (offset)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (offset + 2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset + 2)])))->l)) >> (2 + 8);
            dst[(0) * dst_stride + (offset + 1) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(src[(-1) * src_stride + 2 * (offset + 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset + 2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset + 1)])))->l)) >> (2 + 8);
            dst[(0) * dst_stride + (offset + 1) * 3 + 0] = (((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset + 1)])))->l) >> 8;
            dst[(1) * dst_stride + (offset) * 3 + 2] = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset)])))->l) >> 8;
            dst[(1) * dst_stride + (offset) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset - 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset + 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (offset)])))->l)) >> (2 + 8);
            dst[(1) * dst_stride + (offset) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset - 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset + 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (offset - 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (offset + 1)])))->l)) >> (2 + 8);
            dst[(1) * dst_stride + (offset + 1) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset + 2)])))->l)) >> (1 + 8);
            dst[(1) * dst_stride + (offset + 1) * 3 + 1] = (((const union unaligned_16 *)(&(src[(1) * src_stride + 2 * (offset + 1)])))->l) >> 8;
            dst[(1) * dst_stride + (offset + 1) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(src[(0) * src_stride + 2 * (offset + 1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(src[(2) * src_stride + 2 * (offset + 1)])))->l)) >> (1 + 8);
        }
        src += 4 * 2;
        dst += 12;
    }
}
