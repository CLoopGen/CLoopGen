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
        // Variant 2: Strided access with increasing stride multiples (non-unit, widening pattern)
        ptrdiff_t s = stride * 2; // Use a derived striding factor
        (((av_alias64 *)(dst + 0 * s))->u64 = val);
        (((av_alias64 *)(dst + 1 * s))->u64 = val);
        (((av_alias64 *)(dst + 2 * s))->u64 = val);
        (((av_alias64 *)(dst + 3 * s))->u64 = val);
        (((av_alias64 *)(dst + 4 * s))->u64 = val);
        (((av_alias64 *)(dst + 5 * s))->u64 = val);
        (((av_alias64 *)(dst + 6 * s))->u64 = val);
        (((av_alias64 *)(dst + 7 * s))->u64 = val);
        dst += stride;
    }
}
