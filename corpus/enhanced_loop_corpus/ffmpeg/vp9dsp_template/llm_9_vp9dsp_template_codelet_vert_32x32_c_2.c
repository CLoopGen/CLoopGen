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
    for (y = 0; y < 64; y++) {
        uint32_t tmp_a = p4a + y;
        uint32_t tmp_b = p4b + y;
        uint32_t tmp_c = p4c + y;
        uint32_t tmp_d = p4d + y;
        uint32_t tmp_e = p4e + y;
        uint32_t tmp_f = p4f + y;
        uint32_t tmp_g = p4g + y;
        uint32_t tmp_h = p4h + y;

        (((av_alias32 *)(dst + 0))->u32 = tmp_a);
        (((av_alias32 *)(dst + 4))->u32 = tmp_b);
        (((av_alias32 *)(dst + 8))->u32 = tmp_c);
        (((av_alias32 *)(dst + 12))->u32 = tmp_d);
        (((av_alias32 *)(dst + 16))->u32 = tmp_e);
        (((av_alias32 *)(dst + 20))->u32 = tmp_f);
        (((av_alias32 *)(dst + 24))->u32 = tmp_g);
        (((av_alias32 *)(dst + 28))->u32 = tmp_h);
        dst += stride / 2;
    }
}
