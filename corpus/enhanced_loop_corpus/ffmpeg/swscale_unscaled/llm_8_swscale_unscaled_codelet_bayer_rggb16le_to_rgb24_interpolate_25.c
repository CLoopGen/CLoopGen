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
for (i = 2; i < width - 4; i += 4) {
    uint16_t sum_center = ((const union unaligned_16 *)(&(src[0])))->l;
    uint16_t sum_right = ((const union unaligned_16 *)(&(src[4])))->l;
    uint16_t sum_left = ((const union unaligned_16 *)(&(src[-4])))->l;
    uint16_t sum_top = ((const union unaligned_16 *)(&(src[-2 * src_stride])))->l;
    uint16_t sum_bottom = ((const union unaligned_16 *)(&(src[2 * src_stride])))->l;

    dst[0] = sum_center >> 8;
    dst[1] = (sum_center + sum_right) >> 9;
    dst[2] = (sum_center + sum_left) >> 9;

    dst[3] = (sum_center + sum_top) >> 9;
    dst[4] = (sum_center + sum_bottom) >> 9;
    dst[5] = (sum_top + sum_bottom) >> 9;

    dst[dst_stride * 1 + 0] = (sum_center + sum_top + sum_bottom + sum_right) >> 10;
    dst[dst_stride * 1 + 1] = (sum_center + sum_top + sum_bottom + sum_left) >> 10;
    dst[dst_stride * 1 + 2] = (sum_top + sum_bottom + sum_left + sum_right) >> 10;

    src += 4 * 2;
    dst += 2 * dst_stride;
}
}
