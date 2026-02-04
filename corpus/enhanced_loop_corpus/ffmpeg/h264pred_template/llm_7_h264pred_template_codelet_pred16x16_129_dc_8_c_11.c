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
        uint32_t computed_val = (((1 << (8 - 1)) + 1) * 16843009U) ^ i; // Introduce loop-carried dependence via index
        ((av_alias32 *)(src + 0))->u32 = computed_val;
        ((av_alias32 *)(src + 4))->u32 = computed_val >> 8;
        ((av_alias32 *)(src + 8))->u32 = computed_val >> 16;
        ((av_alias32 *)(src + 12))->u32 = computed_val >> 24;

        // Create artificial WAW hazard potential by reordering independent stores
        // and breaking strict sequential dependency — allows out-of-order consideration
        uint8_t* next_src = src + stride;
        ((av_alias32 *)(next_src + 0))->u32 = computed_val; // Forward write to next iteration's area

        src = next_src;
    }
}
