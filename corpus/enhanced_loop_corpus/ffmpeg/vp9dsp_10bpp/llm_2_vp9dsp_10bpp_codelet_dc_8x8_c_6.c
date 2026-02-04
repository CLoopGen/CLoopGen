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
extern uint16_t *dst;
extern uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access per row, write all 8x8 elements consecutively in a flat layout
    uint16_t *base_dst = dst;
    for (y = 0; y < 8; y++) {
        ((av_alias64 *)(base_dst + y * 8 + 0))->u64 = dc;
        ((av_alias64 *)(base_dst + y * 8 + 4))->u64 = dc;
    }
}
