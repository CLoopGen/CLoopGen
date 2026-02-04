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
    // Variant 1: Consecutive memory access (unrolled and restructured for linear write pattern)
    uint64_t *base_ptr = (uint64_t *)(src + 8 * stride);
    av_alias64 *alias_ptr = (av_alias64 *)base_ptr;
    for (i = 0; i < 4; i += 2) {
        alias_ptr[i + 0].u64 = dc4splat;
        alias_ptr[i + 1].u64 = dc5splat;
    }
}
