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
    uint32_t local_splat[4];
    // Break loop-carried dependency by precomputing values
    local_splat[0] = dcsplat;
    local_splat[1] = dcsplat;
    local_splat[2] = dcsplat;
    local_splat[3] = dcsplat;

    for (i = 0; i < 16; i++) {
        (((av_alias32 *)(src + 0))->u32 = (local_splat[0]));
        (((av_alias32 *)(src + 4))->u32 = (local_splat[1]));
        (((av_alias32 *)(src + 8))->u32 = (local_splat[2]));
        (((av_alias32 *)(src + 12))->u32 = (local_splat[3]));
        // Remove any modification of shared state — pure write with no inter-iteration dependency
        src += stride;
    }
}
