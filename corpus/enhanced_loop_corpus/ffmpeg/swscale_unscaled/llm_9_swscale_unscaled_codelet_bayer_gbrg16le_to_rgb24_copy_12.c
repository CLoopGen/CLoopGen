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
    uint8_t *s0 = src + 0 * src_stride;
    uint8_t *s1 = src + 1 * src_stride;
    uint16_t v00 = ((const union unaligned_16 *)(s0 + 2*0))->l;
    uint16_t v01 = ((const union unaligned_16 *)(s0 + 2*1))->l;
    uint16_t v10 = ((const union unaligned_16 *)(s1 + 2*0))->l;
    uint16_t v11 = ((const union unaligned_16 *)(s1 + 2*1))->l;

    dst[(0) * dst_stride + (0) * 3 + 0] = dst[(0) * dst_stride + (1) * 3 + 0] =
        dst[(1) * dst_stride + (1) * 3 + 0] = dst[(1) * dst_stride + (0) * 3 + 0] = v10 >> 8;

    dst[(0) * dst_stride + (0) * 3 + 1] = v00 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 1] = v11 >> 8;

    dst[(0) * dst_stride + (1) * 3 + 1] = dst[(1) * dst_stride + (0) * 3 + 1] = 
        ((unsigned int)v00 + (unsigned int)v11) >> (1 + 8);

    dst[(1) * dst_stride + (1) * 3 + 2] = dst[(0) * dst_stride + (0) * 3 + 2] =
        dst[(0) * dst_stride + (1) * 3 + 2] = dst[(1) * dst_stride + (0) * 3 + 2] = v01 >> 8;

    if (i + 2 < width) {
        s0 += 2 * 2; s1 += 2 * 2; dst += 6;
        uint16_t v02 = ((const union unaligned_16 *)(s0 + 2*0))->l;
        uint16_t v03 = ((const union unaligned_16 *)(s0 + 2*1))->l;
        uint16_t v12 = ((const union unaligned_16 *)(s1 + 2*0))->l;
        uint16_t v13 = ((const union unaligned_16 *)(s1 + 2*1))->l;

        dst[(0) * dst_stride + (0) * 3 + 0] = dst[(0) * dst_stride + (1) * 3 + 0] =
            dst[(1) * dst_stride + (1) * 3 + 0] = dst[(1) * dst_stride + (0) * 3 + 0] = v12 >> 8;

        dst[(0) * dst_stride + (0) * 3 + 1] = v02 >> 8;
        dst[(1) * dst_stride + (1) * 3 + 1] = v13 >> 8;

        dst[(0) * dst_stride + (1) * 3 + 1] = dst[(1) * dst_stride + (0) * 3 + 1] = 
            ((unsigned int)v02 + (unsigned int)v13) >> (1 + 8);

        dst[(1) * dst_stride + (1) * 3 + 2] = dst[(0) * dst_stride + (0) * 3 + 2] =
            dst[(0) * dst_stride + (1) * 3 + 2] = dst[(1) * dst_stride + (0) * 3 + 2] = v03 >> 8;

        dst += 6;
        src += 4 * 2;
    } else {
        dst += 6;
        src += 2 * 2;
    }
}
}
