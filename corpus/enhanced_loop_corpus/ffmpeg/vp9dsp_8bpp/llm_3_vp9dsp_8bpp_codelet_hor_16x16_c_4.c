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
for (y = 0; y < 16; y += 2) {
    uint32_t p4_curr = ((left[15 - y]) * 16843009U);
    uint32_t p4_next = ((left[15 - (y + 1)]) * 16843009U);
    (((av_alias32 *)(dst + 0))->u32 = p4_curr);
    (((av_alias32 *)(dst + 4))->u32 = p4_curr);
    (((av_alias32 *)(dst + 8))->u32 = p4_curr);
    (((av_alias32 *)(dst + 12))->u32 = p4_curr);
    if (y + 1 < 16) {
        (((av_alias32 *)(dst + stride + 0))->u32 = p4_next);
        (((av_alias32 *)(dst + stride + 4))->u32 = p4_next);
        (((av_alias32 *)(dst + stride + 8))->u32 = p4_next);
        (((av_alias32 *)(dst + stride + 12))->u32 = p4_next);
    }
    dst += 2 * stride;
}
}
