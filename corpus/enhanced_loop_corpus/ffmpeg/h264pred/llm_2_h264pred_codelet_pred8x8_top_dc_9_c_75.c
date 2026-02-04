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
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unrolled and restructured for sequential writes)
    uint64_t *base0 = (uint64_t *)(src + 4 * stride);
    uint64_t *base1 = (uint64_t *)(src + 5 * stride);
    uint64_t *base2 = (uint64_t *)(src + 6 * stride);
    uint64_t *base3 = (uint64_t *)(src + 7 * stride);

    ((av_alias64*)(base0 + 0))->u64 = dc0splat;
    ((av_alias64*)(base0 + 1))->u64 = dc1splat;

    ((av_alias64*)(base1 + 0))->u64 = dc0splat;
    ((av_alias64*)(base1 + 1))->u64 = dc1splat;

    ((av_alias64*)(base2 + 0))->u64 = dc0splat;
    ((av_alias64*)(base2 + 1))->u64 = dc1splat;

    ((av_alias64*)(base3 + 0))->u64 = dc0splat;
    ((av_alias64*)(base3 + 1))->u64 = dc1splat;
}
