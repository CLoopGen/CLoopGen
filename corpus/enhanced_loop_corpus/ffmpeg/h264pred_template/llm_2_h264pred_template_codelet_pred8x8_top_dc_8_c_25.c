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
    // Variant 1: Consecutive memory access by reorganizing data layout assumption
    // Instead of strided access, we assume a transposed layout where consecutive rows are stored adjacently
    uint8_t *base = src + 4 * stride;
    for (i = 0; i < 4; i++) {
        av_alias32 *target0 = (av_alias32*)(base + i * sizeof(uint32_t));
        av_alias32 *target1 = (av_alias32*)(base + i * sizeof(uint32_t) + 4);
        target0->u32 = dc0splat;
        target1->u32 = dc1splat;
        base += stride - 8; // Adjust base to simulate next row after two writes
    }
}
