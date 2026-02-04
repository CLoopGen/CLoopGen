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
extern uint64_t p4a;
extern uint64_t p4b;
extern uint64_t p4c;
extern uint64_t p4d;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with transposed write pattern (interleaved stores)
    uint16_t *d = dst;
    for (y = 0; y < 16; y++) {
        ((av_alias64 *)(d + 0))->u64 = p4a;
        ((av_alias64 *)(d + 8))->u64 = p4b;  // Increased stride between writes
        ((av_alias64 *)(d + 16))->u64 = p4c;
        ((av_alias64 *)(d + 24))->u64 = p4d;
        d += stride;
    }
}
