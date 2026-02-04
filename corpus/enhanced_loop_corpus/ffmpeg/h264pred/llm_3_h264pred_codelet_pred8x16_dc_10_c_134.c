#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern ptrdiff_t stride;
extern int i;
extern uint64_t dc4splat;
extern uint64_t dc5splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // Instead of direct i * stride, we use a lookup table for row offsets
    static const ptrdiff_t indices[] = {8, 9, 10, 11}; // Original loop indices
    for (i = 0; i < 4; i++) {
        uint16_t* target_row = src + indices[i] * stride;
        ((av_alias64*)((uint64_t*)target_row + 0))->u64 = dc4splat;
        ((av_alias64*)((uint64_t*)target_row + 1))->u64 = dc5splat;
    }
}
