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
for (i = 0; i < width; i += 2) {
    uint8_t *src_base_0 = src + 0 * src_stride;
    uint8_t *src_base_1 = src + 1 * src_stride;
    uint8_t *dst_row_0 = dst + 0 * dst_stride;
    uint8_t *dst_row_1 = dst + 1 * dst_stride;

    dst_row_0[2] = dst_row_0[5] = dst_row_1[5] = dst_row_1[2] = (((const union unaligned_16 *)(src_base_1 + 0))->l) >> 8;
    dst_row_0[1] = (((const union unaligned_16 *)(src_base_0 + 0))->l) >> 8;
    dst_row_1[4] = (((const union unaligned_16 *)(src_base_1 + 2))->l) >> 8;
    dst_row_0[4] = dst_row_1[1] = ((unsigned int)(((const union unaligned_16 *)(src_base_0 + 0))->l) + (unsigned int)(((const union unaligned_16 *)(src_base_1 + 2))->l)) >> 9;
    dst_row_1[3] = dst_row_0[0] = dst_row_0[3] = dst_row_1[0] = (((const union unaligned_16 *)(src_base_0 + 2))->l) >> 8;

    src += 4;
    dst += 6;
}
}
