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
    // Variant 2: Strided but transposed access - simulate column-wise traversal
    // with fixed offset jumps across iterations to increase cache line variation
    uint16_t *base = dst;
    for (y = 0; y < 8; y++) {
        // Access two non-adjacent locations with stride, but now with alternating banks
        size_t index1 = (y * stride / sizeof(uint16_t)) + 0;
        size_t index2 = (y * stride / sizeof(uint16_t)) + 4;
        ((av_alias64 *)(base + index1))->u64 = val;
        ((av_alias64 *)(base + index2))->u64 = val;
    }
}
