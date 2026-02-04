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
    // Instead of writing four aligned 64-bit values with fixed offsets,
    // write eight consecutive 16-bit elements using a single linear pointer progression.
    uint16_t *d = dst;
    for (y = 0; y < 16; y++) {
        for (int x = 0; x < 8; x++) {
            d[x] = (uint16_t)(val >> (x * 8)); // Distribute val bytes across 8 uint16s (conceptual expansion)
        }
        d += stride;
    }
}
