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
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access across iterations, write to consecutive 16-byte aligned blocks in a single stretch.
    // This removes stride dependency and accesses memory sequentially for better cache locality.
    uint8_t *base = src;
    for (i = 0; i < 16; i++) {
        uint8_t *dst = base + i * 16;  // Sequential 16-byte blocks
        ((av_alias32 *)(dst + 0))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        ((av_alias32 *)(dst + 4))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        ((av_alias32 *)(dst + 8))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
        ((av_alias32 *)(dst + 12))->u32 = ((((1 << (8 - 1)) + 1) * 16843009U));
    }
}
