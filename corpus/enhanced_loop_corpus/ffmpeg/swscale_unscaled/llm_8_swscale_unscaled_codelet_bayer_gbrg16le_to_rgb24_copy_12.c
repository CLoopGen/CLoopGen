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
uint8_t temp_vals[4][3];
for (i = 0; i < width; i += 2) {
    const uint8_t* src_row0 = &src[(0) * src_stride];
    const uint8_t* src_row1 = &src[(1) * src_stride];

    uint16_t s00 = ((const union unaligned_16 *)(src_row0 + 2 * 0))->l;
    uint16_t s01 = ((const union unaligned_16 *)(src_row0 + 2 * 1))->l;
    uint16_t s10 = ((const union unaligned_16 *)(src_row1 + 2 * 0))->l;
    uint16_t s11 = ((const union unaligned_16 *)(src_row1 + 2 * 1))->l;

    temp_vals[0][0] = s10 >> 8;
    temp_vals[0][1] = s00 >> 8;
    temp_vals[0][2] = s01 >> 8;

    temp_vals[1][0] = temp_vals[0][0];
    temp_vals[1][1] = ((unsigned)s00 + s11) >> 9;
    temp_vals[1][2] = temp_vals[0][2];

    temp_vals[2][0] = temp_vals[0][0];
    temp_vals[2][1] = temp_vals[1][1];
    temp_vals[2][2] = temp_vals[0][2];

    temp_vals[3][0] = temp_vals[0][0];
    temp_vals[3][1] = temp_vals[1][1];
    temp_vals[3][2] = temp_vals[0][2];

    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
            dst[r * dst_stride + c * 3 + 0] = temp_vals[r * 2 + c][0];
            dst[r * dst_stride + c * 3 + 1] = temp_vals[r * 2 + c][1];
            dst[r * dst_stride + c * 3 + 2] = temp_vals[r * 2 + c][2];
        }
    }

    src += 2 * 2;
    dst += 6;
}
}
