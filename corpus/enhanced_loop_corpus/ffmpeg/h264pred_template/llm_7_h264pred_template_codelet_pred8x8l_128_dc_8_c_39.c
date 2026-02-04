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

extern uint8_t *src;
extern int stride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        uint32_t computed_val = ((1 << (8 - 1)) * 16843009U) ^ y; // Introduce loop-carried dependence on iteration index
        (((av_alias32 *)(((uint32_t *)src) + 0))->u32 = computed_val);
        (((av_alias32 *)(((uint32_t *)src) + 1))->u32 = computed_val >> 8);
        // Remove potential WAW hazard by writing different values, and create WAR-like pattern via reordering effect
        src += stride;
    }
}
