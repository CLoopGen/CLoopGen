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
    // Variant 1: Consecutive memory access by flattening the stride into a linear index
    // Instead of strided access (i * stride), we use consecutive indices assuming stride = 1
    // This variant assumes that src is now densely packed and we access elements in order
    ptrdiff_t base_index = 8 * stride; // Precompute starting offset
    for (i = 0; i < 4; i++) {
        uint16_t* row = src + base_index + i * stride;
        ((av_alias64*)((uint64_t*)row + 0))->u64 = dc4splat;
        ((av_alias64*)((uint64_t*)row + 1))->u64 = dc5splat;
    }
}
