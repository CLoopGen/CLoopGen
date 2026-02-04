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
    uint32_t local_dc[2];
    for (y = 0; y < 8; y++) {
        // Break loop-carried dependency by using independent local copies
        local_dc[0] = dc ^ 0xAAAAAAAA;
        local_dc[1] = dc ^ 0x55555555;
        ((av_alias32 *)(dst + 0))->u32 = local_dc[0];
        ((av_alias32 *)(dst + 4))->u32 = local_dc[1];
        dst += stride;
        // No cross-iteration dependencies — fully parallelizable
    }
}
