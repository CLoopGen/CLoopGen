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



void loop() {
    // Variant 2: Strided access with reversed iteration order
    // Access memory in reverse using the original stride but from a computed starting point.
    // This creates a backward traversal with same strided step, altering temporal access pattern.
    uint8_t *base = src + 15 * stride;  // Start from the last row
    for (i = 0; i < 16; i++) {
        uint8_t *current = base - i * stride;  // Reverse walk: decreasing by stride
        ((av_alias32 *)(current + 0))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        ((av_alias32 *)(current + 4))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        ((av_alias32 *)(current + 8))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        ((av_alias32 *)(current + 12))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
    }
}
