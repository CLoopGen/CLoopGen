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
extern uint64_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access across iterations, write 16 consecutive uint16_t elements per row (32 bytes)
    // This improves spatial locality and may benefit from cache line utilization.
    uint16_t *base = dst;
    for (y = 0; y < 8; y++) {
        av_alias64 *ptr = (av_alias64 *)(base);
        ptr[0].u64 = val;
        ptr[1].u64 = val;
        ptr[2].u64 = val;
        ptr[3].u64 = val; // Write 4x u64 = 32 bytes = 16 uint16_t elements
        base += 16; // Move to next row with fixed row length
    }
}
