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
    // Variant 2: Strided access with dynamic offset based on iteration
    // Use a strided access pattern where each write is spaced by a non-unit, variable step
    // Simulate a transposed or scattered store pattern using compile-time known offsets
    ptrdiff_t effective_stride = stride / sizeof(uint16_t);
    for (y = 0; y < 16; y++) {
        int base_offset = y * effective_stride;
        // Write to non-consecutive columns: 0, 8, 16, 24 — increasing stride in output
        (((av_alias64 *)(dst + base_offset +  0))->u64 = (val));
        (((av_alias64 *)(dst + base_offset +  8))->u64 = (val));
        (((av_alias64 *)(dst + base_offset + 16))->u64 = (val));
        (((av_alias64 *)(dst + base_offset + 24))->u64 = (val));
    }
}
