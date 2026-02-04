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
    unsigned int tmpval2 = (((const union unaligned_32 *)(src + stride))->l) * (scale) + (dc);
    (((av_alias32 *)(dst))->u32 = (tmpval1));
    (((av_alias32 *)(dst + stride))->u32 = (tmpval2));
    if (scale)
        src += 2 * stride;
    dst += 2 * stride;
    i++; // Process two rows per iteration
}
}
