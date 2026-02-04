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
extern uint64_t dc2splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc = dc2splat; // Remove potential aliasing effect by using local copy early
    for (i = 4; i < 8; i += 2) { // Unroll-like step to remove per-iteration dependencies
        uint64_t *base1 = (uint64_t *)(src + i * stride);
        uint64_t *base2 = (uint64_t *)(src + (i + 1) * stride);

        ((av_alias64 *)(base1 + 0))->u64 = local_dc;
        ((av_alias64 *)(base1 + 1))->u64 = local_dc;

        if (i + 1 < 8) { // Ensure safety within bounds
            ((av_alias64 *)(base2 + 0))->u64 = local_dc;
            ((av_alias64 *)(base2 + 1))->u64 = local_dc;
        }
    }
}
