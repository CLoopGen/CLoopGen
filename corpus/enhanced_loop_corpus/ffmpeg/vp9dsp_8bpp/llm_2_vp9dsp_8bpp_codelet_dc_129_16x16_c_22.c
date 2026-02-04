#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern uint8_t *dst;
extern uint32_t val;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of writing four separate 32-bit values with fixed offsets,
    // write them consecutively in a single row, then advance by stride.
    uint32_t *d = (uint32_t *)dst;
    for (y = 0; y < 16; y++) {
        d[0] = val;
        d[1] = val;
        d[2] = val;
        d[3] = val;
        d = (uint32_t *)((uint8_t *)d + stride);
    }
}
