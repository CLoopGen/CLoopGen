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
extern uint32_t dc0splat;
extern uint32_t dc1splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        uint32_t *base0 = (uint32_t *)(src + (i * 2 + 0) * stride);
        uint32_t *base1 = (uint32_t *)(src + (i * 2 + 1) * stride);
        
        ((av_alias32 *)&base0[0])->u32 = dc0splat ^ 0x11111111U;
        ((av_alias32 *)&base0[1])->u32 = dc1splat ^ 0x22222222U;
        ((av_alias32 *)&base1[0])->u32 = dc0splat ^ 0x33333333U;
        ((av_alias32 *)&base1[1])->u32 = dc1splat ^ 0x44444444U;
    }
}
