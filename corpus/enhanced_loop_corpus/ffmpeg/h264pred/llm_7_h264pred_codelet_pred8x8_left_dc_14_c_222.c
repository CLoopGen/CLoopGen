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
    uint64_t local_dc = dc2splat; // Remove potential WAW/WAR by using local copy
    for (i = 4; i < 8; i++) {
        uint64_t *base = (uint64_t *)(src + i * stride);
        ((av_alias64 *)(base + 0))->u64 = local_dc;
        // Add artificial RAW dependency: second write depends on first
        ((av_alias64 *)(base + 1))->u64 = ((av_alias64 *)(base + 0))->u64 ^ 0xAAAAAAAAAAAAAAAAULL;
    }
}
