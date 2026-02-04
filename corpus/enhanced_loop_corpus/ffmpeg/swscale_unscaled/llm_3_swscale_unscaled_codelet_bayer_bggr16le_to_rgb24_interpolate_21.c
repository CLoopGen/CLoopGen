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
    const uint8_t *s = src;
    uint8_t *d = dst;

    // Reorder memory accesses to be more sequential in destination
    // and group source loads to improve cache locality

    uint16_t c_m1_m1 = ((const union unaligned_16 *)(s - src_stride - 2))->l;
    uint16_t c_m1_00 = ((const union unaligned_16 *)(s - src_stride + 0))->l;
    uint16_t c_m1_p1 = ((const union unaligned_16 *)(s - src_stride + 2))->l;

    uint16_t c_00_m1 = ((const union unaligned_16 *)(s + 0 - 2))->l;
    uint16_t c_00_00 = ((const union unaligned_16 *)(s + 0))->l;
    uint16_t c_00_p1 = ((const union unaligned_16 *)(s + 2))->l;
    uint16_t c_00_p2 = ((const union unaligned_16 *)(s + 4))->l;

    uint16_t c_p1_m1 = ((const union unaligned_16 *)(s + src_stride - 2))->l;
    uint16_t c_p1_00 = ((const union unaligned_16 *)(s + src_stride + 0))->l;
    uint16_t c_p1_p1 = ((const union unaligned_16 *)(s + src_stride + 2))->l;
    uint16_t c_p1_p2 = ((const union unaligned_16 *)(s + src_stride + 4))->l;

    uint16_t c_p2_m1 = ((const union unaligned_16 *)(s + 2*src_stride - 2))->l;
    uint16_t c_p2_00 = ((const union unaligned_16 *)(s + 2*src_stride + 0))->l;
    uint16_t c_p2_p1 = ((const union unaligned_16 *)(s + 2*src_stride + 2))->l;
    uint16_t c_p2_p2 = ((const union unaligned_16 *)(s + 2*src_stride + 4))->l;

    // Write output in row-major order with flattened indexing
    d[0] = (c_m1_m1 + c_m1_p1 + c_p1_m1 + c_p1_p1) >> 10;
    d[1] = (c_m1_00 + c_00_m1 + c_00_p1 + c_p1_00) >> 10;
    d[2] = c_00_00 >> 8;

    d[3] = (c_m1_p1 + c_p1_p1) >> 9;
    d[4] = c_00_p1 >> 8;
    d[5] = (c_00_00 + c_00_p2) >> 9;

    d[dst_stride + 0] = (c_p1_m1 + c_p1_p1) >> 9;
    d[dst_stride + 1] = c_p1_00 >> 8;
    d[dst_stride + 2] = (c_00_00 + c_p2_00) >> 9;

    d[dst_stride + 3] = c_p1_p1 >> 8;
    d[dst_stride + 4] = (c_00_p1 + c_p1_00 + c_p1_p2 + c_p2_p1) >> 10;
    d[dst_stride + 5] = (c_00_00 + c_00_p2 + c_p2_00 + c_p2_p2) >> 10;

    src += 4;
    dst += 6;
}
}
