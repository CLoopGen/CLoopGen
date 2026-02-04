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
    // Variant 2: Strided access with alternating offset pattern (every other 64-bit element)
    uint64_t *src64 = (uint64_t *)src;
    int base_stride = stride / sizeof(uint64_t);
    for (y = 0; y < 8; y++) {
        int effective_idx = (y * base_stride); // Linear progression with stride
        ((av_alias64 *)(src64 + effective_idx + 0))->u64 = dc;
        ((av_alias64 *)(src64 + effective_idx + 2))->u64 = dc; // Increased stride between writes
    }
}
