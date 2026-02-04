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
    const uint8_t *s = src;
    uint8_t *d = dst;

    int cond1 = (i & 3) != 0;
    int cond2 = (i % 5) > 1;

    if (cond1) {
        d[(0) * dst_stride + (0) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(s[(-1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (0)])))->l)) >> (1 + 8);
        d[(0) * dst_stride + (0) * 3 + 1] = (((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (0)])))->l) >> 8;
        d[(0) * dst_stride + (0) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (1)])))->l)) >> (1 + 8);
        d[(1) * dst_stride + (1) * 3 + 1] = (((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (1)])))->l) >> 8;
    }

    if (cond2) {
        d[(0) * dst_stride + (1) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(s[(-1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(-1) * src_stride + 2 * (2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (2)])))->l)) >> (2 + 8);
        d[(0) * dst_stride + (1) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(s[(-1) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (2)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (1)])))->l)) >> (2 + 8);
        d[(1) * dst_stride + (0) * 3 + 1] = ((unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(2) * src_stride + 2 * (0)])))->l)) >> (2 + 8);
        d[(1) * dst_stride + (0) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(2) * src_stride + 2 * (-1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(2) * src_stride + 2 * (1)])))->l)) >> (2 + 8);
    }

    d[(1) * dst_stride + (0) * 3 + 0] = (((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (0)])))->l) >> 8;
    d[(1) * dst_stride + (1) * 3 + 0] = ((unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (0)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(1) * src_stride + 2 * (2)])))->l)) >> (1 + 8);
    d[(1) * dst_stride + (1) * 3 + 2] = ((unsigned int)(((const union unaligned_16 *)(&(s[(0) * src_stride + 2 * (1)])))->l) + (unsigned int)(((const union unaligned_16 *)(&(s[(2) * src_stride + 2 * (1)])))->l)) >> (1 + 8);

    src += 2 * 2;
    dst += 6;
}
}
