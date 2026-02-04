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
extern uint16_t *src;
extern uint64_t dcsplat;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed write pattern using alternating offsets
    for (i = 0; i < 16; i++) {
        uint16_t *p = src + (i & 7) * 8; // Non-linear strided read based on lower 3 bits
        ((av_alias64 *)(p + 0 * stride / sizeof(uint16_t)))->u64 = dcsplat;
        ((av_alias64 *)(p + 1 * stride / sizeof(uint16_t)))->u64 = dcsplat;
        ((av_alias64 *)(p + 2 * stride / sizeof(uint16_t)))->u64 = dcsplat;
        ((av_alias64 *)(p + 3 * stride / sizeof(uint16_t)))->u64 = dcsplat;
    }
    src += stride; // Maintain compatibility with original pointer update expectation
}
