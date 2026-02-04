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
    const int unroll_factor = 2;
    for (y = 0; y < 8; y++) {
        for (int x = 0; x < unroll_factor; x++) {
            int offset = x * 16;
            (((av_alias32 *)(dst + offset + 0))->u32 = (val));
            (((av_alias32 *)(dst + offset + 4))->u32 = (val));
            (((av_alias32 *)(dst + offset + 8))->u32 = (val));
            (((av_alias32 *)(dst + offset + 12))->u32 = (val));
        }
        dst += stride;
    }
}
