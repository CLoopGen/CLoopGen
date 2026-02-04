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
extern uint32_t dc2splat;
extern uint32_t dc3splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_dc2 = dc2splat;
    uint32_t local_dc3 = dc3splat;
    for (i = 4; i < 8; i++) {
        // Reorder memory stores to remove potential WAW hazard and change access pattern
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = local_dc3);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = local_dc2);
        // Eliminate all loop-carried dependencies — each iteration is now fully independent
    }
    // Use local copies to break any artificial dependencies; no modification of shared state across iterations
}
