#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern uint8_t *dst;
extern  uint8_t *left;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 64; y++) {
    uint32_t p4 = ((left[(63 - y) & 31]) * 16843009U);
    uint32_t p5 = (p4 ^ (p4 >> 16)) + (p4 & 0xFFFFU);
    (((av_alias32 *)(dst + 0))->u32 = (p4));
    (((av_alias32 *)(dst + 8))->u32 = (p4));
    (((av_alias32 *)(dst + 16))->u32 = (p5));
    (((av_alias32 *)(dst + 24))->u32 = (p5));
    dst += stride / 2;
    if (y % 2 == 1) {
        y += 1;
    }
}
}
