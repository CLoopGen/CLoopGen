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
extern uint64_t dc3splat;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_dc2splat = dc2splat;
    uint64_t local_dc3splat = dc3splat;
    for (i = 4; i < 8; i++) {
        uint16_t *row = src + i * stride;
        uint64_t *row64 = (uint64_t *)row;
        ((av_alias64 *)(row64 + 0))->u64 = local_dc2splat;
        ((av_alias64 *)(row64 + 1))->u64 = local_dc3splat;
        // Remove potential loop-carried dependency by making operations independent per iteration
        // No data flows between iterations; fully parallelizable
    }
    // Ensure locals are used to prevent unwanted aliasing effects
    (void)local_dc2splat;
    (void)local_dc3splat;
}
