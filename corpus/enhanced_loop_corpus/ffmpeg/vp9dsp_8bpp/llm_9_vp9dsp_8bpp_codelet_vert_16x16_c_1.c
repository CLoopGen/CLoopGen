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
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    uint32_t tmp_a = p4a + 0x10101010;
    uint32_t tmp_b = p4b + 0x20202020;
    uint32_t tmp_c = p4c + 0x30303030;
    uint32_t tmp_d = p4d + 0x40404040;
    (((av_alias32 *)(dst + 0))->u32 = tmp_a);
    (((av_alias32 *)(dst + 4))->u32 = tmp_b);
    (((av_alias32 *)(dst + 8))->u32 = tmp_c);
    (((av_alias32 *)(dst + 12))->u32 = tmp_d);
    dst += stride;
    
    // Second write pass with modified values
    tmp_a += 0x01010101;
    tmp_b += 0x02020202;
    tmp_c += 0x03030303;
    tmp_d += 0x04040404;
    (((av_alias32 *)(dst + 0))->u32 = tmp_a);
    (((av_alias32 *)(dst + 4))->u32 = tmp_b);
    (((av_alias32 *)(dst + 8))->u32 = tmp_c);
    (((av_alias32 *)(dst + 12))->u32 = tmp_d);
    dst += stride;
}
}
