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
for (y = 0; y < 8; y++) {
    uint32_t temp_dc = dc + y * 4;
    for (int x = 0; x < 16; x += 16) {
        (((av_alias32 *)(dst + x + 0))->u32 = (temp_dc));
        (((av_alias32 *)(dst + x + 4))->u32 = (temp_dc));
        (((av_alias32 *)(dst + x + 8))->u32 = (temp_dc));
        (((av_alias32 *)(dst + x + 12))->u32 = (temp_dc));
    }
    dst += stride;
}
}
