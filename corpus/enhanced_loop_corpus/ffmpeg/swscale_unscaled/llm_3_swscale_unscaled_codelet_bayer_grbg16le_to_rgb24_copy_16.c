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
    const uint8_t *s0 = &src[0];
    const uint8_t *s1 = &src[src_stride];
    uint8_t *d0 = &dst[0];
    uint8_t *d1 = &dst[dst_stride];

    d0[2] = d0[5] = d1[5] = d1[2] = ((const union unaligned_16 *)&s1[0])->l >> 8;
    d0[1] = ((const union unaligned_16 *)&s0[0])->l >> 8;
    d1[4] = ((const union unaligned_16 *)&s1[2])->l >> 8;
    d0[4] = d1[1] = (((unsigned int)((const union unaligned_16 *)&s0[0])->l + (unsigned int)((const union unaligned_16 *)&s1[2])->l) >> 9);
    d1[3] = d0[0] = d0[3] = d1[0] = ((const union unaligned_16 *)&s0[2])->l >> 8;

    src += 4;
    dst += 6;
}
}
