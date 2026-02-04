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
// Use indirect addressing via index arrays to simulate irregular memory access pattern
// This variant precomputes all required source and destination offsets for clarity and flexibility

static const int src_offsets[4] = { 2*1, 2*1, 2*0, 2*0 }; // effective src column indices multiplied by 2
static const int dst_rows[6] = { 0, 0, 1, 1, 0, 1 };
static const int dst_cols[6] = { 2, 1, 1, 2, 0, 0 };

for (i = 0; i < width; i += 2) {
    const uint8_t *s0 = src + 0 * src_stride;
    const uint8_t *s1 = src + 1 * src_stride;

    uint8_t *d[6];
    for (int j = 0; j < 6; ++j) {
        d[j] = &dst[dst_rows[j] * dst_stride + dst_cols[j] * 3];
    }

    // Assign using indirect destinations
    d[0][2] = d[3][2] = d[2][2] = d[1][2] = ((const union unaligned_16 *)(s1 + src_offsets[0]))->l >> 8;
    d[0][1] = ((const union unaligned_16 *)(s0 + src_offsets[1]))->l >> 8;
    d[0][0] = d[2][1] = ((unsigned int)(((const union unaligned_16 *)(s0 + src_offsets[2]))->l) + 
                         (unsigned int)(((const union unaligned_16 *)(s1 + src_offsets[3]))->l)) >> 9;
    d[1][1] = ((const union unaligned_16 *)(s1 + src_offsets[3]))->l >> 8;
    d[5][0] = d[4][0] = d[0][0] = d[1][0] = ((const union unaligned_16 *)(s0 + src_offsets[2]))->l >> 8;

    src += 4;
    dst += 6;
}
}
