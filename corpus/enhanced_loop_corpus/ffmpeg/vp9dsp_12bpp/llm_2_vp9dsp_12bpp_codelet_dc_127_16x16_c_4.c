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
    // Instead of writing four separate unaligned 64-bit values with stride,
    // write 8 consecutive uint64_t-sized chunks (interpreted as 16x uint16_t) in row-major order
    uint64_t *dst64 = (uint64_t*)dst;
    for (y = 0; y < 16; y++) {
        for (int x = 0; x < 8; x++) {
            ((av_alias64*)(dst64 + x))->u64 = val;
        }
        dst64 += (stride / sizeof(uint64_t));
    }
}
