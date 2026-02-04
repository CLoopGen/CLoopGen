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
// Change to indirect access using index arrays to simulate non-unit strided or reordered access
int indices_src[4];
int indices_dst[6];

for (i = 0; i < width; i += 2) {
    // Precompute indirect indices for source and destination
    indices_src[0] = 0 * src_stride + 0;
    indices_src[1] = 0 * src_stride + 2;
    indices_src[2] = 1 * src_stride + 0;
    indices_src[3] = 1 * src_stride + 2;

    indices_dst[0] = 0 * dst_stride + 0;
    indices_dst[1] = 0 * dst_stride + 3;
    indices_dst[2] = 1 * dst_stride + 3;
    indices_dst[3] = 1 * dst_stride + 0;
    indices_dst[4] = 0 * dst_stride + 1;
    indices_dst[5] = 1 * dst_stride + 4;

    const union unaligned_16 *u0 = (const union unaligned_16 *)&src[indices_src[0]];
    const union unaligned_16 *u1 = (const union unaligned_16 *)&src[indices_src[1]];
    const union unaligned_16 *u2 = (const union unaligned_16 *)&src[indices_src[2]];
    const union unaligned_16 *u3 = (const union unaligned_16 *)&src[indices_src[3]];

    uint8_t avg = ((unsigned int)u0->l + (unsigned int)u3->l) >> (1 + 8);

    // Use indirect addressing via precomputed indices
    dst[indices_dst[0]] = dst[indices_dst[1]] = dst[indices_dst[2]] = dst[indices_dst[3]] = u2->l >> 8;
    dst[indices_dst[4]] = u0->l >> 8;
    dst[indices_dst[5]] = u3->l >> 8;

    dst[0 * dst_stride + 4] = dst[1 * dst_stride + 1] = avg;

    dst[1 * dst_stride + 5] = dst[0 * dst_stride + 2] = 
    dst[0 * dst_stride + 5] = dst[1 * dst_stride + 2] = u1->l >> 8;

    src += 4;
    dst += 6;
}
}
