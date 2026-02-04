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
    uint8_t *temp_dst = dst;
    for (y = 0; y < 32; y++) {
        av_alias32 val;
        val.u32 = dc;
        ((av_alias32 *)(temp_dst + 0 ))->u32 = val.u32;
        ((av_alias32 *)(temp_dst + 4 ))->u32 = val.u32;
        ((av_alias32 *)(temp_dst + 8 ))->u32 = val.u32;
        ((av_alias32 *)(temp_dst + 12))->u32 = val.u32;
        ((av_alias32 *)(temp_dst + 16))->u32 = val.u32;
        ((av_alias32 *)(temp_dst + 20))->u32 = val.u32;
        ((av_alias32 *)(temp_dst + 24))->u32 = val.u32;
        ((av_alias32 *)(temp_dst + 28))->u32 = val.u32;
        temp_dst += stride;
    }
}
