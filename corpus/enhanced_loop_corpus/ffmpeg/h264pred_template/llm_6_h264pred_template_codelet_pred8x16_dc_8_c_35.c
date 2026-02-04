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
extern uint32_t dc6splat;
extern uint32_t dc7splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_dc6 = dc6splat;
    uint32_t temp_dc7 = dc7splat;
    for (i = 12; i < 16; i++) {
        av_alias32 *target0 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 0);
        av_alias32 *target1 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 1);
        target0->u32 = temp_dc6;
        target1->u32 = temp_dc7;
        temp_dc6 ^= 0x11111111; // Introduce WAW dependency across iterations via temp_dc6
        temp_dc7 ^= 0x22222222; // Loop-carried dependency: each iteration modifies values used in next
    }
}
