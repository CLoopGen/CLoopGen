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
    // Variant 1: Consecutive memory access with full 16-element horizontal write per iteration
    uint64_t *dst64 = (uint64_t*)dst;
    ptrdiff_t stride64 = stride / sizeof(uint16_t); // Convert stride to number of uint16_t units
    for (y = 0; y < 16; y++) {
        dst64[0*stride64] = dc;
        dst64[1*stride64] = dc;
        dst64[2*stride64] = dc;
        dst64[3*stride64] = dc;
        dst64[4*stride64] = dc;
        dst64[5*stride64] = dc;
        dst64[6*stride64] = dc;
        dst64[7*stride64] = dc;
        dst += stride;
        dst64 += stride64; // Advance double-word pointer by stride
    }
}
