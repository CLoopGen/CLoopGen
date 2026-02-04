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
    // Variant 2: Strided memory access pattern with non-unit stride in inner dimension
    // Access every 2nd element in a strided manner, effectively writing to alternating positions
    // This increases spatial sparsity and changes cache access behavior
    uint16_t *d = dst;
    for (y = 0; y < 16; y++) {
        ((av_alias64 *)(d + 0))->u64 = val;     // Original aligned 64-bit store
        ((av_alias64 *)(d + 8))->u64 = val;     // Store at offset +8 (skipping 4 uint16s)
        ((av_alias64 *)(d + 16))->u64 = val;    // Further strided
        ((av_alias64 *)(d + 24))->u64 = val;
        d += stride;
    }
}
