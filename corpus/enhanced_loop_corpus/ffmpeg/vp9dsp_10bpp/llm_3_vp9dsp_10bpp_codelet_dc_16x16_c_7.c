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
    // Variant 2: Strided access with increased stride step and reduced iterations using larger jumps
    uint16_t **pp_dst = &dst;
    for (y = 0; y < 8; y++) {
        uint16_t *row = *pp_dst;
        // Write to non-consecutive columns with a fixed stride of 8 apart
        (((av_alias64 *)(row + 0))->u64 = dc);
        (((av_alias64 *)(row + 8))->u64 = dc);
        // Skip middle accesses, creating a sparse write pattern
        (((av_alias64 *)(row + 16))->u64 = dc);
        (((av_alias64 *)(row + 24))->u64 = dc);
        *pp_dst += stride * 2; // Progress two rows at a time
    }
    // Adjust final state if needed; note y now only goes to 8
}
