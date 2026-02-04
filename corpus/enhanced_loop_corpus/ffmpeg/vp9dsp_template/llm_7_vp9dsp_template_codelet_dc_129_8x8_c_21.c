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
    uint32_t local_val[8]; // Remove loop-carried dependency by precomputing values
    for (int i = 0; i < 8; i++) {
        local_val[i] = val ^ (i << 2); // Independent computation, no RAW/WAR/WAW across iterations
    }
    for (y = 0; y < 8; y++) {
        (((av_alias32 *)(dst + 0))->u32 = local_val[y]);
        (((av_alias32 *)(dst + 4))->u32 = local_val[y]);
        dst += stride;
    }
}
