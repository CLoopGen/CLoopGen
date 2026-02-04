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
extern uint8_t *src;
extern uint32_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_dc = dcsplat;
    for (i = 0; i < 16; i++) {
        temp_dc ^= i; // Introduce loop-carried dependency: each iteration modifies temp_dc based on index
        (((av_alias32 *)(src + 0))->u32 = (temp_dc));
        (((av_alias32 *)(src + 4))->u32 = (temp_dc));
        (((av_alias32 *)(src + 8))->u32 = (temp_dc));
        (((av_alias32 *)(src + 12))->u32 = (temp_dc));
        temp_dc = dcsplat; // Reset to original value (removes cumulative effect, but dependency still exists)
        src += stride;
    }
}
