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
    uint8_t *src0 = &src[0 * src_stride];
    uint8_t *src1 = &src[1 * src_stride];
    uint8_t *dst0 = &dst[0 * dst_stride];
    uint8_t *dst1 = &dst[1 * dst_stride];

    // Convert strided 2D-like access into consecutive local pointers for better spatial locality
    dst0[2] = dst0[5] = dst1[5] = dst1[2] = ((const union unaligned_16 *)(src1 + 2))->l >> 8;
    dst0[4] = ((const union unaligned_16 *)(src0 + 2))->l >> 8;
    dst0[1] = dst1[4] = ((unsigned int)(((const union unaligned_16 *)(src0 + 2))->l) + 
                         (unsigned int)(((const union unaligned_16 *)(src1 + 0))->l)) >> 9;
    dst1[1] = ((const union unaligned_16 *)(src1 + 0))->l >> 8;
    dst1[0] = dst0[0] = dst0[3] = dst1[3] = ((const union unaligned_16 *)(src0 + 0))->l >> 8;

    src += 4;
    dst += 6;
}
}
