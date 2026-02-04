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
extern uint64_t dc6splat;
extern uint64_t dc7splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unrolled and rewritten for sequential layout)
    uint64_t *base_ptr = (uint64_t *)(src + 12 * stride);
    av_alias64 *alias_ptr = (av_alias64 *)base_ptr;
    alias_ptr[0].u64 = dc6splat;
    alias_ptr[1].u64 = dc7splat;
    alias_ptr[2].u64 = dc6splat;
    alias_ptr[3].u64 = dc7splat;
    alias_ptr[4].u64 = dc6splat;
    alias_ptr[5].u64 = dc7splat;
    alias_ptr[6].u64 = dc6splat;
    alias_ptr[7].u64 = dc7splat;
}
