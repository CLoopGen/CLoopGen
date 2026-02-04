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

extern uint16_t *src;
extern int stride;
extern  uint64_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration and alternating write pattern
    uint64_t *base = (uint64_t *)src;
    for (y = 7; y >= 0; y--) {
        int effective_idx = y ^ 1; // Introduce non-linear index mutation
        uint64_t *row = base + effective_idx * stride;
        ((av_alias64 *)(row + 0))->u64 = dc;
        ((av_alias64 *)(row + 1))->u64 = dc;
    }
}
