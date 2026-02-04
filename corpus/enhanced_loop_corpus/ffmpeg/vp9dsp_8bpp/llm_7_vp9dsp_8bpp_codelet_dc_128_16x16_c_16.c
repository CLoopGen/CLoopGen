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
    uint32_t local_val[4];
    for (y = 0; y < 16; y++) {
        // Break loop-carried dependency by computing values independently each iteration
        local_val[0] = val + y;
        local_val[1] = val + y + 1;
        local_val[2] = val + y + 2;
        local_val[3] = val + y + 3;

        ((av_alias32 *)(dst + 0))->u32 = local_val[0];
        ((av_alias32 *)(dst + 4))->u32 = local_val[1];
        ((av_alias32 *)(dst + 8))->u32 = local_val[2];
        ((av_alias32 *)(dst + 12))->u32 = local_val[3];

        dst += stride;
    }
}
