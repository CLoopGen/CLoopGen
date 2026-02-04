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
extern uint32_t dc0splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access across rows, process 8 consecutive uint32_t values in a single block
    uint32_t *base = (uint32_t*)src;
    for (i = 0; i < 8; i++) {
        (((av_alias32 *)(base + i))->u32 = (dc0splat));
    }
}
