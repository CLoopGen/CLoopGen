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
    for (y = 0; y < 16; y++) {
        temp_val ^= y; // Introduce loop-carried dependency: each iteration modifies temp_val based on previous iteration
        (((av_alias32 *)(dst + 0))->u32 = (temp_val));
        (((av_alias32 *)(dst + 4))->u32 = (temp_val));
        (((av_alias32 *)(dst + 8))->u32 = (temp_val));
        (((av_alias32 *)(dst + 12))->u32 = (temp_val));
        dst += stride;
        temp_val = val; // Reset to original val at end of iteration (WAW dependency eliminated in next iteration)
    }
}
