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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int factor = ((1 << (8 - 1)) - 1);
    const uint32_t base_val = factor * 16843009U;
    for (i = 0; i < 8; ++i) {
        // Unroll by a factor of 2 and reduce trip count
        ((av_alias32 *)(src + 0))->u32 = base_val;
        ((av_alias32 *)(src + 4))->u32 = base_val;
        ((av_alias32 *)(src + 8))->u32 = base_val;
        ((av_alias32 *)(src + 12))->u32 = base_val;

        src += stride;

        // Second iteration of unrolled loop body
        ((av_alias32 *)(src + 0))->u32 = base_val;
        ((av_alias32 *)(src + 4))->u32 = base_val;
        ((av_alias32 *)(src + 8))->u32 = base_val;
        ((av_alias32 *)(src + 12))->u32 = base_val;

        src += stride;
    }
}
