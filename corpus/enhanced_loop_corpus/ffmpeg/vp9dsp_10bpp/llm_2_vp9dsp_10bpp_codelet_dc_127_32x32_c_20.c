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
    // Instead of writing 8 unrolled stores with fixed offsets, write all 32 uint16_t elements consecutively
    // Each iteration writes 32 consecutive uint16_t values (covering 64 bytes), using direct indexing
    for (y = 0; y < 32; y++) {
        for (int x = 0; x < 32; x++) {
            dst[x] = (uint16_t)(val & 0xFFFF);
        }
        dst += stride;
    }
}
