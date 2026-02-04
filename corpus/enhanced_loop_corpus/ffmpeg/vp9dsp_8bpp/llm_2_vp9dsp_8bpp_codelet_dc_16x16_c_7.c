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
extern uint8_t *dst;
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with sequential 32-bit writes
    uint32_t *dst32 = (uint32_t *)dst;
    ptrdiff_t stride32 = stride / sizeof(uint32_t);
    for (y = 0; y < 16; y++) {
        dst32[0] = dc;
        dst32[1] = dc;
        dst32[2] = dc;
        dst32[3] = dc;
        dst32 += stride32;
    }
}
