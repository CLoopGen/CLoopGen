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
    uint64_t local_dc0, local_dc1;
    for (i = 0; i < 16; i += 2) {
        // Remove redundant recomputation and unroll partially to break loop-carried dependencies
        local_dc0 = dc0splat;
        local_dc1 = dc1splat;

        // First iteration of unrolled pair
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = (local_dc0));
        (((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = (local_dc1));

        // Second iteration, if within bounds
        if (i + 1 < 16) {
            (((av_alias64 *)(((uint64_t *)(src + (i + 1) * stride)) + 0))->u64 = (local_dc0));
            (((av_alias64 *)(((uint64_t *)(src + (i + 1) * stride)) + 1))->u64 = (local_dc1));
        }
    }
}
