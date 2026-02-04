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
    uint8_t *src_base0 = src + 0 * src_stride;
    uint8_t *src_base1 = src + 1 * src_stride;
    uint8_t *dst_row0 = dst + 0 * dst_stride;
    uint8_t *dst_row1 = dst + 1 * dst_stride;

    // Load source values using consecutive memory layout interpretation
    uint16_t val_00 = ((const union unaligned_16 *)(src_base0 + 0))->l;
    uint16_t val_02 = ((const union unaligned_16 *)(src_base0 + 2))->l;
    uint16_t val_10 = ((const union unaligned_16 *)(src_base1 + 0))->l;
    uint16_t val_12 = ((const union unaligned_16 *)(src_base1 + 2))->l;

    // Store to destination with direct pointer arithmetic, avoiding repeated indexing
    dst_row0[0] = dst_row0[3] = dst_row1[4] = dst_row1[1] = val_12 >> 8;
    dst_row0[4] = val_02 >> 8;
    dst_row0[1] = dst_row1[4] = ((unsigned int)val_02 + (unsigned int)val_10) >> 9;
    dst_row1[1] = val_10 >> 8;
    dst_row1[5] = dst_row0[2] = dst_row0[5] = dst_row1[2] = val_00 >> 8;

    src += 4;
    dst += 6;
}
}
