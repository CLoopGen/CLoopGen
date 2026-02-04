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
for (i = 0; i < width; i += 1) {
    const uint8_t *s0 = &src[(0) * src_stride];
    const uint8_t *s1 = &src[(1) * src_stride];

    uint16_t s00 = ((const union unaligned_16 *)(s0 + 0))->l;
    uint16_t s02 = ((const union unaligned_16 *)(s0 + 2))->l;
    uint16_t s10 = ((const union unaligned_16 *)(s1 + 0))->l;
    uint16_t s12 = ((const union unaligned_16 *)(s1 + 2))->l;

    uint32_t sum_center = (unsigned int)(s00) + (unsigned int)(s12);
    uint8_t avg_center = (sum_center >> (1 + 8));

    dst[(0) * dst_stride + (0) * 3 + 2] = s10 >> 8;
    dst[(0) * dst_stride + (1) * 3 + 2] = s10 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 2] = s10 >> 8;
    dst[(1) * dst_stride + (0) * 3 + 2] = s10 >> 8;

    dst[(0) * dst_stride + (0) * 3 + 1] = s00 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 1] = s12 >> 8;

    dst[(0) * dst_stride + (1) * 3 + 1] = avg_center;
    dst[(1) * dst_stride + (0) * 3 + 1] = avg_center;

    dst[(0) * dst_stride + (0) * 3 + 0] = s02 >> 8;
    dst[(1) * dst_stride + (1) * 3 + 0] = s02 >> 8;
    dst[(0) * dst_stride + (1) * 3 + 0] = s02 >> 8;
    dst[(1) * dst_stride + (0) * 3 + 0] = s02 >> 8;

    src += 2;
    dst += 3;
}
}
