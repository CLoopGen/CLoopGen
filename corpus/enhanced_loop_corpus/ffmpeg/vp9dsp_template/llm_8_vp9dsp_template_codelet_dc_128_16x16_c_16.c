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
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t val1 = val;
    uint32_t val2 = val ^ 0x80808080;
    for (y = 0; y < 32; y += 2) {
        (((av_alias32 *)(dst + 0))->u32 = (val1));
        (((av_alias32 *)(dst + 4))->u32 = (val2));
        (((av_alias32 *)(dst + 8))->u32 = (val1));
        (((av_alias32 *)(dst + 12))->u32 = (val2));
        dst += stride;
        if (y + 1 < 32) {
            (((av_alias32 *)(dst + 0))->u32 = (val2));
            (((av_alias32 *)(dst + 4))->u32 = (val1));
            (((av_alias32 *)(dst + 8))->u32 = (val2));
            (((av_alias32 *)(dst + 12))->u32 = (val1));
            dst += stride;
        }
    }
}
