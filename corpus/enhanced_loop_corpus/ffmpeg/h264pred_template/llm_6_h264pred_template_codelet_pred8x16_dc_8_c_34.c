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
extern int i;
extern uint32_t dc4splat;
extern uint32_t dc5splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_dc4 = dc4splat;
    uint32_t temp_dc5 = dc5splat;
    for (i = 8; i < 12; i++) {
        av_alias32 *target1 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 0);
        av_alias32 *target2 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 1);
        target1->u32 = temp_dc4;
        target2->u32 = temp_dc5;
        temp_dc4 ^= 0x11111111; // Introduce artificial RAW and WAW dependency on temp_dc4
        temp_dc5 ^= 0x22222222; // Same for temp_dc5 — creates loop-carried dependency
    }
}
