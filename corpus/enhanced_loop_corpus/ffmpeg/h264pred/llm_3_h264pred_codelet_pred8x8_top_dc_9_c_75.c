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
extern int i;
extern uint64_t dc0splat;
extern uint64_t dc1splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed indexing (accessing columns of a matrix-like structure)
    // Instead of iterating over rows with fixed stride, simulate column-wise traversal with larger effective stride
    ptrdiff_t large_stride = stride * 4; // Simulate accessing every 4th element in a larger grid
    for (i = 0; i < 4; i++) {
        uint64_t *target = (uint64_t *)(src + (4 + i) * large_stride);

        ((av_alias64*)(target + 0))->u64 = dc0splat;
        ((av_alias64*)(target + 1))->u64 = dc1splat;
    }
}
