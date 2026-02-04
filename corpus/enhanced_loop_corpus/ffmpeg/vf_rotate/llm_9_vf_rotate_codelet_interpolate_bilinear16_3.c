#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst_color;
extern  uint8_t *src;
extern int src_linesize;
extern int src_linestep;
extern int int_x;
extern int int_y;
extern int frac_x;
extern int frac_y;
extern int i;
extern int int_x1;
extern int int_y1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < src_linestep; i += 2) {
    int base0 = src_linestep * int_x + i;
    int base1 = src_linestep * int_x1 + i;
    int offset_y0 = src_linesize * int_y;
    int offset_y1 = src_linesize * int_y1;

    const uint8_t* src_ptr = src;
    uint8_t* dst_ptr = dst_color;

    int s00 = ((const union unaligned_16 *)(src_ptr + base0 + offset_y0))->l;
    int s01 = ((const union unaligned_16 *)(src_ptr + base1 + offset_y0))->l;
    int s10 = ((const union unaligned_16 *)(src_ptr + base0 + offset_y1))->l;
    int s11 = ((const union unaligned_16 *)(src_ptr + base1 + offset_y1))->l;

    int w_x_inv = (1 << 16) - frac_x;
    int w_y_inv = (1 << 16) - frac_y;

    int s0 = w_x_inv * s00 + frac_x * s01;
    int s1 = w_x_inv * s10 + frac_x * s11;

    int64_t temp = (int64_t)w_y_inv * s0 + (int64_t)frac_y * s1;
    ((union unaligned_16 *)(dst_ptr + i))->l = (uint16_t)(temp >> 32);
}
}
