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

extern int y;
extern uint8_t *src;
extern int stride;
extern uint32_t a;
extern uint32_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reorganizing data layout access
    uint32_t *base = (uint32_t *)(src + stride);
    for (y = 1; y < 8; y++) {
        av_alias32 *current = (av_alias32*)(base + (y - 1) * (stride / sizeof(uint32_t)) * 2);
        current[0].u32 = a;
        current[1].u32 = b;
    }
}
