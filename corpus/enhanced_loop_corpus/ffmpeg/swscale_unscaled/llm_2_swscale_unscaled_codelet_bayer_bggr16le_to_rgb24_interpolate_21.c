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
    uint8_t *src_base = src;
    uint8_t *dst_base = dst;

    dst_base[(0)*dst_stride + 0] = ((unsigned int)(((const union unaligned_16 *)(src_base - src_stride - 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base - src_stride + 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + src_stride - 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + src_stride + 2))->l)) >> 10;
    dst_base[(0)*dst_stride + 1] = ((unsigned int)(((const union unaligned_16 *)(src_base - src_stride + 0))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 0 - 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 0 + 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + src_stride + 0))->l)) >> 10;
    dst_base[(0)*dst_stride + 2] = (((const union unaligned_16 *)(src_base + 0))->l) >> 8;

    dst_base[(1)*dst_stride + 0] = ((unsigned int)(((const union unaligned_16 *)(src_base - src_stride + 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + src_stride + 2))->l)) >> 9;
    dst_base[(1)*dst_stride + 1] = (((const union unaligned_16 *)(src_base + 2))->l) >> 8;
    dst_base[(1)*dst_stride + 2] = ((unsigned int)(((const union unaligned_16 *)(src_base + 0))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 4))->l)) >> 9;

    dst_base[(2)*dst_stride + 0] = ((unsigned int)(((const union unaligned_16 *)(src_base + src_stride - 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + src_stride + 2))->l)) >> 9;
    dst_base[(2)*dst_stride + 1] = (((const union unaligned_16 *)(src_base + src_stride + 0))->l) >> 8;
    dst_base[(2)*dst_stride + 2] = ((unsigned int)(((const union unaligned_16 *)(src_base + 0))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 2*src_stride + 0))->l)) >> 9;

    dst_base[(3)*dst_stride + 0] = (((const union unaligned_16 *)(src_base + src_stride + 2))->l) >> 8;
    dst_base[(3)*dst_stride + 1] = ((unsigned int)(((const union unaligned_16 *)(src_base + 0 + 2))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + src_stride + 0))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + src_stride + 4))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 2*src_stride + 2))->l)) >> 10;
    dst_base[(3)*dst_stride + 2] = ((unsigned int)(((const union unaligned_16 *)(src_base + 0))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 4))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 2*src_stride + 0))->l) +
                                    (unsigned int)(((const union unaligned_16 *)(src_base + 2*src_stride + 4))->l)) >> 10;

    src += 4;
    dst += 2 * dst_stride;
}
}
