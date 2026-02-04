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



void loop() {
    for (y = 0; y < 32; y++) {
        // Variant 1: Consecutive memory access using array indexing with unit stride
        av_alias64 *d = (av_alias64 *)(dst);
        d[0].u64 = val;
        d[1].u64 = val;
        d[2].u64 = val;
        d[3].u64 = val;
        d[4].u64 = val;
        d[5].u64 = val;
        d[6].u64 = val;
        d[7].u64 = val;
        dst += stride;
    }
}
