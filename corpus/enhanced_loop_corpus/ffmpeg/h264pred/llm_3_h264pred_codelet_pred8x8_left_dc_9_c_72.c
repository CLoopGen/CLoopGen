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
    // Variant 2: Strided access with increased stride step (every other element with doubled stride offset)
    for (i = 4; i < 8; i += 2) {
        uint64_t *p1 = (uint64_t*)(src + i * stride);
        uint64_t *p2 = (uint64_t*)(src + (i + 1) * stride);
        ((av_alias64*)(p1 + 0))->u64 = dc2splat;
        ((av_alias64*)(p1 + 1))->u64 = dc2splat;
        ((av_alias64*)(p2 + 0))->u64 = dc2splat;
        ((av_alias64*)(p2 + 1))->u64 = dc2splat;
    }
}
