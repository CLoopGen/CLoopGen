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
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 32; y++) {
    dst += stride;
    if (y < 16) {
        (((av_alias32 *)(dst - stride + 0))->u32 = (dc));
        (((av_alias32 *)(dst - stride + 4))->u32 = (dc));
        (((av_alias32 *)(dst - stride + 8))->u32 = (dc));
        (((av_alias32 *)(dst - stride + 12))->u32 = (dc));
    } else {
        (((av_alias32 *)(dst - stride + 16))->u32 = (dc));
        (((av_alias32 *)(dst - stride + 20))->u32 = (dc));
        (((av_alias32 *)(dst - stride + 24))->u32 = (dc));
        (((av_alias32 *)(dst - stride + 28))->u32 = (dc));
    }
}
}
