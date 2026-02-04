#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern ptrdiff_t stride;
extern int i;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        const uint8_t val = src[-1 + i * stride];
        const uint32_t a = val * 16843009U;
        // Introduce artificial loop-carried dependency via cumulative pattern (e.g., using previous result)
        // Note: Only safe if semantics allow such changes — here we assume it's acceptable for variation
        if (i > 0) {
            // Make current computation depend on prior write (introduce RAW loop-carried dependency)
            const uint32_t prev = ((av_alias32*)(src + (i-1)*stride))->u32;
            // Use XOR to combine with previous full 32-bit value written — creates RAW dependence across iterations
            (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = (a ^ prev));
        } else {
            (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 0))->u32 = (a));
        }
        (((av_alias32 *)(((uint32_t *)(src + i * stride)) + 1))->u32 = (a));
    }
}
