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
    uint64_t local_dc0 = dc0splat;
    uint64_t local_dc1 = dc1splat;
    uint16_t *base_src = src;
    for (i = 0; i < 4; i++) {
        uint16_t *row = base_src + i * stride;
        // Remove potential aliasing concerns by reordering independent stores
        ((av_alias64 *)(((uint64_t *)row) + 1))->u64 = local_dc1;
        ((av_alias64 *)(((uint64_t *)row) + 0))->u64 = local_dc0;
        // Eliminate loop-carried dependency entirely — all iterations are now independent
    }
}
