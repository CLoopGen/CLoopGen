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
for (i = 0; i < width; i += 1) {
    const union unaligned_16 *u00 = (const union unaligned_16 *)(&(src[0 * src_stride + 2 * 0]));
    const union unaligned_16 *u01 = (const union unaligned_16 *)(&(src[0 * src_stride + 2 * 1]));
    const union unaligned_16 *u10 = (const union unaligned_16 *)(&(src[1 * src_stride + 2 * 0]));
    const union unaligned_16 *u11 = (const union unaligned_16 *)(&(src[1 * src_stride + 2 * 1]));

    unsigned int avg_low = ((unsigned int)u00->l + (unsigned int)u11->l) >> 1;

    dst[0]                     = u10->l >> 8;
    dst[1]                     = u00->l >> 8;
    dst[2]                     = u01->l >> 8;

    dst[dst_stride * 1 + 0]    = u10->l >> 8;
    dst[dst_stride * 1 + 1]    = avg_low >> 8;
    dst[dst_stride * 1 + 2]    = u01->l >> 8;

    dst[3]                     = u10->l >> 8;
    dst[4]                     = avg_low >> 8;
    dst[5]                     = u01->l >> 8;

    dst[dst_stride * 1 + 3]    = u10->l >> 8;
    dst[dst_stride * 1 + 4]    = u11->l >> 8;
    dst[dst_stride * 1 + 5]    = u01->l >> 8;

    src += 2;
    dst += 3;
}
}
