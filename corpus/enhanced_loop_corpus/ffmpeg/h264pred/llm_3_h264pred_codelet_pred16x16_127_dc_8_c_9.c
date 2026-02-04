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
    // Variant 2: Strided memory access — write to every other 32-bit location in a scattered pattern
    uint8_t *base_src = src;
    for (i = 0; i < 16; i++) {
        uint8_t *pos = base_src + i * (stride * 2); // Double stride for wider spacing
        ((av_alias32 *)(pos + 0))->u32 = ((((1 << (8 - 1)) - 1) * 16843009U));
        ((av_alias32 *)(pos + 8))->u32 = ((((1 << (8 - 1)) - 1) * 16843009U));
        // Skip intermediate locations, creating a sparse write pattern
        ((av_alias32 *)(pos + 24))->u32 = ((((1 << (8 - 1)) - 1) * 16843009U));
        ((av_alias32 *)(pos + 32))->u32 = ((((1 << (8 - 1)) - 1) * 16843009U));
    }
}
