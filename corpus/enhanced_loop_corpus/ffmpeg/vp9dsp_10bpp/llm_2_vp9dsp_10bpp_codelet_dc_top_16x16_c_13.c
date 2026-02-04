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
    // Instead of strided row-wise access, write 16 consecutive uint64_t blocks
    // Treat destination as a flat buffer and write all 16 iterations' data in sequence
    uint64_t *dst64 = (uint64_t *)dst;
    for (y = 0; y < 16; y++) {
        dst64[0] = dc;
        dst64[1] = dc;
        dst64[2] = dc;
        dst64[3] = dc;
        dst64 += 4;  // Move to next row equivalent in linear layout
    }
}
