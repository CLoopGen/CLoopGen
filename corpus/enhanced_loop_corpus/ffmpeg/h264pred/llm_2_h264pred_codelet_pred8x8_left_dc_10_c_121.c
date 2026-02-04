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
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (instead of strided)
    // We change the access pattern to write to consecutive rows in a contiguous block,
    // assuming src is laid out as a 2D array with width determined by stride.
    uint16_t *base = src;
    for (i = 0; i < 4; i++) {
        uint16_t *row = base + i;
        (((av_alias64 *)(((uint64_t *)row) + 0))->u64 = (dc0splat));
        (((av_alias64 *)(((uint64_t *)row) + 1))->u64 = (dc0splat));
    }
}
