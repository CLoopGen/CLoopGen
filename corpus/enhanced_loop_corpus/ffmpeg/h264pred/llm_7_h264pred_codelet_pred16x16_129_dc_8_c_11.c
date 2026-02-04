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
    const uint32_t base_val = (((1 << (8 - 1)) + 1) * 16843009U);
    uint32_t scratch[4];
    // Remove direct memory writes and introduce local data reuse
    for (i = 0; i < 16; i++) {
        // Compute values in local storage first (introducing WAR-like pattern via reuse)
        scratch[0] = base_val ^ (i * 257U);     // Use loop index to diversify
        scratch[1] = base_val ^ (i * 513U);
        scratch[2] = base_val ^ (i * 769U);
        scratch[3] = base_val ^ (i * 1025U);

        // Now write back with no inter-element dependencies (eliminate WAW/RAR)
        ((av_alias32 *)(src + 0))->u32 = scratch[0];
        ((av_alias32 *)(src + 4))->u32 = scratch[1];
        ((av_alias32 *)(src + 8))->u32 = scratch[2];
        ((av_alias32 *)(src + 12))->u32 = scratch[3];

        src += stride;
        // No loop-carried data dependency — fully parallelizable across iterations
    }
}
