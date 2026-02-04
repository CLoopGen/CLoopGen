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
    // Variant 2: Strided access with increased stride step (every other element in larger steps)
    ptrdiff_t large_stride = stride * 2; // Effectively skip one block per iteration
    for (i = 4; i < 8; i++) {
        uint64_t *row = (uint64_t *)(src + i * large_stride);
        ((av_alias64 *)(row + 0))->u64 = dc2splat;
        ((av_alias64 *)(row + 2))->u64 = dc2splat; // Skip one 64-bit unit, store at next
    }
}
