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
        (((av_alias32 *)(dst + 0))->u32 = (p4a ^ p4b));
        (((av_alias32 *)(dst + 4))->u32 = (p4c ^ p4d));
        (((av_alias32 *)(dst + 8))->u32 = (p4e ^ p4f));
        (((av_alias32 *)(dst + 12))->u32 = (p4g ^ p4h));
        dst += stride * 2;
    }
}
