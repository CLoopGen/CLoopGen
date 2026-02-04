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
extern uint32_t dc2splat;
extern uint32_t dc3splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_dc2 = dc2splat;
    uint32_t temp_dc3 = dc3splat;
    for (i = 4; i < 8; i++) {
        av_alias32 *pos0 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 0);
        av_alias32 *pos1 = (av_alias32 *)(((uint32_t *)(src + i * stride)) + 1);
        pos0->u32 = temp_dc2;
        pos1->u32 = temp_dc3;
        temp_dc2 ^= 0x11111111; // Introduce WAW and RAW dependency across iterations
        temp_dc3 ^= 0x22222222;
    }
}
