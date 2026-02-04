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
    // Instead of updating dst by stride each iteration, write 8 consecutive blocks of 8 uint64_t-sized chunks (64 bytes)
    // Each row is now written entirely in one go with unit stride, improving spatial locality.
    uint16_t *base = dst;
    for (y = 0; y < 32; y++) {
        uint16_t *row = base + y * (stride / sizeof(uint16_t));
        for (int x = 0; x < 32; x += 4) {  // 32 elements = 16 av_alias64 writes (each covers 4x uint16_t)
            ((av_alias64 *)(row + x + 0))->u64 = val;
            ((av_alias64 *)(row + x + 4))->u64 = val;
            ((av_alias64 *)(row + x + 8))->u64 = val;
            ((av_alias64 *)(row + x + 12))->u64 = val;
        }
    }
}
