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
    for (i = 4; i < 8; i++) {
        uint32_t local_dc2 = dc2splat ^ (i << 16); // Remove loop-carried dependency, make data independent per iteration
        uint32_t local_dc3 = dc3splat ^ (i << 8);
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32) = local_dc2;
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32) = local_dc3;
        // No dependencies between iterations — fully parallelizable
    }
}
