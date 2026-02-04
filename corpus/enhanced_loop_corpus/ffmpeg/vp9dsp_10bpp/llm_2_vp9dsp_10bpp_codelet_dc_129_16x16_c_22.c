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
    // Instead of strided writes every 4 elements, write 16 consecutive uint16_t values
    // by treating the destination as a flat array and using byte-level offset control.
    uint8_t *dst8 = (uint8_t *)dst;
    for (y = 0; y < 16; y++) {
        ((av_alias64 *)(dst8 + 0))->u64 = val;
        ((av_alias64 *)(dst8 + 8))->u64 = val;
        dst8 += 16; // Move to next row with effective width of 8 uint16_t (16 bytes)
    }
}
