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

extern uint8_t *dst;
extern  uint64_t pix;
extern int32_t n;
extern int32_t row_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every other element first, then the odd-offset elements (cache-friendly striding pattern)
    int32_t i;
    uint8_t *base = dst;

    // First pass: even indices (0, 2, 4, ...) with stride of 2*row_offset
    for (i = 0; i < n; i += 2) {
        uint8_t *current = base + i * row_offset;
        (((av_alias64 *)(current))->u64 = (pix));
    }

    // Second pass: odd indices (1, 3, 5, ...)
    for (i = 1; i < n; i += 2) {
        uint8_t *current = base + i * row_offset;
        (((av_alias64 *)(current))->u64 = (pix));
    }

    // Update global state
    dst = base + n * row_offset;
    n = 0;
}
