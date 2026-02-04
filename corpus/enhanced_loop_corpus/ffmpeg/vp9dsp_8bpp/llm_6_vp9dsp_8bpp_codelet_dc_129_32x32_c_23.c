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
    uint32_t temp_val = val;
    for (y = 0; y < 32; y++) {
        ((av_alias32 *)(dst + 0))->u32 = temp_val;
        ((av_alias32 *)(dst + 4))->u32 = temp_val;
        ((av_alias32 *)(dst + 8))->u32 = temp_val;
        ((av_alias32 *)(dst + 12))->u32 = temp_val;
        ((av_alias32 *)(dst + 16))->u32 = temp_val;
        ((av_alias32 *)(dst + 20))->u32 = temp_val;
        ((av_alias32 *)(dst + 24))->u32 = temp_val;
        ((av_alias32 *)(dst + 28))->u32 = temp_val;
        temp_val ^= 0x11111111; // Introduce WAW and RAW dependency on temp_val across iterations
        dst += stride;
    }
}
