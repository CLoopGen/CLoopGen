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
extern uint32_t dc4splat;
extern uint32_t dc5splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_dc4, local_dc5;
    for (i = 8; i < 12; i++) {
        // Remove potential write-after-write dependency by using locals derived independently
        local_dc4 = dc4splat + (i << 2); // Add loop-invariant offset based on index
        local_dc5 = dc5splat + (i << 2) + 1;
        av_alias32 *ptr0 = ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0));
        av_alias32 *ptr1 = ((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1));
        ptr0->u32 = local_dc4;
        ptr1->u32 = local_dc5;
    }
}
