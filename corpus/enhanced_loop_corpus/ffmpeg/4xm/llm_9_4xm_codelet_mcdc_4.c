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
for (i = 0; i < h && scale != 0; i++) {
    uint32_t s = ((const union unaligned_32 *)(src))->l;
    unsigned int tmpval = s * scale + dc;
    av_alias32 *d = (av_alias32 *)dst;
    d->u32 = tmpval;
    // Additional computational load: simulate a simple saturation arithmetic on individual bytes
    d->u8[0] = (d->u8[0] > 200) ? 255 : d->u8[0] + 50;
    d->u8[1] = (d->u8[1] < 50)  ? 0   : d->u8[1] - 25;
    src += stride;
    dst += stride;
}
}
