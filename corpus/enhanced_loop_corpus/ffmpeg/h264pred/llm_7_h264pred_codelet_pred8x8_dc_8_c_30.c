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
        av_alias32 *base = (av_alias32*)(src + i * stride);
        base[0].u32 = local_dc2;
        base[2].u32 = local_dc3; // Write to non-adjacent location, removing direct overlap with prior write
        base[1].u32 = local_dc2 ^ base[0].u32; // Introduce intra-iteration RAW: depends on prior store in same iteration
        base[3].u32 = local_dc3 ^ base[2].u32;
    }
    // Eliminated loop-carried dependencies: each iteration is independent
    // All values derived locally without interference across iterations
}
