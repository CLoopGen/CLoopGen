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
    unsigned int tmpval1 = (((const union unaligned_32 *)(src))->l) * (scale) + (dc);
    unsigned int tmpval2 = (((const union unaligned_32 *)(src + 2))->l) * (scale) + (dc);
    unsigned int tmpval3 = (((const union unaligned_32 *)(src + 4))->l) * (scale) + (dc);
    unsigned int tmpval4 = (((const union unaligned_32 *)(src + 6))->l) * (scale) + (dc);

    (((av_alias32 *)(dst + 0))->u32 = tmpval1);
    (((av_alias32 *)(dst + 2))->u32 = tmpval2);
    (((av_alias32 *)(dst + 4))->u32 = tmpval3);
    (((av_alias32 *)(dst + 6))->u32 = tmpval4);

    if (scale)
        src += stride * 2;
    dst += stride * 2;
}
}
