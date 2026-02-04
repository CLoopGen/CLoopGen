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
    // Variant 2: Strided access across columns — iterate over a fixed set of rows but with column-like offset pattern
    // Simulate accessing every 4th byte within the same row segment, creating a strided vertical pattern
    ptrdiff_t effective_stride = stride * 4; // Larger stride to skip multiple rows
    uint8_t *start = src + 8 * stride;
    for (i = 0; i < 4; i++) {
        uint32_t *target = (uint32_t *)(start + i * effective_stride);
        ((av_alias32 *)(target + 0))->u32 = dc4splat;
        ((av_alias32 *)(target + 1))->u32 = dc5splat;
    }
}
