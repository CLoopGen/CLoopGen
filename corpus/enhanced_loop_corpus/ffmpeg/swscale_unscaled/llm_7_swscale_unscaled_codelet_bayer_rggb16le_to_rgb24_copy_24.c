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
uint8_t temp_red, temp_green, temp_blue;
for (i = 0; i < width; i += 2) {
    const uint8_t* src_row0 = &src[(0) * src_stride];
    const uint8_t* src_row1 = &src[(1) * src_stride];

    uint16_t s00 = ((const union unaligned_16 *)(src_row0 + 2 * 0))->l;
    uint16_t s01 = ((const union unaligned_16 *)(src_row0 + 2 * 1))->l;
    uint16_t s10 = ((const union unaligned_16 *)(src_row1 + 2 * 0))->l;
    uint16_t s11 = ((const union unaligned_16 *)(src_row1 + 2 * 1))->l;

    temp_blue = (s00 >> 8);
    temp_green = ((s01 + s10) >> (1 + 8));
    temp_red = (s11 >> 8);

    dst[(0) * dst_stride + (0) * 3 + 0] = temp_blue;
    dst[(0) * dst_stride + (1) * 3 + 0] = temp_blue;
    dst[(1) * dst_stride + (0) * 3 + 0] = temp_blue;
    dst[(1) * dst_stride + (1) * 3 + 0] = temp_blue;

    dst[(0) * dst_stride + (1) * 3 + 1] = (s01 >> 8);
    dst[(1) * dst_stride + (0) * 3 + 1] = (s10 >> 8);
    dst[(0) * dst_stride + (0) * 3 + 1] = temp_green;
    dst[(1) * dst_stride + (1) * 3 + 1] = temp_green;

    dst[(0) * dst_stride + (0) * 3 + 2] = temp_red;
    dst[(0) * dst_stride + (1) * 3 + 2] = temp_red;
    dst[(1) * dst_stride + (1) * 3 + 2] = temp_red;
    dst[(1) * dst_stride + (0) * 3 + 2] = temp_red;

    src += 2 * 2;
    dst += 6;
}
}
