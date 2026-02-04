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
extern uint32_t p4a;
extern uint32_t p4b;
extern uint32_t p4c;
extern uint32_t p4d;
extern uint32_t p4e;
extern uint32_t p4f;
extern uint32_t p4g;
extern uint32_t p4h;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    uint32_t tmp1 = p4a + p4b;
    uint32_t tmp2 = p4c + p4d;
    uint32_t tmp3 = p4e + p4f;
    uint32_t tmp4 = p4g + p4h;

    (((av_alias32 *)(dst + 0))->u32 = (tmp1));
    (((av_alias32 *)(dst + 4))->u32 = (tmp2));
    (((av_alias32 *)(dst + 8))->u32 = (tmp3));
    (((av_alias32 *)(dst + 12))->u32 = (tmp4));

    tmp1 += tmp2; tmp3 += tmp4;
    (((av_alias32 *)(dst + 16))->u32 = (tmp1));
    (((av_alias32 *)(dst + 20))->u32 = (tmp3));

    dst += stride;
}
}
