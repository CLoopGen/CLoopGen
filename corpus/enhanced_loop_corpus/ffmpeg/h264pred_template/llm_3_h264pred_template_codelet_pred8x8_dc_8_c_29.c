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
extern uint32_t dc0splat;
extern uint32_t dc1splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with step larger than one, simulating block-row or padded matrix access
    // Assume that each "logical" row is separated by a larger stride (e.g., cache line alignment)
    // We maintain the same operation but simulate non-unit stride amplification
    ptrdiff_t effective_stride = stride * 2; // Simulate padding: every other row is used

    for (i = 0; i < 4; i++) {
        uint8_t *row = src + i * effective_stride;
        ((av_alias32*)((uint32_t*)row + 0))->u32 = dc0splat;
        ((av_alias32*)((uint32_t*)row + 1))->u32 = dc1splat;
    }
}
