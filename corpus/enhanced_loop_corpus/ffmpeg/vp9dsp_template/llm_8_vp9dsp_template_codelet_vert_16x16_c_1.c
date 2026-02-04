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
    (((av_alias32 *)(dst + 0))->u32 = (p4a ^ 0x12345678));
    (((av_alias32 *)(dst + 4))->u32 = (p4b ^ 0x23456789));
    (((av_alias32 *)(dst + 8))->u32 = (p4c ^ 0x3456789A));
    (((av_alias32 *)(dst + 12))->u32 = (p4d ^ 0x456789AB));
    dst += stride * 2;
}
}
