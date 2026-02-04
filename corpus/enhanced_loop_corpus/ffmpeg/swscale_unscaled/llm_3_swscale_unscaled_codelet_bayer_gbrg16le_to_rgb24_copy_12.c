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

    // Reorder memory accesses to use consecutive loads and stores where possible
    uint16_t val_00 = ((const union unaligned_16 *)(src_base_0 + 0))->l;
    uint16_t val_01 = ((const union unaligned_16 *)(src_base_0 + 2))->l;
    uint16_t val_10 = ((const union unaligned_16 *)(src_base_1 + 0))->l;
    uint16_t val_11 = ((const union unaligned_16 *)(src_base_1 + 2))->l;

    uint8_t avg_01 = ((unsigned int)val_00 + (unsigned int)val_11) >> (1 + 8);

    // Store components in a more sequential pattern across destination
    dst_row_0[0] = dst_row_0[3] = dst_row_1[3] = dst_row_1[0] = val_10 >> 8;
    dst_row_0[1] = val_00 >> 8;
    dst_row_1[4] = val_11 >> 8;
    dst_row_0[4] = dst_row_1[1] = avg_01;
    dst_row_1[5] = dst_row_0[2] = dst_row_0[5] = dst_row_1[2] = val_01 >> 8;

    src += 4;
    dst += 6;
}
}
