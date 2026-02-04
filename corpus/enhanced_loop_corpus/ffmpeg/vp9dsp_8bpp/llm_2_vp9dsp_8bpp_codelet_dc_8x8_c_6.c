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
    // Variant 1: Consecutive memory access - write 8 consecutive 32-bit values in a row
    // Instead of strided access across rows, we write all data consecutively in one line
    uint32_t *d = (uint32_t *)dst;
    for (y = 0; y < 8; y++) {
        d[0] = dc;
        d[1] = dc;
        d += 2; // Move to next two 32-bit slots consecutively
    }
}
