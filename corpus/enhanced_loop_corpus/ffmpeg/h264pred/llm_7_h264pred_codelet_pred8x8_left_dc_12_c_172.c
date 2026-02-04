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
    uint64_t local_splat[4]; // Remove loop-carried dependency by precomputing values
    for (int j = 0; j < 4; j++) {
        local_splat[j] = dc2splat ^ (j << 32); // Independent computation, no RAW/WAR/WAW across iterations
    }
    for (i = 4; i < 8; i++) {
        int idx = i - 4;
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 0))->u64 = local_splat[idx];
        ((av_alias64 *)(((uint64_t *)(src + i * stride)) + 1))->u64 = local_splat[idx];
        // All writes are independent; no data dependencies between loop iterations
    }
}
