#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern uint16_t *dst;
extern  uint16_t *src;
extern int h;
extern int stride;
extern int scale;
extern unsigned int dc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    unsigned int tmpval0, tmpval1, tmpval2, tmpval3;
    const uint16_t *src_local = src;
    uint16_t *dst_local = dst;

    tmpval0 = (((const union unaligned_32 *)(src_local + 0))->l) * scale + dc;
    tmpval1 = (((const union unaligned_32 *)(src_local + 2))->l) * scale + dc;
    tmpval2 = (((const union unaligned_32 *)(src_local + 4))->l) * scale + dc;
    tmpval3 = (((const union unaligned_32 *)(src_local + 6))->l) * scale + dc;

    (((av_alias32 *)(dst_local + 0))->u32 = tmpval0);
    (((av_alias32 *)(dst_local + 2))->u32 = tmpval1);
    (((av_alias32 *)(dst_local + 4))->u32 = tmpval2);
    (((av_alias32 *)(dst_local + 6))->u32 = tmpval3);

    if (scale)
        src += stride;
    dst += stride;
}
}
