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
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, write to consecutive 16-bit elements in a block
    uint16_t *base = src;
    for (i = 0; i < 8; i++) {
        (((av_alias64 *)(((uint64_t *)(base + i)) + 0))->u64 = (dc0splat));
    }
}
