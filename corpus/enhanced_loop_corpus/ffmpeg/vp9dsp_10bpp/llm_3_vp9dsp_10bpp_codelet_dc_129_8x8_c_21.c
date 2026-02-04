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
    // Variant 2: Indirect memory access via index array
    // Use an explicit index array to simulate non-contiguous, irregular destination layout
    // This models scenarios like scattered writes or frame buffer tiling
    static const int offsets[] = {0, 8, 16, 24, 32, 40, 48, 56}; // Simulated custom layout
    uint16_t *base = dst;
    for (y = 0; y < 8; y++) {
        uint16_t *row = base + offsets[y];
        ((av_alias64 *)(row + 0))->u64 = val;
        ((av_alias64 *)(row + 4))->u64 = val;
    }
}
